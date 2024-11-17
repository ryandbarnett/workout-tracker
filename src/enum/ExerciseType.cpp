#include "../../include/enum/ExerciseType.h"
#include <iostream>

namespace ExerciseUtils {
    ExerciseType getExerciseTypeFromChoice(int choice) {
        switch (choice) {
        case 1: return ExerciseType::Endurance;
        case 2: return ExerciseType::Strength;
        case 3: return ExerciseType::Flexibility;
        case 4: return ExerciseType::Stability;
        case 5: return ExerciseType::Recovery;
        default:
            std::cout << "Invalid choice. Defaulting to Endurance.\n";
            return ExerciseType::Endurance;
        }
    }

    ExerciseType getExerciseTypeFromString(const std::string& typeStr) {
        if (typeStr == "Endurance") return ExerciseType::Endurance;
        if (typeStr == "Strength") return ExerciseType::Strength;
        if (typeStr == "Flexibility") return ExerciseType::Flexibility;
        if (typeStr == "Stability") return ExerciseType::Stability;
        if (typeStr == "Recovery") return ExerciseType::Recovery;

        std::cout << "Unknown exercise type: " << typeStr << ". Defaulting to Endurance.\n";
        return ExerciseType::Endurance;
    }
}
