#include "StandardRide.h"

const double StandardRide::BASE_FARE = 2.50;
const double StandardRide::RATE_PER_MILE = 1.50;

StandardRide::StandardRide(int id, const std::string& pickup, const std::string& dropoff, double dist)
    : Ride(id, pickup, dropoff, dist) {
}

double StandardRide::fare() {
    fareAmount = BASE_FARE + (distance * RATE_PER_MILE);
    return fareAmount;
}

void StandardRide::rideDetails() const {
    std::cout << "\n=== STANDARD RIDE ===" << std::endl;
    Ride::rideDetails();
}

