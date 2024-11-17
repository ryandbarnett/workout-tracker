#pragma once
#include "../model/Tracker.h"
#include "../model/Exercise.h"
#include "../enum/ExerciseType.h"
#include <string>

class ExerciseController {
private:
    Tracker& tracker;

    std::string getExerciseNameFromUser() const;
    ExerciseType getExerciseTypeFromUser() const;
    int getExerciseDurationFromUser() const;
    int getExerciseNumberFromUser() const;

public:
    ExerciseController(Tracker& tracker);

    void addExercise();
    void updateExercise();
    void deleteExercise();
};