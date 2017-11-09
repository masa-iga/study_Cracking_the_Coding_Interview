CXX = g++
CXXFLAGS = -g -Wall -std=c++11 -I ./ -I ../
LDLIBS = -lCppUTest
TARGET = test
FILE = 8-10
SRCS = \
	$(FILE).cpp \

OBJS = \
	$(FILE).o \

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS)

$(FILE).o :
	$(CXX) -c $(CXXFLAGS) $(FILE).cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

