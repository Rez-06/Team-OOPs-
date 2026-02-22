#include "Rental.h"
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
static const char* RENTAL_FILE = "rental_slots.txt";
static void loadBookings(map<string, int>& bookingSlots) {
    ifstream in(RENTAL_FILE);
    if (!in) return;
    string line;
    while (getline(in, line)) {
        size_t p = line.find('|');
        if (p == string::npos) continue;
        string slot = line.substr(0, p);
        int cnt = 0;
        try {
            cnt = stoi(line.substr(p + 1));
        } catch (...) {
            continue;
        }
        bookingSlots[slot] = cnt;
    }
}
static void saveBookings(const map<string, int>& bookingSlots) {
    ofstream out(RENTAL_FILE);
    if (!out) {
        cout << "File error: cannot write rental_slots.txt\n";
        return;
    }
    for (auto& it : bookingSlots) {
        out << it.first << "|" << it.second << "\n";
    }
}
Rental::Rental() {
    totalSlots = 4;
    baseOneHour = 150;
    baseHalfHour = 100;
    extraControllerHour = 50;
    extraControllerHalf = 30;
    loadBookings(bookingSlots);
}
bool Rental::isAvailable(string timeSlot) const {
    auto it = bookingSlots.find(timeSlot);
    int booked = (it == bookingSlots.end()) ? 0 : it->second;
    return booked < totalSlots;
}
double Rental::calculatePrice(int controllers, int minutes) const {
    if (controllers < 1 || controllers > 4) {
        throw invalid_argument("Controllers must be between 1 and 4");
    }
    if (!(minutes == 30 || minutes == 60)) {
        throw invalid_argument("Minutes must be 30 or 60");
    }
    double base = (minutes == 60) ? baseOneHour : baseHalfHour;
    int extra = 0;
    if (controllers > 2) extra = controllers - 2;
    double extraFee = 0.0;
    if (extra > 0) {
        if (minutes == 60) extraFee = extra * extraControllerHour;
        else extraFee = extra * extraControllerHalf;
    }
    return base + extraFee;
}
void Rental::bookSlot(string timeSlot, int controllers, int minutes, Register& reg) {
    if (timeSlot.empty()) {
        throw invalid_argument("Time slot cannot be empty");
    }
    if (!isAvailable(timeSlot)) {
        throw runtime_error("Selected time slot is fully booked");
    }
    double price = calculatePrice(controllers, minutes);
    bookingSlots[timeSlot]++;      
    saveBookings(bookingSlots);      
    string desc = "Slot " + timeSlot + " (" + to_string(controllers) + " ctrl, " + to_string(minutes) + " min)";
    reg.addTransaction("RENT", desc, price);
    cout << "Booked successfully. Price: " << price << " BDT\n";
}
void Rental::updatePricing() {
    cout << "\n--- Update Rental Pricing ---\n";
    cout << "Current:\n";
    cout << "1 hour base: " << baseOneHour << "\n";
    cout << "30 min base: " << baseHalfHour << "\n";
    cout << "Extra ctrl 1 hour: " << extraControllerHour << "\n";
    cout << "Extra ctrl 30 min: " << extraControllerHalf << "\n";
    cout << "\nEnter new base 1 hour price: ";
    cin >> baseOneHour;
    cout << "Enter new base 30 min price: ";
    cin >> baseHalfHour;
    cout << "Enter new extra controller 1 hour price: ";
    cin >> extraControllerHour;
    cout << "Enter new extra controller 30 min price: ";
    cin >> extraControllerHalf;
    cout << "Pricing updated.\n";
}
void Rental::updateSlots(int slots) {
    if (slots <= 0) {
        throw invalid_argument("Slots must be positive");
    }
    totalSlots = slots;
    cout << "Total slots updated to " << totalSlots << "\n";
}
