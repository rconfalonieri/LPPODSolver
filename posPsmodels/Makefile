## computeLPPOD makefile
## author: rconfalonieri
## 15/12/2009


CXXFLAGS =	-O2 -g -w
CXX = g++
OBJS = posPsmodels.o
TARGET = posPsmodels

SRCS = utils.cc lpodmodel.cc lppodmodel.cc parsing.cc lppodprogram.cc lppodrule.cc possibilisticatom.cc fact.cc lppodreduction.cc lppodtransformations.cc possibilisticdegree.cc possprefrelation.cc main.cc 
OBJS = $(SRCS:.cc=.o)


$(TARGET): clean preprocLPPODparse.o $(OBJS) 
	#$(CXX) $(CXXFLAGS) $(LIBS) $(OBJS)  preprocLPPODparse.o  -o  $(TARGET) -lfl
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJS)  -o  $(TARGET)    
	
quick: clean preprocLPPODparse.o $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS)  preprocLPPODparse.o  -o  $(TARGET) $(LIBS) 
	
preprocLPPODparse.o: preprocLPPODparse.cc
	$(CXX) $(CXXFLAGS) -c $<
	
	
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< 
	
preprocLPPODparse: preprocLPPODparse.o
	$(CXX) $(CXXFLAGS) $(LFLAGS) -o preprocLPPODparse preprocLPPODparse.o -lfl



preprocLPPODparse.cc: preprocLPPODparse.yy preprocLPPODparse.lex.c
	bison -o preprocLPPODparse.cc preprocLPPODparse.yy

preprocLPPODparse.lex.c: preprocLPPODparse.ll
	flex -o preprocLPPODparse.lex.c preprocLPPODparse.ll


clean:
	rm -f preprocLPPODparse.o preprocLPPODparse.cc preprocLPPODparse.lex.c
	rm -f $(OBJS) $(TARGET) 
