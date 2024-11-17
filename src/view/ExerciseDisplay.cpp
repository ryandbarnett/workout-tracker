#include "../../include/view/ExerciseDisplay.h"
#include <iostream>

using namespace std;

namespace Display {
    void displayExercise(const Exercise& exercise) {
        cout << exercise.getName()
            << " - " << exerciseTypeToString(exercise.getType())
            << " - " << exercise.getDuration() << " minutes" << endl;
    }

    void displayExerciseLibrary(const Tracker& tracker) {
        const auto& exercises = tracker.getExercises();
        if (exercises.empty()) {
            cout << "No exercises found." << endl;
        }
        else {
            cout << "====== Exercise Library ======" << endl;
            int index = 1;
            for (const auto& exercise : exercises) {
                cout << index << ". ";
                displayExercise(exercise);
                ++index;
            }
        }
    }

    void displayExerciseTypeOptions() {
        std::cout << "Select Exercise Type:\n"
            << "1. Endurance\n"
            << "2. Strength\n"
            << "3. Flexibility\n"
            << "4. Stability\n"
            << "5. Recovery\n"
            << "Enter choice: ";
    }

    string exerciseTypeToString(ExerciseType type) {
        switch (type) {
        case ExerciseType::Endurance: return "Endurance";
        case ExerciseType::Strength: return "Strength";
        case ExerciseType::Flexibility: return "Flexibility";
        case ExerciseType::Stability: return "Stability";
        case ExerciseType::Recovery: return "Recovery";
        default: return "Unknown";
        }
    }

    void displayExerciseAddedMessage() {
        cout << "Exercise added successfully!" << endl;
    }

    void promptExerciseName() {
        cout << "Enter exercise name: ";
    }

    void promptExerciseDuration() {
        cout << "Enter duration (minutes): ";
    }

    int promptExerciseNumber(const std::string& message) {
        int choice;
        cout << message;
        cin >> choice;
        return choice;
    }

    void displayInvalidExerciseNumberMessage() {
        cout << "Invalid choice. Please enter a valid exercise number." << endl;
    }

    void displayUpdatePrompt() {
        cout << "Updating an existing exercise. Please enter the new details." << endl;
    }
}
