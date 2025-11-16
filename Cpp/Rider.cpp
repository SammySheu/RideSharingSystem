#include "Rider.h"

Rider::Rider(int id, const std::string& riderName)
    : riderID(id), name(riderName) {
}

Rider::~Rider() {
    // Note: Rides are managed elsewhere, so we don't delete them here
}

void Rider::requestRide(Ride* ride) {
    if (ride != nullptr) {
        requestedRides.push_back(ride);
        std::cout << "Ride #" << ride->getRideID() << " requested by " << name << std::endl;
    }
}

void Rider::viewRides() const {
    std::cout << "\n=== RIDER INFORMATION ===" << std::endl;
    std::cout << "Rider ID: " << riderID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Total Rides: " << requestedRides.size() << std::endl;
    std::cout << "Total Spent: $" << getTotalSpent() << std::endl;
    
    if (!requestedRides.empty()) {
        std::cout << "\nRide History:" << std::endl;
        for (size_t i = 0; i < requestedRides.size(); i++) {
            std::cout << "  " << (i + 1) << ". Ride #" << requestedRides[i]->getRideID()
                      << " - " << requestedRides[i]->getPickupLocation()
                      << " to " << requestedRides[i]->getDropoffLocation()
                      << " - " << requestedRides[i]->getDistance() << " miles"
                      << " ($" << requestedRides[i]->getFareAmount() << ")" << std::endl;
        }
    }
}

double Rider::getTotalSpent() const {
    double total = 0.0;
    for (const auto& ride : requestedRides) {
        total += ride->getFareAmount();
    }
    return total;
}

int Rider::getRiderID() const {
    return riderID;
}

std::string Rider::getName() const {
    return name;
}

int Rider::getNumberOfRides() const {
    return requestedRides.size();
}

