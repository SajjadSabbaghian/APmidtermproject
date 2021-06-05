CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/main.o ./obj/maze.o
# GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
./obj/maze.o: ./cpp/maze.cpp
	$(CXX) $(CXXFLAGS) ./cpp/maze.cpp -o ./obj/maze.o
# ./obj/aphw3_unittest.o: ./cpp/aphw3_unittest.cpp
# 	$(CXX) $(CXXFLAGS) ./cpp/aphw3_unittest.cpp -o ./obj/aphw3_unittest.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
