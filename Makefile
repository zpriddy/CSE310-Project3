###############################################################################
#!/bin/bash
#
# Standard Make File
# Zachary Priddy
# me@zpriddy.com
# www.zpriddy.com
###############################################################################
#Name the output file here
EXECUTABLE=run
# List sources here seperated by a space:
SOURCES=main.cpp file_io.cpp errors.cpp min_heap.cpp 2d_array.cpp data_ops.cpp
# List objects here sperated by a space after $(....o):
OBJECTS=$(SOURCES:.cpp=.o)
# Other Settigns
CC=g++
CFLAGS=-c -Wall -w
LDFLAGS=

###############################################################################
#!!!!!!!! 				DO NOT EDIT BELOW HERE 					 !!!!!!!!!!!!!!
###############################################################################

$(BINARY): $(OBJECTS)
	g++ $(OBJECTS) -o $(BINARY)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

%.d: %.cpp
	rm -f $@; g++ -MM $< > $@

#This is for when you have .d files you need to read
#include $(SOURCES:.cpp=.d)

.PHONY: clean
clean:
	rm -f *.d
	rm -f $(BINARY)
	rm -f $(OBJECTS)

## 'make final' will make the program output and then clean up the directory
.PHONY: final
final:
	make
	rm -f *.d
	rm -f $(BINARY)
	rm -f $(OBJECTS)