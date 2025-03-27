CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET = matrix_program

SRCS = main.cpp matrix.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	
.PHONY: all clean