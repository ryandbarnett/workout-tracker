#pragma once
#include "../model/Tracker.h"
#include <string>

using namespace std;

namespace TrackerFileIO {
    void loadExercisesFromFile(Tracker& tracker, const string& filename);
    void saveExercisesToFile(const Tracker& tracker, const string& filename);
}
