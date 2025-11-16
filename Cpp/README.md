# Ride Sharing System - C++ Implementation

## Project Structure

```
@Cpp/
├── Ride.h              # Base class header (abstract)
├── Ride.cpp            # Base class implementation
├── StandardRide.h      # StandardRide derived class header
├── StandardRide.cpp    # StandardRide implementation
├── PremiumRide.h       # PremiumRide derived class header
├── PremiumRide.cpp     # PremiumRide implementation
├── Driver.h            # Driver class header
├── Driver.cpp          # Driver class implementation
├── Rider.h             # Rider class header
├── Rider.cpp           # Rider class implementation
├── main.cpp            # Main program demonstrating system
├── Makefile            # Build configuration
└── README.md           # This file
```

## Classes

### 1. Ride (Abstract Base Class)
- **Attributes**: rideID, pickupLocation, dropoffLocation, distance, fareAmount
- **Methods**: 
  - `virtual double fare()` - Pure virtual method for calculating fare
  - `virtual void rideDetails()` - Display ride information
  - Getters for all attributes

### 2. StandardRide (Derived Class)
- **Inherits from**: Ride
- **Fare Calculation**: Base fare ($2.50) + ($1.50 per mile)
- **Overrides**: `fare()` and `rideDetails()` methods

### 3. PremiumRide (Derived Class)
- **Inherits from**: Ride
- **Fare Calculation**: Base fare ($5.00) + ($2.50 per mile) + Luxury surcharge ($3.00)
- **Overrides**: `fare()` and `rideDetails()` methods

### 4. Driver Class
- **Attributes**: driverID, name, rating, assignedRides (private vector)
- **Methods**:
  - `addRide(Ride* ride)` - Add a ride to driver's list
  - `getDriverInfo()` - Display driver information
  - `getTotalEarnings()` - Calculate total earnings
- **Demonstrates**: Encapsulation (private assignedRides accessed through public methods)

### 5. Rider Class
- **Attributes**: riderID, name, requestedRides (private vector)
- **Methods**:
  - `requestRide(Ride* ride)` - Request a ride
  - `viewRides()` - Display ride history
  - `getTotalSpent()` - Calculate total amount spent
- **Demonstrates**: Encapsulation (private requestedRides accessed through public methods)

## Building and Running

### Compilation
```bash
# Using Makefile
make
```

### Running
```bash
./RideSharingSystem
```

### Cleaning
```bash
make clean
```

## Sample Output
The program demonstrates:
1. Creating multiple rides (Standard and Premium)
2. Calculating fares polymorphically
3. Displaying ride details polymorphically
4. Assigning rides to drivers
5. Riders requesting rides
6. Viewing driver and rider information
7. System summary statistics

