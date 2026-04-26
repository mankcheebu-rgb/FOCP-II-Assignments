#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, int> movieCapacity;
    unordered_map<int, unordered_set<int>> bookings;
    int defaultCapacity = 5;

public:
    bool book(int customerID, int movieID) {
        if (bookings[movieID].count(customerID)) return false;
        if ((int)bookings[movieID].size() >= getCapacity(movieID)) return false;
        bookings[movieID].insert(customerID);
        return true;
    }

    bool cancel(int customerID, int movieID) {
        if (!bookings[movieID].count(customerID)) return false;
        bookings[movieID].erase(customerID);
        return true;
    }

    bool isBooked(int customerID, int movieID) {
        return bookings[movieID].count(customerID);
    }

    int availableTickets(int movieID) {
        return getCapacity(movieID) - (int)bookings[movieID].size();
    }

private:
    int getCapacity(int movieID) {
        if (!movieCapacity.count(movieID)) {
            movieCapacity[movieID] = defaultCapacity;
        }
        return movieCapacity[movieID];
    }
};

int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    MovieTicket system;

    while (Q--) {
        string query;
        cout << "Enter query type (BOOK / CANCEL / IS_BOOKED / AVAILABLE_TICKETS): ";
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cout << "Enter customer ID and movie ID: ";
            cin >> X >> Y;
            cout << (system.book(X, Y) ? "true" : "false") << '\n';
        } 
        else if (query == "CANCEL") {
            int X, Y;
            cout << "Enter customer ID and movie ID: ";
            cin >> X >> Y;
            cout << (system.cancel(X, Y) ? "true" : "false") << '\n';
        } 
        else if (query == "IS_BOOKED") {
            int X, Y;
            cout << "Enter customer ID and movie ID: ";
            cin >> X >> Y;
            cout << (system.isBooked(X, Y) ? "true" : "false") << '\n';
        } 
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cout << "Enter movie ID: ";
            cin >> Y;
            cout << system.availableTickets(Y) << '\n';
        } 
        else {
            cout << "Invalid query\n";
        }
    }

    return 0;
}