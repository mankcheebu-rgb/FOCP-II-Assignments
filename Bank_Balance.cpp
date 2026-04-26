#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<int, long long> balance;

public:
    bool create(int userID, long long amount) {
        if (balance.find(userID) == balance.end()) {
            balance[userID] = amount;
            return true; // new account created
        } else {
            balance[userID] += amount;
            return false; // already existed
        }
    }

    bool debit(int userID, long long amount) {
        if (!balance.count(userID) || balance[userID] < amount) {
            return false;
        }
        balance[userID] -= amount;
        return true;
    }

    bool credit(int userID, long long amount) {
        if (!balance.count(userID)) {
            return false;
        }
        balance[userID] += amount;
        return true;
    }

    long long getBalance(int userID) {
        if (!balance.count(userID)) {
            return -1;
        }
        return balance[userID];
    }
};

int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cout << "\nEnter query (CREATE / DEBIT / CREDIT / BALANCE): ";
        cin >> query;

        if (query == "CREATE") {
            int X;
            long long Y;
            cout << "Enter user ID and amount: ";
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "DEBIT") {
            int X;
            long long Y;
            cout << "Enter user ID and amount: ";
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "CREDIT") {
            int X;
            long long Y;
            cout << "Enter user ID and amount: ";
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "BALANCE") {
            int X;
            cout << "Enter user ID: ";
            cin >> X;
            cout << bank.getBalance(X) << "\n";
        }
        else {
            cout << "Invalid query\n";
        }
    }

    return 0;
}