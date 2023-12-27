#ifndef ODOMETER_H
#define ODOMETER_H

#include "Koichi_Nakata_FuelGauge.h"

class Odometer {
public:
  Odometer(FuelGauge*, int);
  ~Odometer();

  int getMile() const;
  void setMile(int);
  void reportMile() const;

  void useFuel();
  void run();

  void changeAdjustmentMile();

// Comment 4: FuelGauge pointer variable is just passed to have an Odometer object can work with it. This is not a composition relationship. The odometer object just has a piece of paper written FuelGauge object's address, and it can interact with the object.
private:
  int mile{0};
  FuelGauge* gaugePtr;
  int adjustmentMile{24};
};

#endif
