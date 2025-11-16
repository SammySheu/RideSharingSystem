#ifndef PREMIUMRIDE_H
#define PREMIUMRIDE_H

#include "Ride.h"

// Derived class demonstrating inheritance and polymorphism
class PremiumRide : public Ride {
private:
    static const double BASE_FARE;
    static const double RATE_PER_MILE;
    static const double LUXURY_SURCHARGE;

public:
    // Constructor
    PremiumRide(int id, const std::string& pickup, const std::string& dropoff, double dist);
    
    // Override fare calculation for premium rides (higher rates)
    double fare() override;
    
    // Override ride details to include ride type
    void rideDetails() const override;
};

#endif // PREMIUMRIDE_H

