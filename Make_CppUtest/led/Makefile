CC=g++

INCLUDE +=.

CPPUTEST_HOME = /home/ysun/cpputest/cpputest
CPPFLAGS += -I$(CPPUTEST_HOME)/include
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

all:myapp
test:myapp_test
 
myapp:main.o sample.o io.o
	$(CC) -o myapp main.o sample.o io.o $(LD_LIBRARIES)
myapp_test:sample_test.o sample.o sample_stubs.o
	$(CC) -o myapp_test sample_test.o sample.o sample_stubs.o $(LD_LIBRARIES)
main.o:main.cpp
	$(CC) -c main.cpp -I$(INCLUDE) $(CPPFLAGS) $(CXXFLAGS)
sample_test.o:sample_test.cpp
	$(CC) -c sample_test.cpp -I$(INCLUDE) $(CPPFLAGS) $(CXXFLAGS)
sample.o:sample.cpp
	$(CC) -c sample.cpp -I$(INCLUDE) $(CPPFLAGS) $(CXXFLAGS)
io.o:io.cpp
	$(CC) -c io.cpp -I$(INCLUDE) $(CPPFLAGS) $(CXXFLAGS)
clean:
	rm myapp* *.o
	
