//============================================================================
// Name        : main.cc
// Author      : confalonieri
// Version     :
// // Copyright (C) 2009-2010 Roberto Confalonieri
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
// http://www.gnu.org/copyleft/gpl.html
//
// confalonieri@lsi.upc.edu
//
// Description : A possibilistic solver for LPPODs
//============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <dlfcn.h>


using namespace std;

#include "preprocLPPODparse.h"
#include "computeLPPOD.h"
#include "utils.h"
#include "parsing.h"
#include "lppodprogram.h"
#include "lpodmodel.h"
#include "lppodreduction.h"
#include "lppodtransformations.h"
#include "possprefrelation.h"

/*
 *
 * @inputs: an LPPOD P
 * @output: a set of possibilistic answer sets
 * algorithm:
 * 1. compute P* (parsing the possibilistic values)
 * 2. compute answer sets of P* (call psmodels)
 * 3. reduce P based on each of the M* found (apply the possibilistic reductions)
 * 4. compute possibilistic answer sets (call possmodels)
 *
 */


int
main(int argc, char* argv[]) {
	//int main() {
	int models = 1;
	char *fname = 0;
	char *program_name;
	char *programName2transform;
	char* lparseOption;
	
	list <LpodModel> *modelList = new list<LpodModel>();

	for (int i = 1; i < argc; i++) {
		/*if (isdigit(*argv[i])) {
			models = strtol(argv[i], 0, 10);
		} else {*/
		if (i==1)
			fname = argv[i];
		if (i==2) 
			lparseOption = argv[i];
	}
	//fname = "lppod/diagnosis.lppod";
	if (!fname) {
		cerr << "usage: posPsmodels INPUT_FILE lparse-option" << endl;
		exit(1);
	}
	if (!lparseOption) {
		cerr << "usage: posPsmodels input_file LPARSE_OPTION" << endl;
		exit(1);
	}

	//char *splitteFilename[sizeof(strtok(fname,"/"))];
	char *splittedFilename = strtok(fname,"/");
	//cout <<
	while (splittedFilename!=NULL) {
		programName2transform = "";
		programName2transform = splittedFilename;
		splittedFilename = strtok(NULL,"/");
	}

	//cout << "Program Name to transform " << Utils::char2string(programName2transform) << endl;
	string fileName = "lppod/"+Utils::char2string(programName2transform);
	//cout << "DEBUG filename: " << fileName << endl;
	//string filename = Utils::char2string(splitteFilename[sizeof(strok(fname,"/"))-1]);


	//transformedProgramName = Utils::string2char(filename.substr(6,(filename.size())-12));
	//cout << "transformedProgramName " << Utils::char2string(transformedProgramName) << endl;


	LppodProgram *p = new LppodProgram;
	//LppodProgram *transformed = new LppodProgram;

	//TODO: change the parse according the new syntax
	parseLppod(Utils::string2char(fileName),p);

	//parseLppod(Utils::string2char(fileName),transformed);
	//transformLppod(transformed);
	//generateLppod(transformed,programName2transform);
	//program_name = possibilistic_projection(Utils::string2char("tmp/"+Utils::char2string(programName2transform)));

	//TODO you can deprecate this function (which uses bison and flex) by means of the generateLppod function modified accordingly to
	//generate the program without numbers and to be place in the lpod/ folder
	//generateLppod(p,programName2transform);
	program_name = possibilistic_projection(Utils::string2char(fileName));

	//cout << "DEBUG program_name " << Utils::char2string(program_name) << endl;
	//program_name = "diagnosis";
	//char * program_name2 = "diagnosis";
	if (program_name == NULL) {
		cout << "\nPossibilistic projection failed....\n";
		exit(1);
	}



	list<LppodModel> *possModelList = new list<LppodModel>();
	string lparse_command;
	int reduced_programs_nr = 1;

	if (p->isOrderedDisjunctionProgram()) {

		//do not touch
		lparse_command = "./lparse --true-negation "+Utils::char2string(lparseOption)+" lpod/"+Utils::char2string(program_name)+".lpod >tmp/"+Utils::char2string(program_name)+".lparse";
		system(lparse_command.c_str());


		char *model_file = Utils::string2char("lpodmodels/"+Utils::char2string(program_name)+".models");
		string psmodel_command = "./psmodels 0 tmp/"+Utils::char2string(program_name)+".lparse > "+Utils::char2string(model_file);
		system(psmodel_command.c_str());


		//parse psmodel output and save models and satisfaction degrees
		//parsePsmodelsNew(model_file,modelList);
		parsePsmodelsForDecisionMaking(model_file,modelList);

		//for debug
		//printListElement(modelList);

		//reduce P according to the M_i found by psmodels (which are to be found in lpodmodels folder)

		//TODO to change the reduceLppod to produce the new reduction
		list<LppodProgram> *reduced_lppods = reduceLppod(modelList,p);

		//TODO change the generateReducedLppods to consider that each reduced program may have is own possibilistic value
		reduced_programs_nr = generateReducedLppods(reduced_lppods,Utils::char2string(program_name));

	}
	string reducedLPPOD;


	list<LpodModel>::iterator modelIt;
	int i = 1;
	string preproclparse_command;
	string possmodels_command;

	for (modelIt=modelList->begin();modelIt!=modelList->end();modelIt++) {
		//for(int i=1; i<=reduced_programs_nr; i++) {

		string preProcInput1;
		stringstream out;
		out << i;
		string nr = out.str();
		if (p->isOrderedDisjunctionProgram()) {

			reducedLPPOD = Utils::char2string(program_name)+".red"+nr;
			preProcInput1 = "reducedlppod/"+reducedLPPOD;
		}
		else {

			reducedLPPOD = Utils::char2string(program_name)+".lppod";
			preProcInput1 = "lppod/"+reducedLPPOD;
		}

		string preProcInput2 = "tmp/"+reducedLPPOD+".prelparse";
		preproclparse_command = "./preprocLparse "+preProcInput1+" > "+preProcInput2;
		system(preproclparse_command.c_str());
		lparse_command = "./lparse --true-negation tmp/"+reducedLPPOD+".prelparse > tmp/"+reducedLPPOD+".lparse";
		system(lparse_command.c_str());


		string output_file = "lpodmodels/"+reducedLPPOD+".possmodels";

		possmodels_command = "./posSmodels < tmp/"+reducedLPPOD+".lparse > "+output_file;
		system(possmodels_command.c_str());

		generatePossibilisticModels(possModelList,output_file,&(*modelIt));
		//printPossibilisticModels(possModelList);
		i++;

		//}
	}
	list<LppodModel> *sortedLppodModelL = new list<LppodModel>();

	//TODO change the possibilisticPreferenceRelation according to the new order to be produced
	possibilisticPreferenceRelation(possModelList,p,sortedLppodModelL);
	//possibilisticPreferenceRelation(possModelList,transformed,sortedLppodModelL);
	//possibilisticPreferenceRelation(possModelList,p,sortedLppodModelL);
	printPossibilisticModels(sortedLppodModelL);

	return (EXIT_SUCCESS);
}



