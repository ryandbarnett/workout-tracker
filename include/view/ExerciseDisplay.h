#pragma once
#include "../model/Exercise.h"
#include "../model/Tracker.h"

namespace Display {
    void displayExercise(const Exercise& exercise);
    void displayExerciseLibrary(const Tracker& tracker);
    void displayExerciseTypeOptions();
    string exerciseTypeToString(ExerciseType type);
    void displayExerciseAddedMessage();
    void promptExerciseName();
    void promptExerciseDuration();
    int promptExerciseNumber(const std::string& message = "Enter the number of the exercise:");
    void displayInvalidExerciseNumberMessage();
    void displayUpdatePrompt();
}
