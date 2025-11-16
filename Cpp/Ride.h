#ifndef RIDE_H
#define RIDE_H

#include <string>
#include <iostream>

// Base class Ride demonstrating encapsulation and inheritance
class Ride {
protected:
    int rideID;
    std::string pickupLocation;
    std::string dropoffLocation;
    double distance;
    double fareAmount;

public:
    // Constructor
    Ride(int id, const std::string& pickup, const std::string& dropoff, double dist);
    
    // Virtual destructor for proper cleanup
    virtual ~Ride();
    
    // Virtual method for polymorphism - to be overridden by derived classes
    virtual double fare() = 0;
    
    // Method to display ride details
    virtual void rideDetails() const;
    
    // Getters (encapsulation)
    int getRideID() const;
    std::string getPickupLocation() const;
    std::string getDropoffLocation() const;
    double getDistance() const;
    double getFareAmount() const;
};

#endif // RIDE_H

