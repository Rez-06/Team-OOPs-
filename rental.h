
#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include <map>
#include "Register.h"
using namespace std;

class Rental {
private:
    int totalSlots; // default 4
    map<string, int> bookingSlots;

    double baseOneHour;
    double baseHalfHour;
    double extraControllerHour;
    double extraControllerHalf;

public:
    Rental();

    bool isAvailable(string timeSlot) const;
    double calculatePrice(int controllers, int minutes) const;
    void bookSlot(string timeSlot, int controllers, int minutes, Register& reg);

    void updatePricing();
    void updateSlots(int slots);
};

#endif
