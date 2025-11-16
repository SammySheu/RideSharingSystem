#include "Driver.h"

Driver::Driver(int id, const std::string& driverName, double rate)
    : driverID(id), name(driverName), rating(rate) {
}

Driver::~Driver() {
    // Note: Rides are managed elsewhere, so we don't delete them here
}

void Driver::addRide(Ride* ride) {
    if (ride != nullptr) {
        assignedRides.push_back(ride);
        std::cout << "Ride #" << ride->getRideID() << " assigned to driver " << name << std::endl;
    }
}

void Driver::getDriverInfo() const {
    std::cout << "\n=== DRIVER INFORMATION ===" << std::endl;
    std::cout << "Driver ID: " << driverID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Rating: " << rating << " stars" << std::endl;
    std::cout << "Total Rides Completed: " << assignedRides.size() << std::endl;
    std::cout << "Total Earnings: $" << getTotalEarnings() << std::endl;
    
    if (!assignedRides.empty()) {
        std::cout << "\nCompleted Rides:" << std::endl;
        for (size_t i = 0; i < assignedRides.size(); i++) {
            std::cout << "  " << (i + 1) << ". Ride #" << assignedRides[i]->getRideID()
                      << " - " << assignedRides[i]->getPickupLocation()
                      << " to " << assignedRides[i]->getDropoffLocation()
                      << " ($" << assignedRides[i]->getFareAmount() << ")" << std::endl;
        }
    }
}

double Driver::getTotalEarnings() const {
    double total = 0.0;
    for (const auto& ride : assignedRides) {
        total += ride->getFareAmount();
    }
    return total;
}

int Driver::getDriverID() const {
    return driverID;
}

std::string Driver::getName() const {
    return name;
}

double Driver::getRating() const {
    return rating;
}

int Driver::getNumberOfRides() const {
    return assignedRides.size();
}

