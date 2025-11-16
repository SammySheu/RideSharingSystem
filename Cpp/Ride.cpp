#include "Ride.h"

Ride::Ride(int id, const std::string& pickup, const std::string& dropoff, double dist)
    : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist), fareAmount(0.0) {
}

Ride::~Ride() {
}

void Ride::rideDetails() const {
    std::cout << "Ride ID: " << rideID << std::endl;
    std::cout << "Pickup: " << pickupLocation << std::endl;
    std::cout << "Dropoff: " << dropoffLocation << std::endl;
    std::cout << "Distance: " << distance << " miles" << std::endl;
    std::cout << "Fare: $" << fareAmount << std::endl;
}

int Ride::getRideID() const {
    return rideID;
}

std::string Ride::getPickupLocation() const {
    return pickupLocation;
}

std::string Ride::getDropoffLocation() const {
    return dropoffLocation;
}

double Ride::getDistance() const {
    return distance;
}

double Ride::getFareAmount() const {
    return fareAmount;
}

