#pragma once
#include "../model/Workout.h"
#include "../model/Exercise.h"
#include "../model/Tracker.h"
#include <string>

using namespace std;

namespace Display {
    string promptWorkoutName();
    void displayWorkoutCreatedMessage(const string& workoutName);
    void displayStartWorkoutMessage(const string& workoutName);
    void displayCurrentExercise(const Exercise& exercise);
    void displayWorkoutCompleteMessage(const string& workoutName);
    void displayWorkoutResetMessage(const string& workoutName);
    void displayWorkoutNotFoundMessage();
    void displayInvalidExerciseIndexMessage();
    void displayWorkoutAlreadyExistsMessage(const string& workoutName);
    void displayExerciseAddedToWorkoutMessage(const string& exerciseName, const string& workoutName);
    void displayWorkouts(const Tracker& tracker);
}

