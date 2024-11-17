#pragma once
#include "ExerciseController.h"
#include "WorkoutController.h"
#include "../model/Tracker.h"

class Controller {
private:
    Tracker tracker;
    ExerciseController exerciseController;
    WorkoutController workoutController;

    void handleMenuChoice(int choice);
    bool shouldContinueMainMenu();

public:
    Controller();
    void run();
};

