# Makefile for Ride Sharing System

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = RideSharingSystem
OBJS = main.o Ride.o StandardRide.o PremiumRide.o Driver.o Rider.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
main.o: main.cpp Ride.h StandardRide.h PremiumRide.h Driver.h Rider.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Ride.o: Ride.cpp Ride.h
	$(CXX) $(CXXFLAGS) -c Ride.cpp

StandardRide.o: StandardRide.cpp StandardRide.h Ride.h
	$(CXX) $(CXXFLAGS) -c StandardRide.cpp

PremiumRide.o: PremiumRide.cpp PremiumRide.h Ride.h
	$(CXX) $(CXXFLAGS) -c PremiumRide.cpp

Driver.o: Driver.cpp Driver.h Ride.h
	$(CXX) $(CXXFLAGS) -c Driver.cpp

Rider.o: Rider.cpp Rider.h Ride.h
	$(CXX) $(CXXFLAGS) -c Rider.cpp

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

