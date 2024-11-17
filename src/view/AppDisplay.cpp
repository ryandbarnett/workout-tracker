#include "../../include/view/AppDisplay.h"
#include <iostream>

using namespace std;

namespace Display {
    void displayMainMenu() {
        cout << "====== Workout Tracker ======" << endl;
        cout << "1. Add Exercise" << endl;
        cout << "2. View Exercise Library" << endl;
        cout << "3. Delete Exercise" << endl;
        cout << "4. Update Exercise" << endl;
        cout << "5. Create New Workout" << endl;
        cout << "6. Add Exercise To Workout" << endl;
        cout << "7. View Workouts" << endl;
        cout << "8. Start Workout" << endl;
        cout << "9. Reset Workout" << endl;
        cout << "10. Exit" << endl;
        cout << "Please select an option: ";
    }

    void displayExitMessage() {
        cout << "Exiting the program. Goodbye!" << endl;
    }

    void displayInvalidChoiceMessage() {
        cout << "Invalid choice. Please try again." << endl;
    }

    int getUserMenuChoice() {
        int choice;
        cin >> choice;
        return choice;
    }
}
