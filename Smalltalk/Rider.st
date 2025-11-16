"Rider class demonstrating encapsulation"

Object subclass: Rider [
    | riderID name requestedRides |
    
    <comment: 'Rider class with encapsulated ride list'>
    
    Rider class >> newWithID: id name: riderName [
        "Create and initialize a new rider"
        ^ self new 
            initializeWithID: id 
            name: riderName
    ]
    
    initializeWithID: id name: riderName [
        "Initialize instance variables"
        riderID := id.
        name := riderName.
        requestedRides := OrderedCollection new.
        ^ self
    ]
    
    requestRide: aRide [
        "Add a ride to the rider's requested rides"
        requestedRides add: aRide.
        Transcript show: 'Ride #', aRide rideID printString, 
                         ' requested by ', name; nl.
    ]
    
    viewRides [
        "Display rider information and ride history"
        | index |
        Transcript nl.
        Transcript show: '=== RIDER INFORMATION ==='; nl.
        Transcript show: 'Rider ID: ', riderID printString; nl.
        Transcript show: 'Name: ', name; nl.
        Transcript show: 'Total Rides: ', requestedRides size printString; nl.
        Transcript show: 'Total Spent: $', (NumberFormatter format: self getTotalSpent); nl.
        
        requestedRides isEmpty ifFalse: [
            Transcript nl; show: 'Ride History:'; nl.
            index := 1.
            requestedRides do: [ :ride |
                Transcript show: '  ', index printString, '. Ride #', 
                           ride rideID printString, ' - ',
                           ride pickupLocation, ' to ', ride dropoffLocation,
                           ' - ', (NumberFormatter format: ride distance), ' miles ($', 
                           (NumberFormatter format: ride fareAmount), ')'; nl.
                index := index + 1.
            ]
        ].
    ]
    
    getTotalSpent [
        "Sum up fares from all requested rides"
        | total |
        total := 0.
        requestedRides do: [ :ride | total := total + ride fareAmount ].
        ^ total
    ]
    
    "Accessor methods"
    riderID [ ^ riderID ]
    name [ ^ name ]
    numberOfRides [ ^ requestedRides size ]
]
