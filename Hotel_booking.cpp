#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip> // For std::setw

using namespace std;

// Structure to represent a hotel room
struct Room {
    string roomNumber;
    string type;
    double pricePerNight;
    bool available;
};

// Function to display available rooms
void displayAvailableRooms(const vector<Room>& rooms) {
    cout << "Available Rooms:\n";
    cout << "------------------------------------------------------\n";
    cout << "| Room Number | Type      | Price per Night (USD) |\n";
    cout << "------------------------------------------------------\n";
    for (const auto& room : rooms) {
        if (room.available) {
            cout << "| " << std::setw(11) << room.roomNumber << " | " << std::setw(10) << room.type << " | " << std::setw(21) << room.pricePerNight << " |\n";
        }
    }
    cout << "------------------------------------------------------\n\n";
}

// Function to calculate total price based on number of days
double calculateTotalPrice(double pricePerNight, int numDays) {
    return pricePerNight * numDays;
}

// Function to process reservation
void reserveRoom(vector<Room>& rooms, const string& name) {
    string roomChoice;
    cout << "Enter the room number you want to reserve: ";
    cin >> roomChoice;

    // Check if the chosen room is available
    for (auto& room : rooms) {
        if (room.roomNumber == roomChoice && room.available) {
            room.available = false; // Mark the room as reserved

            // Get check-in and check-out dates
            time_t now = time(0);
            tm* currentDate = localtime(&now);
            int checkInDay, checkOutDay;
            cout << "Enter check-in day (1-31): ";
            cin >> checkInDay;
            cout << "Enter check-out day (1-31): ";
            cin >> checkOutDay;

            // Calculate number of days and total price
            int numDays = checkOutDay - checkInDay;
            double totalPrice = calculateTotalPrice(room.pricePerNight, numDays);

            // Display reservation details
            cout << "\n--------------------------\n";
            cout << "      Reservation Receipt      \n";
            cout << "--------------------------\n";
            cout << "Name: " << name << endl;
            cout << "Room Number: " << room.roomNumber << endl;
            cout << "Type: " << room.type << endl;
            cout << "Check-in Date: " << currentDate->tm_mon + 1 << "/" << checkInDay << "/" << currentDate->tm_year + 1900 << endl;
            cout << "Check-out Date: " << currentDate->tm_mon + 1 << "/" << checkOutDay << "/" << currentDate->tm_year + 1900 << endl;
            cout << "Total Price (USD): " << totalPrice << endl;
            cout << "--------------------------\n";
            break;
        }
    }
}

int main() {
    string name;
    char choice;
    cout << "Welcome to the Hotel Reservation System!\n";
    do {
        cout << "Please enter your name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);

        // Sample hotel rooms data
        vector<Room> rooms;
        for (int i = 1; i <= 120; ++i) {
            string roomNum;
            if (i < 10) {
                roomNum = "00" + to_string(i);
            } else if (i < 100) {
                roomNum = "0" + to_string(i);
            } else {
                roomNum = to_string(i);
            }
            string type;
            double pricePerNight;
            bool available = true;
            if (i % 7 == 0) {
                type = "A Suite";
                pricePerNight = 200.0;
                available = false; // Make some rooms unavailable
            } else if (i % 11 == 0) {
                type = "B Double";
                pricePerNight = 150.0;
            } else if (i % 3 == 0) {
                type = "Double";
                pricePerNight = 120.0;
            } else if (i % 5 == 0) {
                type = "Suite";
                pricePerNight = 180.0;
            } else {
                type = "Single";
                pricePerNight = 100.0;
            }
            rooms.push_back({roomNum, type, pricePerNight, available});
        }

        // Display available rooms
        displayAvailableRooms(rooms);

        // Reserve a room
        reserveRoom(rooms, name);

        cout << "\nDo you want to make another reservation? (y/n): ";
        cin >> choice;
    } while (choice != 'n' && choice != 'N');

    cout << "\nThank you for using the Hotel Reservation System. Have a great day!\n";

    return 0;
}
