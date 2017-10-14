/*

Question: Design a parking lot using object-oriented principles.

How to approach:

1. Handle ambiguity
2. Define core objects
3. Analyze relationships
4. Investigate actions

Assumptions
- Has several floors
- For buses, cars and motorcycles
- parking fee depends on car sizes

Core objects
- A parking lot
- Spaeces for buses, cars and motor cycles
-- position (floor and #), available, how many hours occupied
- Vehicles

Actions
- Park/leave at
- Pay
- Check a charge
- Check if it's vacant

**************************
  My answer
**************************

@startuml
class Parking {
    - Vector<CarSpace> carSpaces
    - Vector<BusSpace> busSpaces
    - Vector<MotorcycleSpace> motorcycleSpaces
    
    + bool isAvailable(eSpace space)
    + Space* parkAt(eSpace space)
    + int checkCharge(Space* pSpace)
    + int payCharge(Space* pSpace, int money)
    - void leaveAt(Space* pSpace)
}

Parking o-- Space
class Space {
    - bool available
    - const int feePerHour
    - int currentCharge
    - int idNumber
    - Time parkTime
    - Vehicle* parkedVehicle
    + Space(int feePerHour, int number)
    + bool isAvailable()
    + Space* park(Vehicle* vechicle)
    + void leave(Vehicle* vehicle)
    + int getCurrentCharge()
}

Space <|-- CarSpace
class CarSpace {
}

Space <|-- BusSpace
class BusSpace {
}

Space <|-- MotorcycleSpace
class MotorcycleSpace {
}

@enduml

// Bus, Car, Motorcycle等の継承がうまく使えなかった

**************************
  Example answer
**************************

*/
