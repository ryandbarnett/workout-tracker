#include "../../include/utilities/TrackerFileIO.h"
#include "../../include/view/ExerciseDisplay.h"
#include "../../include/enum/ExerciseType.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void TrackerFileIO::loadExercisesFromFile(Tracker& tracker, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream stream(line);
        string name, typeStr;
        int duration;

        getline(stream, name, ',');
        getline(stream, typeStr, ',');
        stream >> duration;

        ExerciseType type = ExerciseUtils::getExerciseTypeFromString(typeStr);

        tracker.createExercise(Exercise(name, duration, type));
    }

    file.close();
}

void TrackerFileIO::saveExercisesToFile(const Tracker& tracker, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return;
    }

    for (const auto& exercise : tracker.getExercises()) {
        file << exercise.getName() << ","
            << Display::exerciseTypeToString(exercise.getType()) << ","
            << exercise.getDuration() << endl;
    }

    file.close();
}