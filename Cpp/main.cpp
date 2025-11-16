#include <iostream>
#include <vector>
#include <memory>
#include "Ride.h"
#include "StandardRide.h"
#include "PremiumRide.h"
#include "Driver.h"
#include "Rider.h"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "   RIDE SHARING SYSTEM - C++ DEMO" << std::endl;
    std::cout << "========================================\n" << std::endl;

    // Create a collection of different ride types (POLYMORPHISM)
    std::vector<Ride*> allRides;
    
    // Create Standard Rides
    StandardRide* ride1 = new StandardRide(101, "Downtown", "Airport", 15.5);
    StandardRide* ride2 = new StandardRide(102, "Mall", "University", 8.2);
    
    // Create Premium Rides
    PremiumRide* ride3 = new PremiumRide(103, "Hotel", "Conference Center", 12.3);
    PremiumRide* ride4 = new PremiumRide(104, "Restaurant", "Theater", 5.7);
    
    // Add rides to collection
    allRides.push_back(ride1);
    allRides.push_back(ride2);
    allRides.push_back(ride3);
    allRides.push_back(ride4);
    
    // Calculate fares for all rides (POLYMORPHISM - calling overridden methods)
    std::cout << "=== CALCULATING FARES (Demonstrating Polymorphism) ===" << std::endl;
    for (auto ride : allRides) {
        ride->fare();  // Polymorphic call - calls appropriate fare() method
        std::cout << "Ride #" << ride->getRideID() << " fare calculated: $" 
                  << ride->getFareAmount() << std::endl;
    }
    std::cout << std::endl;
    
    // Display ride details (POLYMORPHISM)
    std::cout << "=== RIDE DETAILS (Demonstrating Polymorphism) ===" << std::endl;
    for (auto ride : allRides) {
        ride->rideDetails();  // Polymorphic call - calls appropriate rideDetails() method
    }
    
    // Create Drivers (ENCAPSULATION - private members with public methods)
    std::cout << "\n=== CREATING DRIVERS (Demonstrating Encapsulation) ===" << std::endl;
    Driver* driver1 = new Driver(201, "John Smith", 4.8);
    Driver* driver2 = new Driver(202, "Sarah Johnson", 4.9);
    
    // Assign rides to drivers
    std::cout << "\n=== ASSIGNING RIDES TO DRIVERS ===" << std::endl;
    driver1->addRide(ride1);
    driver1->addRide(ride3);
    driver2->addRide(ride2);
    driver2->addRide(ride4);
    
    // Display driver information
    driver1->getDriverInfo();
    driver2->getDriverInfo();
    
    // Create Riders (ENCAPSULATION)
    std::cout << "\n=== CREATING RIDERS (Demonstrating Encapsulation) ===" << std::endl;
    Rider* rider1 = new Rider(301, "Alice Brown");
    Rider* rider2 = new Rider(302, "Bob Wilson");
    
    // Riders request rides
    std::cout << "\n=== RIDERS REQUESTING RIDES ===" << std::endl;
    rider1->requestRide(ride1);
    rider1->requestRide(ride3);
    rider2->requestRide(ride2);
    rider2->requestRide(ride4);
    
    // View rider information and ride history
    rider1->viewRides();
    rider2->viewRides();
    
    // Summary Statistics
    std::cout << "\n========================================" << std::endl;
    std::cout << "   SYSTEM SUMMARY" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total Rides Processed: " << allRides.size() << std::endl;
    std::cout << "Total Drivers: 2" << std::endl;
    std::cout << "Total Riders: 2" << std::endl;
    
    double totalRevenue = 0.0;
    for (auto ride : allRides) {
        totalRevenue += ride->getFareAmount();
    }
    std::cout << "Total Revenue: $" << totalRevenue << std::endl;
    
    // Cleanup
    delete driver1;
    delete driver2;
    delete rider1;
    delete rider2;
    
    for (auto ride : allRides) {
        delete ride;
    }
    
    
    return 0;
}

