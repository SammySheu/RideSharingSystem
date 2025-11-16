"Driver class demonstrating encapsulation"

Object subclass: Driver [
    | driverID name rating assignedRides |
    
    <comment: 'Driver class with encapsulated ride list'>
    
    Driver class >> newWithID: id name: driverName rating: rate [
        "Create and initialize a new driver"
        ^ self new 
            initializeWithID: id 
            name: driverName 
            rating: rate
    ]
    
    initializeWithID: id name: driverName rating: rate [
        "Initialize instance variables"
        driverID := id.
        name := driverName.
        rating := rate.
        assignedRides := OrderedCollection new.
        ^ self
    ]
    
    addRide: aRide [
        "Add a ride to the driver's assigned rides"
        assignedRides add: aRide.
        Transcript show: 'Ride #', aRide rideID printString, 
                         ' assigned to driver ', name; nl.
    ]
    
    getDriverInfo [
        "Display driver details and assigned rides"
        | index |
        Transcript nl.
        Transcript show: '=== DRIVER INFORMATION ==='; nl.
        Transcript show: 'Driver ID: ', driverID printString; nl.
        Transcript show: 'Name: ', name; nl.
        Transcript show: 'Rating: ', (NumberFormatter format: rating), ' stars'; nl.
        Transcript show: 'Total Rides Completed: ', assignedRides size printString; nl.
        Transcript show: 'Total Earnings: $', (NumberFormatter format: self getTotalEarnings); nl.
        
        assignedRides isEmpty ifFalse: [
            Transcript nl; show: 'Completed Rides:'; nl.
            index := 1.
            assignedRides do: [ :ride |
                Transcript show: '  ', index printString, '. Ride #', 
                           ride rideID printString, ' - ',
                           ride pickupLocation, ' to ', ride dropoffLocation,
                           ' ($', (NumberFormatter format: ride fareAmount), ')'; nl.
                index := index + 1.
            ]
        ].
    ]
    
    getTotalEarnings [
        "Sum up fares from all assigned rides"
        | total |
        total := 0.
        assignedRides do: [ :ride | total := total + ride fareAmount ].
        ^ total
    ]
    
    "Accessor methods"
    driverID [ ^ driverID ]
    name [ ^ name ]
    rating [ ^ rating ]
    numberOfRides [ ^ assignedRides size ]
]
