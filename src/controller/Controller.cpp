#include "../../include/controller/Controller.h"
#include "../../include/view/AppDisplay.h"
#include "../../include/view/ExerciseDisplay.h"
#include "../../include/view/WorkoutDisplay.h"
#include "../../include/utilities/TrackerFileIO.h"
#include "../../include/utilities/Utilities.h"
#include "../../include/enum/MenuOption.h"
#include <iostream>

using namespace std;

Controller::Controller() : exerciseController(tracker), workoutController(tracker) {}

void Controller::handleMenuChoice(int choice) {
    switch (choice) {
        case ADD_EXERCISE: exerciseController.addExercise(); clearScreen(); break;
        case VIEW_LIBRARY: clearScreen(); Display::displayExerciseLibrary(tracker); break;
        case UPDATE_EXERCISE: exerciseController.updateExercise(); clearScreen(); break;
        case DELETE_EXERCISE: exerciseController.deleteExercise(); clearScreen(); break;
        case CREATE_WORKOUT: clearScreen(); workoutController.createWorkout(); break;
        case ADD_EXERCISE_TO_WORKOUT: clearScreen(); workoutController.addExerciseToWorkout(); break;
        case VIEW_WORKOUTS: clearScreen(); workoutController.viewWorkouts(); break;
        case START_WORKOUT: clearScreen(); workoutController.startWorkout(Display::promptWorkoutName()); break;
        case RESET_WORKOUT: clearScreen(); workoutController.resetWorkout(Display::promptWorkoutName()); break;
        case EXIT: Display::displayExitMessage(); break;
        default: Display::displayInvalidChoiceMessage();
    }
}

bool Controller::shouldContinueMainMenu() {
    Display::displayMainMenu();
    int choice = Display::getUserMenuChoice();
    handleMenuChoice(choice);
    return choice != EXIT;
}

void Controller::run() {
    TrackerFileIO::loadExercisesFromFile(tracker, "exercises.csv");

    while (shouldContinueMainMenu());

    TrackerFileIO::saveExercisesToFile(tracker, "exercises.csv");
}