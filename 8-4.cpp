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
*/

/**************************
  My answer
**************************/
/*
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

*/
/**************************
  Example answer
**************************/

Enum VehicleSize { Motorcycle, Compact, Large }

class Vehicle {
protected:
  Vector<ParkingSpot> parkingSpots;
  String licensePlate;
  int spotsNeeded;
  VehicleSize size;

public:
  int getSpotsNeeded()
  VehicleSize getSize()
  
  /* Park vehicle in this spot (among others, potentially) */
  void parkInSpot(ParkingSpot s);
  
  /* Remove car from spot, and notify spot that it's gone */
  void clearSpots();
  
  /* Checks if the spot is big enough for the vehicle (and is
   * available). This compares the SIZE only. It does not check it
   * has enough spots. */
  virtual bool canFitInSpot(ParkingSpot spot);
};

// TODO: write down inherited classes

class ParkingLot {
public:
  ParkingLot();
  /* Park the vehicle in a spot (or multiple spots).
   * Return false if failed. */
  bool parkVehicle(Vehicle* vehicle);

private:
  Level[] levels;
  const int NUM_LEVELS = 5;
};

class Level {
public:
  Level(int flr, int numberSpots);
  int availableSpots();
  
  /* Find a place to park this vehicle. Return false if failed. */
  bool parkVehicle(Vehicle* vehicle);
  
  /* Park a vehicle starting at the spot spotNumber, and
   * continuing until vehicle.spotsNeeded. */
  bool parkStartingAtSpot(int num, Vehicle v);

  /* When a car was removed from the spot, increment
   * availableSpots */
  void spotFreed();
  
private:
  int floor;
  ParkingSpot[] spots;
  int availableSpots = 0; // number of free spots
  static const int SPOTS_PER_ROW = 10;
  
  /* Find a spot to park this vehicle. Return index of spot, or -1
   * on failure. */
  int findAvailableSpots(Vehicle vehicle);
};

class ParkingSpot {
public:
  ParkingSpot(int lvl, int r, int n, VehicleSize s);
  bool isAvailable();
  
  /* Check if the spot is big enough and is available */
  bool canFitVehicle(Vehicle vehicle);
  
  /* Park vehicle in this spot. */
  bool park(Vehicle* v);
  
  int getRow();
  int getSpotNumber();
  
  /* Remove vehicle from spot, and notify level that a new spot is
   * available */
  void removeVehicle();
  
private:
  Vehicle* vehicle;
  VehicleSize spotSize;
  int row;
  int spotNumber;
  Level level;
};
