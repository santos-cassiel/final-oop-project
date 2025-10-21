CXX = g++

SOURCES = $(wildcard src/*.cpp)

TARGET = game

all: $(TARGET)

$(TARGET): 
	$(CXX) $(SOURCES) -o $(TARGET)

clean: 
	rm -f $(TARGET)