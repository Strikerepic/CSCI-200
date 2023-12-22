# THE NAME OF YOUR EXECUTABLE
TARGET = A5
# ALL CPP COMPILABLE IMPLEMENTATION FILES THAT MAKE UP THE PROJECT
SRC_FILES = main.cpp Coordinate.cpp Polygon.cpp Triangle.cpp ScaleneTriangle.cpp IsoscelesTriangle.cpp EquilateralTriangle.cpp Quadrilateral.cpp Rhombus.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS_DEBUG = -g
CXXVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(OS),Windows_NT)
	TARGET := $(TARGET).exe
	DEL = del
	Q =

	INC_PATH = Z:/CSCI200/include/
	LIB_PATH = Z:/CSCI200/lib/

	ARCH = 
	RPATH =
else
	DEL = rm -f
	Q = "

	INC_PATH = /usr/local/include/
	LIB_PATH = /usr/local/lib/

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CXXFLAGS += -D LINUX
		RPATH =
	endif
	ifeq ($(UNAME_S),Darwin)
		TARGET_MAKEFILE = Makefile.osx
		CXXFLAGS += -D OSX
		RPATH = -Wl,-rpath,/Library/Frameworks
	endif

	UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		ARCH = 
	endif
	ifneq ($(filter %86,$(UNAME_P)),)
		ARCH = 
	endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		ARCH = 
	endif
endif

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(ARCH) -o $@ $^ $(RPATH) -L$(LIB_PATH) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(ARCH) -o $@ -c $< -I$(INC_PATH)

clean:
	$(DEL) $(TARGET) $(OBJECTS)
	
depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES 
main.o: main.cpp Coordinate.h Polygon.h Triangle.h ScaleneTriangle.h \
 IsoscelesTriangle.h EquilateralTriangle.h Quadrilateral.h Rhombus.h
Coordinate.o: Coordinate.cpp Coordinate.h
Polygon.o: Polygon.cpp Polygon.h Coordinate.h
Triangle.o: Triangle.cpp Triangle.h Polygon.h Coordinate.h
ScaleneTriangle.o: ScaleneTriangle.cpp ScaleneTriangle.h Triangle.h \
 Polygon.h Coordinate.h
IsoscelesTriangle.o: IsoscelesTriangle.cpp IsoscelesTriangle.h Triangle.h \
 Polygon.h Coordinate.h
EquilateralTriangle.o: EquilateralTriangle.cpp EquilateralTriangle.h \
 Triangle.h Polygon.h Coordinate.h
Quadrilateral.o: Quadrilateral.cpp Quadrilateral.h Polygon.h Coordinate.h
Rhombus.o: Rhombus.cpp Rhombus.h Quadrilateral.h Polygon.h Coordinate.h
