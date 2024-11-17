#include "../../include/view/ExerciseDisplay.h"
#include "../../include/view/WorkoutDisplay.h"
#include <iostream>

using namespace std;

namespace Display {

    string promptWorkoutName() {
        cout << "Enter the workout name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string name;
        getline(cin, name);
        return name;
    }

    void displayWorkoutCreatedMessage(const string& workoutName) {
        cout << "Workout '" << workoutName << "' created successfully.\n";
    }

    void displayStartWorkoutMessage(const string& workoutName) {
        cout << "Starting workout: " << workoutName << "\n";
    }

    void displayCurrentExercise(const Exercise& exercise) {
        cout << "Exercise: " << exercise.getName() << " - Duration: "
            << exercise.getDuration() << " minutes\n";
    }

    void displayWorkoutCompleteMessage(const string& workoutName) {
        cout << "Workout '" << workoutName << "' completed!\n";
    }

    void displayWorkoutResetMessage(const string& workoutName) {
        cout << "Workout '" << workoutName << "' has been reset.\n";
    }

    void displayWorkoutNotFoundMessage() {
        cout << "Workout not found.\n";
    }

    void displayInvalidExerciseIndexMessage() {
        cout << "Invalid exercise index.\n";
    }

    void displayWorkoutAlreadyExistsMessage(const string& workoutName) {
        cout << "Workout '" << workoutName << "' already exists.\n";
    }

    void displayExerciseAddedToWorkoutMessage(const string& exerciseName, const string& workoutName) {
        cout << "Exercise '" << exerciseName << "' added to workout '" << workoutName << "'.\n";
    }

    void displayWorkouts(const Tracker& tracker) {
        const auto& workouts = tracker.getWorkouts();

        if (workouts.empty()) {
            cout << "No workouts available.\n";
        }
        else {
            cout << "====== Workouts ======\n";
            for (const auto& pair : workouts) {
                cout << "Workout: " << pair.first << endl;
            }
        }
    }
}
