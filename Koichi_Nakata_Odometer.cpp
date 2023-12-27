#include "Koichi_Nakata_Odometer.h"
#include "Koichi_Nakata_FuelGauge.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Odometer::Odometer(FuelGauge* ptr, int m) : gaugePtr{ptr}, mile{m} {}

Odometer::~Odometer() {}

int Odometer::getMile() const { return mile; }
void Odometer::reportMile() const { cout << "Mileage: " << getMile() << endl; }

void Odometer::setMile(int m) { mile = m; }

// Comment 5: Because the Odometer object is passed a FuelGauge object's pointer, the handle to call its public member function has to be "->" here.
void Odometer::useFuel() { gaugePtr->reduceFuel(); }

void Odometer::changeAdjustmentMile() {
  adjustmentMile -= 8;
  if (adjustmentMile == 0) {
    adjustmentMile = 24;
  }
}

void Odometer::run() {
  // Comment 6: First, we need to check if there is fuel in the tank before running the car.
  if (gaugePtr->getFuel() == 0) {
    cout << "The tank is empty! You need to refill the tank." << endl;
  // Comment 7: If there is fuel in the tank, we can run the car by 1 mile. As the result, the cumulative mileage becomes the multiples of 24, it means the car consumes 1 gallon of fuel.
  } else {
    mile += 1;
    // Comment 8: We have to be careful after the cumulative mileage reaches 1,000,000. After that, the mile to use fuel will be 8 miles, 32 miles, 56 miles... So we need an adjustment here.
    if ((getMile() + adjustmentMile) % 24 == 0) {
      useFuel();
    }
    if (getMile() == 1000000) {
      setMile(0);
      changeAdjustmentMile();
    }
  }
}