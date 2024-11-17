#pragma once
#include <vector>
#include <map>
#include "Exercise.h"
#include "Workout.h"
#include "../enum/ExerciseType.h"

using namespace std;

class Tracker {
private:
    vector<Exercise> exercises;
    map<string, Workout> workouts;

    bool isValidIndex(int index) const;

public:
    void createExercise(const Exercise& exercise);
    bool deleteExercise(int index);
    Exercise* getExercise(int index);
    bool updateExercise(int index, const Exercise& updatedExercise);

    bool hasExercise(int index) const;

    const vector<Exercise>& getExercises() const;
    void sortExercisesByName();

    void createWorkout(const string& name);
    Workout* getWorkout(const string& name);
    const map<string, Workout>& getWorkouts() const;
};
