#include "../../include/model/Workout.h"

void Workout::addExercise(const Exercise& exercise) {
    exerciseList.push_back(exercise);
    exerciseQueue.push(exercise);
}

Exercise Workout::getCurrentExercise() const {
    return exerciseQueue.front();
}

void Workout::completeExercise() {
    exerciseQueue.pop();
}

bool Workout::isComplete() const {
    return exerciseQueue.empty();
}

void Workout::resetWorkout() {
    while (!exerciseQueue.empty()) {
        exerciseQueue.pop();
    }
    refillQueue();
}

void Workout::refillQueue() {
    for (const auto& exercise : exerciseList) {
        exerciseQueue.push(exercise);
    }
}