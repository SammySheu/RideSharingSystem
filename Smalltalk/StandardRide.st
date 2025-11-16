"StandardRide - Derived class demonstrating inheritance and polymorphism"

Ride subclass: StandardRide [
    | |
    
    <comment: 'Standard ride with basic pricing'>
    
    StandardRide class >> baseFare [ ^ 2.50 ]
    StandardRide class >> ratePerMile [ ^ 1.50 ]
    
    fare [
        "Calculate fare for standard ride"
        | calculatedFare |
        calculatedFare := self class baseFare + (distance * self class ratePerMile).
        fareAmount := calculatedFare.
        ^ fareAmount
    ]
    
    rideDetails [
        "Display standard ride information"
        Transcript nl.
        Transcript show: '=== STANDARD RIDE ==='; nl.
        super rideDetails.
    ]
    
    rideType [ ^ 'Standard' ]
]
