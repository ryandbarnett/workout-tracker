#pragma once
#include <string>

using namespace std;

enum class ExerciseType {
    Endurance,
    Strength,
    Flexibility,
    Stability,
    Recovery
};

namespace ExerciseUtils {
    ExerciseType getExerciseTypeFromChoice(int choice);
    ExerciseType getExerciseTypeFromString(const string& typeStr);
}
