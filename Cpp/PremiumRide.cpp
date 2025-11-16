#include "PremiumRide.h"

const double PremiumRide::BASE_FARE = 5.00;
const double PremiumRide::RATE_PER_MILE = 2.50;
const double PremiumRide::LUXURY_SURCHARGE = 3.00;

PremiumRide::PremiumRide(int id, const std::string& pickup, const std::string& dropoff, double dist)
    : Ride(id, pickup, dropoff, dist) {
}

double PremiumRide::fare() {
    fareAmount = BASE_FARE + (distance * RATE_PER_MILE) + LUXURY_SURCHARGE;
    return fareAmount;
}

void PremiumRide::rideDetails() const {
    std::cout << "\n=== PREMIUM RIDE ===" << std::endl;
    Ride::rideDetails();
    std::cout << "Includes: Luxury vehicle, Premium service" << std::endl;
}

