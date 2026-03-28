#include "Register.h"
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
static const char *TRANSACTION_FILE = "transactions.txt";
static string formatTime(time_t t)
{
    tm *lt = localtime(&t);
    if (!lt)
        return "unknown-time";
    ostringstream oss;
    oss << put_time(lt, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
static bool parseLine(const string &line, Transaction &tx)
{
    size_t p1 = line.find('|');
    size_t p2 = line.find('|', p1 == string::npos ? 0 : p1 + 1);
    size_t p3 = line.find('|', p2 == string::npos ? 0 : p2 + 1);
    if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
        return false;
    tx.type = line.substr(0, p1);
    tx.description = line.substr(p1 + 1, p2 - (p1 + 1));
    try
    {
        tx.amount = stod(line.substr(p2 + 1, p3 - (p2 + 1)));
        long long ts = stoll(line.substr(p3 + 1));
        tx.timestamp = (time_t)ts;
    }
    catch (...)
    {
        return false;
    }
    return true;
}
static void appendToFile(const Transaction &tx)
{
    ofstream out(TRANSACTION_FILE, ios::app);
    if (!out)
    {
        cout << "File error: cannot write transactions.txt\n";
        return;
    }
    out << tx.type << "|" << tx.description << "|" << tx.amount << "|" << (long long)tx.timestamp << "\n";
}
Register::Register()
{
    totalCash = 0.0;

    ifstream in(TRANSACTION_FILE);
    if (!in)
    {
        return;
    }
    string line;
    while (getline(in, line))
    {
        Transaction tx;
        if (parseLine(line, tx))
        {
            history.push_back(tx);
            totalCash += tx.amount;
        }
    }
}
void Register::addTransaction(string type, string desc, double amount)
{
    if (type.empty())
    {
        throw invalid_argument("Transaction type cannot be empty");
    }
    if (desc.empty())
    {
        desc = "No description";
    }
    if (amount == 0.0)
    {
        throw invalid_argument("Transaction amount cannot be 0");
    }
    Transaction tx;
    tx.type = type;
    tx.description = desc;
    tx.amount = amount;
    tx.timestamp = time(nullptr);
    history.push_back(tx);
    totalCash += amount;
    appendToFile(tx);
    cout << "Transaction added: " << type << " | " << desc << " | " << amount << " BDT\n";
}
void Register::cashOut(double amount, string reason)
{
    if (amount <= 0)
    {
        throw invalid_argument("Cashout amount must be positive");
    }
    if (amount > totalCash)
    {
        throw runtime_error("Not enough cash in register");
    }
    if (reason.empty())
        reason = "Cash out";
    addTransaction("CASHOUT", reason, -amount);
}
double Register::getTotalCash() const
{
    return totalCash;
}
void Register::viewHistory() const
{
    if (history.empty())
    {
        cout << "No transactions found.\n";
        return;
    }
    cout << "\n====== Transaction History ======\n";
    for (int i = 0; i < (int)history.size(); i++)
    {
        const Transaction &tx = history[i];
        cout << i + 1 << ". [" << tx.type << "] " << tx.description << " | " << tx.amount << " BDT | " << formatTime(tx.timestamp) << "\n";
    }
}
void Register::showBestSellingFood() const
{
    if (history.empty())
    {
        cout << "No transactions.\n";
        return;
    }
    map<string, int> cnt;
    map<string, double> income;
    for (const auto &tx : history)
    {
        if (tx.type == "FOOD")
        {
            cnt[tx.description]++;
            income[tx.description] += tx.amount;
        }
    }
    if (cnt.empty())
    {
        cout << "No FOOD transactions found.\n";
        return;
    }
    string best;
    int bestCount = -1;
    for (auto &it : cnt)
    {
        if (it.second > bestCount)
        {
            bestCount = it.second;
            best = it.first;
        }
    }
    cout << "Best-selling food: " << best << " (sold " << bestCount << " times, income " << income[best] << " BDT)\n";
}
void Register::showMostRentedGame() const
{
    if (history.empty())
    {
        cout << "No transactions.\n";
        return;
    }
    map<string, int> cnt;
    map<string, double> income;
    for (const auto &tx : history)
    {
        if (tx.type == "RENT")
        {
            cnt[tx.description]++;
            income[tx.description] += tx.amount;
        }
    }
    if (cnt.empty())
    {
        cout << "No RENT transactions found.\n";
        return;
    }
    string best;
    int bestCount = -1;
    for (auto &it : cnt)
    {
        if (it.second > bestCount)
        {
            bestCount = it.second;
            best = it.first;
        }
    }
    cout << "Most rented: " << best << " (rented " << bestCount << " times, income " << income[best] << " BDT)\n";
}
void Register::showIncomeSummary() const
{
    double foodIncome = 0.0;
    double rentIncome = 0.0;
    double cashoutTotal = 0.0;
    for (const auto &tx : history)
    {
        if (tx.type == "FOOD")
            foodIncome += tx.amount;
        else if (tx.type == "RENT")
            rentIncome += tx.amount;
        else if (tx.type == "CASHOUT")
            cashoutTotal += (-tx.amount); // tx.amount negative
    }
    cout << "\n====== Income Summary ======\n";
    cout << "Food income : " << foodIncome << " BDT\n";
    cout << "Rent income : " << rentIncome << " BDT\n";
    cout << "Cashout     : " << cashoutTotal << " BDT\n";
    cout << "Total cash  : " << totalCash << " BDT\n";
}