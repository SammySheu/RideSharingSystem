#ifndef STANDARDRIDE_H
#define STANDARDRIDE_H

#include "Ride.h"

// Derived class demonstrating inheritance and polymorphism
class StandardRide : public Ride {
private:
    static const double BASE_FARE;
    static const double RATE_PER_MILE;

public:
    // Constructor
    StandardRide(int id, const std::string& pickup, const std::string& dropoff, double dist);
    
    // Override fare calculation for standard rides
    double fare() override;
    
    // Override ride details to include ride type
    void rideDetails() const override;
};

#endif // STANDARDRIDE_H

