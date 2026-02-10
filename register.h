
#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Transaction {
    string type;       // FOOD / RENT / CASHOUT
    string description;
    double amount;
    time_t timestamp;
};

class Register {
private:
    vector<Transaction> history;
    double totalCash;

public:
    Register();

    void addTransaction(string type, string desc, double amount);
    void cashOut(double amount, string reason);

    double getTotalCash() const;

    void viewHistory() const;
    void showBestSellingFood() const;
    void showMostRentedGame() const;
    void showIncomeSummary() const;
};

#endif
