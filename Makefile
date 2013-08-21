## posPsmodels makefile
## author: rconfalonieri
## 24/08/2010



reasoner:
	cd posPsmodels; make quick; cp posPsmodels ../reasoner ;
	cd .. ;
	
all:
	cd lparse; chmod u+x configure; ./configure; make lparse; cp src/lparse ../reasoner; cd .. ;
	cd psmodels; make psmodels; cp psmodels ../reasoner; cd ..;
	cd smodels-2.28; make smodels;
	cd posSmodels/SRC; make all; cd ..; cp posSmodels ../reasoner; cp preprocLparse ../reasoner; cd .. ;
	cd posPsmodels; make quick; cp posPsmodels ../reasoner ; cd .. ;
	
	
clean:
	cd lparse ; make clean ; cd .. ;
	cd smodels-2.28/ ; make clean; 
	cd posSmodels/SRC ; make clean; cd ..; cd ..;
	cd psmodels; make clean; cd .. ;
	cd posPsmodels; make clean; cd .. ; 
	
help:
	@echo 'posPsmodels v0.1	'
	@echo 'type "make all" at first '
	@echo 'type "make -B reasoner" for compiling posPsmodels only '
	

