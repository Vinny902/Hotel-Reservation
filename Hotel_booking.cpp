
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Structure to represent a hotel room
struct Room {
    int roomNumber;
    string type;
    bool available;
};

// Function to display available rooms
void displayAvailableRooms(const vector<Room>& rooms) {
    cout << "Available Rooms:\n";
    for (const auto& room : rooms) {
        if (room.available) {
            cout << "Room Number: " << room.roomNumber << " Type: " << room.type << endl;
        }
    }
    cout << endl;
}

// Function to process reservation
void reserveRoom(vector<Room>& rooms) {
    int roomChoice;
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

            // Display reservation details
            cout << "Room reserved successfully!\n";
            cout << "Reservation Details:\n";
            cout << "Room Number: " << room.roomNumber << " Type: " << room.type << endl;
            cout << "Check-in Date: " << currentDate->tm_mon + 1 << "/" << checkInDay << "/" << currentDate->tm_year + 1900 << endl;
            cout << "Check-out Date: " << currentDate->tm_mon + 1 << "/" << checkOutDay << "/" << currentDate->tm_year + 1900 << endl;
            break;
        }
    }
}

int main() {
    // Sample hotel rooms data
    vector<Room> rooms = {
        {101, "Single", true},
        {102, "Double", false},
        {103, "Single", true},
        {104, "Suite", true}
    };

    // Display available rooms
    displayAvailableRooms(rooms);

    // Reserve a room
    reserveRoom(rooms);

    return 0;
}
