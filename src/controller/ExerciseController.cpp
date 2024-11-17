#include "../../include/controller/ExerciseController.h"
#include "../../include/view/ExerciseDisplay.h"
#include "../../include/view/AppDisplay.h"
#include "../../include/enum/ExerciseType.h"
#include <iostream>
#include <string>

using namespace std;

ExerciseController::ExerciseController(Tracker& tracker) : tracker(tracker) {}

string ExerciseController::getExerciseNameFromUser() const {
    Display::promptExerciseName();
    cin.ignore();
    string name;
    getline(cin, name);
    return name;
}

ExerciseType ExerciseController::getExerciseTypeFromUser() const {
    Display::displayExerciseTypeOptions();
    int choice = Display::getUserMenuChoice();
    return ExerciseUtils::getExerciseTypeFromChoice(choice);
}

int ExerciseController::getExerciseDurationFromUser() const {
    Display::promptExerciseDuration();
    int duration;
    cin >> duration;
    return duration;
}

int ExerciseController::getExerciseNumberFromUser() const {
    return Display::promptExerciseNumber();
}

void ExerciseController::addExercise() {
    string name = getExerciseNameFromUser();
    ExerciseType type = getExerciseTypeFromUser();
    int duration = getExerciseDurationFromUser();

    Exercise exercise(name, duration, type);
    tracker.createExercise(exercise);
    Display::displayExerciseAddedMessage();
}

void ExerciseController::updateExercise() {
    Display::displayExerciseLibrary(tracker);
    int choice = Display::promptExerciseNumber("Enter the number of the exercise to update: ");

    if (tracker.hasExercise(choice - 1)) {
        Display::displayUpdatePrompt();

        string name = getExerciseNameFromUser();
        ExerciseType type = getExerciseTypeFromUser();
        int duration = getExerciseDurationFromUser();

        Exercise updatedExercise(name, duration, type);
        tracker.updateExercise(choice - 1, updatedExercise);
        cout << "Exercise updated successfully." << endl;
    }
    else {
        Display::displayInvalidExerciseNumberMessage();
    }
}

void ExerciseController::deleteExercise() {
    Display::displayExerciseLibrary(tracker);
    int choice = Display::promptExerciseNumber("Enter the number of the exercise to delete: ");

    if (tracker.deleteExercise(choice - 1)) {
        cout << "Exercise deleted successfully." << endl;
    } else {
        Display::displayInvalidExerciseNumberMessage();
    }
}
