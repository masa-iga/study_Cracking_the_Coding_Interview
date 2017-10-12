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

////////////////////////////
@startuml

class Parking {
    Vector<CarSpace> carSpaces
    Vector<BusSpace> busSpaces
    Vector<MotorcycleSpace> motorcycleSpaces
    bool isAvailable(eSpace space)
    Space* parkAt(eSpace space)
    int getCharge(Space* pSpace)
    void leaveAt(Space* pSpace)
}

Parking o-- Space
class Space {
    bool available
    const int feePerHour
    int charge
    int number
    Time parkedTime
    Space(int feePerHour, int number)
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


*/
