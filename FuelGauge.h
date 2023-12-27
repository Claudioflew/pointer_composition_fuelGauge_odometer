#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge {
public:
  FuelGauge(int);
  ~FuelGauge();

  // Comment 1: We don't want to forget to add const keyword to a function which is not supposed to change any member data.
  int getFuel() const;
  void setFuel(int);
  void reportFuel() const;
  void refillFuel();
  void reduceFuel();

private:
  int fuel;
};


#endif
