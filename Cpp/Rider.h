#ifndef RIDER_H
#define RIDER_H

#include <string>
#include <vector>
#include <iostream>
#include "Ride.h"

// Rider class demonstrating encapsulation
class Rider {
private:
    int riderID;
    std::string name;
    std::vector<Ride*> requestedRides;  // Private member - encapsulation

public:
    // Constructor
    Rider(int id, const std::string& riderName);
    
    // Destructor
    ~Rider();
    
    // Method to request a ride
    void requestRide(Ride* ride);
    
    // Method to view ride history
    void viewRides() const;
    
    // Method to calculate total spent
    double getTotalSpent() const;
    
    // Getters (encapsulation - controlled access to private members)
    int getRiderID() const;
    std::string getName() const;
    int getNumberOfRides() const;
};

#endif // RIDER_H

