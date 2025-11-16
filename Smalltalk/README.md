# Ride Sharing System - Smalltalk Implementation

## Files

```
Smalltalk/
├── Ride.st              # Abstract base class
├── StandardRide.st      # Standard ride (inherits from Ride)
├── PremiumRide.st       # Premium ride (inherits from Ride)
├── Driver.st            # Driver class (demonstrates encapsulation)
├── Rider.st             # Rider class (demonstrates encapsulation)
├── Main.st              # Main script to run the system
└── README.md            # This file
```

## How to Run

#### Install GNU Smalltalk:

**Mac:**
```bash
brew install gnu-smalltalk
```

**Ubuntu/Debian:**
```bash
sudo apt-get install gnu-smalltalk
```

**Windows:**
Download from: http://smalltalk.gnu.org/download

#### Run the Program:

```bash
# Navigate to Smalltalk directory
cd Smalltalk

# Load and run all files
gst Utils.st Ride.st StandardRide.st PremiumRide.st Driver.st Rider.st Main.st
```

### Key Smalltalk Concepts

#### 1. Class Definition

```smalltalk
Object subclass: #Driver
    instanceVariableNames: 'driverID name rating assignedRides'
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharingSystem'
```

This creates a new class `Driver` that inherits from `Object`.

#### 2. Method Definition

```smalltalk
Driver >> addRide: aRide
    "Add a ride to the driver's list"
    assignedRides add: aRide.
```

- `>>` separates class name from method name
- `addRide:` is the method selector
- `aRide` is the parameter
- Text in quotes are comments

#### 3. Message Sending

```smalltalk
driver addRide: ride.          "Keyword message"
ride fare.                     "Unary message"
3 + 4.                         "Binary message"
```

Everything in Smalltalk is a message send!

#### 4. Blocks (Closures)

```smalltalk
allRides do: [ :ride |
    ride fare.
].
```

`[ :ride | ... ]` is a block - similar to lambda/closure in other languages.
