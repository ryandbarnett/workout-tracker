#pragma once
#include "../model/Tracker.h"
#include "../model/Workout.h"

using namespace std;

class WorkoutController {
private:
    Tracker& tracker;
    Workout* getWorkout(const string& workoutName);

public:
    WorkoutController(Tracker& tracker);

    void createWorkout();
    void addExerciseToWorkout();
    void startWorkout(const string& workoutName);
    void resetWorkout(const string& workoutName);
    void viewWorkouts();
};
