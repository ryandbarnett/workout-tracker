#include "../../include/controller/WorkoutController.h"
#include "../../include/view/ExerciseDisplay.h"
#include "../../include/view/WorkoutDisplay.h"
#include <iostream>

using namespace std;

WorkoutController::WorkoutController(Tracker& tracker) : tracker(tracker) {}

Workout* WorkoutController::getWorkout(const string& workoutName) {
    Workout* workout = tracker.getWorkout(workoutName);
    if (!workout) {
        Display::displayWorkoutNotFoundMessage();
    }
    return workout;
}

void WorkoutController::createWorkout() {
    string workoutName = Display::promptWorkoutName();

    if (tracker.getWorkout(workoutName)) {
        Display::displayWorkoutAlreadyExistsMessage(workoutName);
        return;
    }

    tracker.createWorkout(workoutName);
    Display::displayWorkoutCreatedMessage(workoutName);
}

void WorkoutController::addExerciseToWorkout() {
    string workoutName = Display::promptWorkoutName();
    Workout* workout = getWorkout(workoutName);
    if (!workout) return;

    Display::displayExerciseLibrary(tracker);

    int exerciseIndex = Display::promptExerciseNumber();
    Exercise* exercise = tracker.getExercise(exerciseIndex - 1);
    if (!exercise) {
        Display::displayInvalidExerciseIndexMessage();
        return;
    }

    workout->addExercise(*exercise);
    Display::displayExerciseAddedToWorkoutMessage(exercise->getName(), workoutName);
}

void WorkoutController::startWorkout(const string& workoutName) {
    Workout* workout = getWorkout(workoutName);
    if (!workout) return;

    Display::displayStartWorkoutMessage(workoutName);

    while (!workout->isComplete()) {
        Exercise currentExercise = workout->getCurrentExercise();
        Display::displayCurrentExercise(currentExercise);
        workout->completeExercise();
    }
    Display::displayWorkoutCompleteMessage(workoutName);
}

void WorkoutController::resetWorkout(const string& workoutName) {
    Workout* workout = getWorkout(workoutName);
    if (!workout) return;

    workout->resetWorkout();
    Display::displayWorkoutResetMessage(workoutName);
}

void WorkoutController::viewWorkouts() {
    Display::displayWorkouts(tracker);
}
