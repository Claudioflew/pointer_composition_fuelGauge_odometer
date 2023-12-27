#include "Koichi_Nakata_FuelGauge.h"
#include "Koichi_Nakata_Odometer.h"
#include <iostream>
#include <string>
using namespace std;

int chooseMenu();
void const reportStatus(Odometer&, FuelGauge&);

int main() {
  // Comment 9: We want to pass the address of FuelGauge object here, or its pointer.
  FuelGauge fuelCar1 = FuelGauge{15};
  Odometer odoCar1 = Odometer{&fuelCar1, 0};

  cout << "\nInitial status:\n----------------------" << endl;
  reportStatus(odoCar1, fuelCar1);

  int choice = chooseMenu();
  while (choice != 4) {
    if (choice == 1) {
      int mileToRun;
      cout << "\nHow many miles do you want to run the car?\nEnter an integer here: ";
      cin >> mileToRun;
      cout << endl;
      for (int i = 0; i < mileToRun; i++) {
        odoCar1.run();
        reportStatus(odoCar1, fuelCar1);
      }
    } else if (choice == 2) {
      int fuelToRefill;
      cout << "\nHow much fuel do you want to refill?\nEnter an integer here: ";
      cin >> fuelToRefill;
      cout << endl;
      for (int i = 0; i < fuelToRefill; i++) {
        fuelCar1.refillFuel();
        reportStatus(odoCar1, fuelCar1);
      }
    } else {
      cout << "\nCurrent status:\n----------------------" << endl;
      reportStatus(odoCar1, fuelCar1);
    }
    choice = chooseMenu();
  }
  cout << "\nGood bye! Thank you for using this program." << endl;
}

int chooseMenu() {
  int choice;
  cout << "\t***Car Operation Menu***" << endl;
  cout << "\t1) Run the car\n\t2) Refill the tank" << endl;
  cout << "\t3) Report status\n\t4) Quit" << endl;
  cout << "\nPlease enter your choice here: ";
  cin >> choice;
  while (choice < 1 || choice > 4) {
    cout << "Invalid entry.. Please enter an integer between 1 to 4: ";
    cin >> choice;
  }
  return choice;
}

// Comment 10: We don't forget the keyword const when a function won't change any value.
void const reportStatus(Odometer& odoObj, FuelGauge& fuelObj) {
  odoObj.reportMile();
  fuelObj.reportFuel();
  cout << endl;
}