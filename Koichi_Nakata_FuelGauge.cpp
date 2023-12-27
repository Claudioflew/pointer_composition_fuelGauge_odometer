#include "Koichi_Nakata_FuelGauge.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Comment 2: Constructors should not do input validation. A member function inside the class should be responsible for that. In that sense, the constructor should call the member function to initialize a member data.
FuelGauge::FuelGauge(int f) { setFuel(f); }

FuelGauge::~FuelGauge() {}

int FuelGauge::getFuel() const { return fuel; }
void FuelGauge::setFuel(int f) {
  if (f >= 0 && f <= 15) {
    fuel = f;
  } else {
    throw invalid_argument("Fuel should be in range of 0 and 15");
  }
}

void FuelGauge::reportFuel() const {
  cout << "Fuel level: " << getFuel() << " gallons" << endl;
}

// Comment 3: We have to be carefull here so that invalid data (such as value 16) won't be input.
void FuelGauge::refillFuel() {
  if (getFuel() < 15) {
    fuel += 1;
  } else {
    cout << "The tank is full!" << endl;
  }
}

void FuelGauge::reduceFuel() {
  if (getFuel() > 0) {
    fuel -= 1;
  } else {
    cout << "The tank is empty!" << endl;
  }
}