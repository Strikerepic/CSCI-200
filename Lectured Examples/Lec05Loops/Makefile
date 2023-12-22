TARGET = Loops
SRC_FILES = main.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

.PHONY: all clean depend
