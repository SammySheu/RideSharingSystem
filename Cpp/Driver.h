#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include <iostream>
#include "Ride.h"

// Driver class demonstrating encapsulation
class Driver {
private:
    int driverID;
    std::string name;
    double rating;
    std::vector<Ride*> assignedRides;  // Private member - encapsulation

public:
    // Constructor
    Driver(int id, const std::string& driverName, double rate);
    
    // Destructor
    ~Driver();
    
    // Method to add a ride to the driver's list
    void addRide(Ride* ride);
    
    // Method to display driver information
    void getDriverInfo() const;
    
    // Method to calculate total earnings
    double getTotalEarnings() const;
    
    // Getters (encapsulation - controlled access to private members)
    int getDriverID() const;
    std::string getName() const;
    double getRating() const;
    int getNumberOfRides() const;
};

#endif // DRIVER_H

