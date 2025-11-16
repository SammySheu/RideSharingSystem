"PremiumRide - Derived class demonstrating inheritance and polymorphism"

Ride subclass: PremiumRide [
    | |
    
    <comment: 'Premium ride with luxury pricing'>
    
    PremiumRide class >> baseFare [ ^ 5.00 ]
    PremiumRide class >> ratePerMile [ ^ 2.50 ]
    PremiumRide class >> luxurySurcharge [ ^ 3.00 ]
    
    fare [
        "Calculate fare for premium ride"
        | calculatedFare |
        calculatedFare := self class baseFare + 
                         (distance * self class ratePerMile) + 
                         self class luxurySurcharge.
        fareAmount := calculatedFare.
        ^ fareAmount
    ]
    
    rideDetails [
        "Display premium ride information"
        Transcript nl.
        Transcript show: '=== PREMIUM RIDE ==='; nl.
        super rideDetails.
        Transcript show: 'Includes: Luxury vehicle, Premium service'; nl.
    ]
    
    rideType [ ^ 'Premium' ]
]
