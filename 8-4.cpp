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

////////////////////////////
@startuml

class Parking {
}

Parking o-- Space
class Space {
    bool available
    const int feePerHour
    int charge
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
