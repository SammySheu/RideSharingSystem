"Main script to demonstrate the Ride Sharing System in Smalltalk"

| ride1 ride2 ride3 ride4 allRides driver1 driver2 rider1 rider2 totalRevenue |

"Display header"
Transcript show: '========================================'; nl.
Transcript show: '   RIDE SHARING SYSTEM - SMALLTALK DEMO'; nl.
Transcript show: '========================================'; nl; nl.

"Create different ride types (demonstrating inheritance)"
ride1 := StandardRide 
    newWithID: 101 
    pickup: 'Downtown' 
    dropoff: 'Airport' 
    distance: 15.5.

ride2 := StandardRide 
    newWithID: 102 
    pickup: 'Mall' 
    dropoff: 'University' 
    distance: 8.2.

ride3 := PremiumRide 
    newWithID: 103 
    pickup: 'Hotel' 
    dropoff: 'Conference Center' 
    distance: 12.3.

ride4 := PremiumRide 
    newWithID: 104 
    pickup: 'Restaurant' 
    dropoff: 'Theater' 
    distance: 5.7.

"Create collection of different ride types (polymorphism)"
allRides := OrderedCollection new.
allRides add: ride1.
allRides add: ride2.
allRides add: ride3.
allRides add: ride4.

"Calculate fares polymorphically"
Transcript show: '=== CALCULATING FARES (Demonstrating Polymorphism) ==='; nl.
allRides do: [ :ride |
    ride fare.
    Transcript show: 'Ride #', ride rideID printString, 
                     ' fare calculated: $', (NumberFormatter format: ride fareAmount); nl.
].
Transcript nl.

"Display ride details polymorphically"
Transcript show: '=== RIDE DETAILS (Demonstrating Polymorphism) ==='; nl.
allRides do: [ :ride |
    ride rideDetails.
].

"Create Drivers (demonstrating encapsulation)"
Transcript nl.
Transcript show: '=== CREATING DRIVERS (Demonstrating Encapsulation) ==='; nl; nl.

driver1 := Driver 
    newWithID: 201 
    name: 'John Smith' 
    rating: 4.8.

driver2 := Driver 
    newWithID: 202 
    name: 'Sarah Johnson' 
    rating: 4.9.

"Assign rides to drivers"
Transcript show: '=== ASSIGNING RIDES TO DRIVERS ==='; nl.
driver1 addRide: ride1.
driver1 addRide: ride3.
driver2 addRide: ride2.
driver2 addRide: ride4.

"Display driver information"
driver1 getDriverInfo.
driver2 getDriverInfo.

"Create Riders (demonstrating encapsulation)"
Transcript nl.
Transcript show: '=== CREATING RIDERS (Demonstrating Encapsulation) ==='; nl; nl.

rider1 := Rider 
    newWithID: 301 
    name: 'Alice Brown'.

rider2 := Rider 
    newWithID: 302 
    name: 'Bob Wilson'.

"Riders request rides"
Transcript show: '=== RIDERS REQUESTING RIDES ==='; nl.
rider1 requestRide: ride1.
rider1 requestRide: ride3.
rider2 requestRide: ride2.
rider2 requestRide: ride4.

"View rider information"
rider1 viewRides.
rider2 viewRides.

"Summary Statistics"
Transcript nl.
Transcript show: '========================================'; nl.
Transcript show: '   SYSTEM SUMMARY'; nl.
Transcript show: '========================================'; nl.
Transcript show: 'Total Rides Processed: ', allRides size printString; nl.
Transcript show: 'Total Drivers: 2'; nl.
Transcript show: 'Total Riders: 2'; nl.

totalRevenue := 0.
allRides do: [ :ride | totalRevenue := totalRevenue + ride fareAmount ].
Transcript show: 'Total Revenue: $', (NumberFormatter format: totalRevenue); nl.

"Demonstrate OOP principles"
Transcript nl.
Transcript show: '=== OOP PRINCIPLES DEMONSTRATED ==='; nl.
Transcript show: '1. ENCAPSULATION: Private instance variables in Driver and Rider'; nl.
Transcript show: '   classes with controlled access through accessor methods.'; nl.
Transcript show: '2. INHERITANCE: StandardRide and PremiumRide inherit from Ride'; nl.
Transcript show: '   using subclass: message.'; nl.
Transcript show: '3. POLYMORPHISM: Different ride types respond to same messages'; nl.
Transcript show: '   (fare, rideDetails) with different behavior through message'; nl.
Transcript show: '   passing and late binding.'; nl.

Transcript nl.
Transcript show: '========================================'; nl.
Transcript show: '   PROGRAM ENDED SUCCESSFULLY'; nl.
Transcript show: '========================================'; nl.
