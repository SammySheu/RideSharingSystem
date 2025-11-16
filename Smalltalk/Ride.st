"Ride Sharing System - GNU Smalltalk Implementation
Base class: Ride (Abstract)"

Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance fareAmount |
    
    <comment: 'Abstract base class for all ride types'>
    
    Ride class >> newWithID: id pickup: pickup dropoff: dropoff distance: dist [
        "Create and initialize a new ride"
        ^ self new 
            initializeWithID: id 
            pickup: pickup 
            dropoff: dropoff 
            distance: dist
    ]
    
    initializeWithID: id pickup: pickup dropoff: dropoff distance: dist [
        "Initialize instance variables"
        rideID := id.
        pickupLocation := pickup.
        dropoffLocation := dropoff.
        distance := dist.
        fareAmount := 0.
        ^ self
    ]
    
    fare [
        "Calculate fare - subclass responsibility (polymorphism)"
        self subclassResponsibility
    ]
    
    rideDetails [
        "Display information about the ride"
        Transcript show: 'Ride ID: ', rideID printString; nl.
        Transcript show: 'Pickup: ', pickupLocation; nl.
        Transcript show: 'Dropoff: ', dropoffLocation; nl.
        Transcript show: 'Distance: ', (NumberFormatter format: distance), ' miles'; nl.
        Transcript show: 'Fare: $', (NumberFormatter format: fareAmount); nl.
    ]
    
    "Accessor methods"
    rideID [ ^ rideID ]
    pickupLocation [ ^ pickupLocation ]
    dropoffLocation [ ^ dropoffLocation ]
    distance [ ^ distance ]
    fareAmount [ ^ fareAmount ]
    fareAmount: amount [ fareAmount := amount ]
]
