CXX = g++
CXXFLAGS = -g -W -Wall 
LFLAGS = -g 
SRCS = main.cc smodels.cc stack.cc dcl.cc atomrule.cc read.cc \
       queue.cc timer.cc list.cc improve.cc program.cc api.cc stable.cc \
       tree.cc denant.cc
OBJS = $(SRCS:.cc=.o)

psmodels: $(OBJS)
	$(CXX) $(LFLAGS) -o psmodels $(OBJS)


clean:
	rm -f *.o ; rm -f psmodels

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<
