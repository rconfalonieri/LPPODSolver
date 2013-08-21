CXX = g++
CXXFLAGS = -O3 -W -Wall -I ../../smodels-2.28/
LFLAGS =
SRCS = MyAtom.cpp AtomSet.cpp PosAtom.cpp PosAtomSet.cpp MyRule.cpp  PosRule.cpp  PosRuleVector.cpp Dictionnary.cpp  PosLogProg.cpp ApiExt.cpp LogProgReader.cpp lpio.cpp Main.cpp 
OBJS = $(SRCS:.cpp=.o)
SMODELSSRCS = smodels.cc stack.cc dcl.cc atomrule.cc read.cc \
queue.cc timer.cc list.cc improve.cc program.cc api.cc stable.cc \
tree.cc denant.cc
SMODELSOBJS = $(SMODELSSRCS:%.cc=../../smodels-2.28/%.o)


all: posSmodels preprocLparse

posSmodels: $(OBJS)
	$(CXX) $(LFLAGS) -o "../posSmodels" $(OBJS) $(SMODELSOBJS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< 

preprocLparse: preprocLparse.o
	$(CXX) $(LFLAGS) -o "../preprocLparse" preprocLparse.o 

preprocLparse.cpp: preprocLparse.y preprocLparse.lex.c
	bison -o preprocLparse.cpp preprocLparse.y

preprocLparse.lex.c: preprocLparse.l
	flex -opreprocLparse.lex.c preprocLparse.l

clean:
	rm -f $(OBJS) posSmodels.o posSmodels preprocLparse.o preprocLparse

distclean: clean
	rm -f preprocLparse.cpp preprocLparse.lex.c 

