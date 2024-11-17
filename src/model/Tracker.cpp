#include "../../include/model/Tracker.h"
#include "../../include/view/WorkoutDisplay.h"
#include <algorithm>

using namespace std;

bool Tracker::isValidIndex(int index) const { return index >= 0 && index < exercises.size(); }

void Tracker::createExercise(const Exercise& exercise) {
    exercises.push_back(exercise);
    sortExercisesByName();
}

bool Tracker::deleteExercise(int index) {
    if (isValidIndex(index)) {
        exercises.erase(exercises.begin() + index);
        return true;
    }
    return false;
}

Exercise* Tracker::getExercise(int index) {
    if (!isValidIndex(index)) {
        return nullptr;
    }
    return &exercises.at(index);
}

bool Tracker::updateExercise(int index, const Exercise& updatedExercise) {
    if (isValidIndex(index)) {
        exercises[index] = updatedExercise;
        sortExercisesByName();
        return true;
    }
    return false;
}

bool Tracker::hasExercise(int index) const { return isValidIndex(index); }

const vector<Exercise>& Tracker::getExercises() const { return exercises; }

void Tracker::sortExercisesByName() {
    sort(exercises.begin(), exercises.end(), [](const Exercise& a, const Exercise& b) {
        return a.getName() < b.getName();
    });
}

void Tracker::createWorkout(const string& name) {
    if (workouts.find(name) != workouts.end()) {
        Display::displayWorkoutAlreadyExistsMessage(name);
        return;
    }

    workouts[name] = Workout();
    Display::displayWorkoutCreatedMessage(name);;
}

Workout* Tracker::getWorkout(const string& name) {
    auto it = workouts.find(name);
    if (it != workouts.end()) {
        return &it->second;
    }
    return nullptr;
}

const map<string, Workout>& Tracker::getWorkouts() const { return workouts; }
