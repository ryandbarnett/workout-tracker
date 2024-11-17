#pragma once
#include <vector>
#include <queue>
#include "Exercise.h"

using namespace std;

class Workout {
private:
    vector<Exercise> exerciseList;
    queue<Exercise> exerciseQueue;

    void refillQueue();

public:
    void addExercise(const Exercise& exercise);
    Exercise getCurrentExercise() const;
    void completeExercise();
    bool isComplete() const;
    void resetWorkout();
};

