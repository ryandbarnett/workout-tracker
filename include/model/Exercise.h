#pragma once
#include <string>
#include "../enum/ExerciseType.h"
using namespace std;

class Exercise {
private:
    string name;
    int duration;
    ExerciseType type;

public:
    Exercise(const string& name, int duration, ExerciseType type)
        : name(name), duration(duration), type(type) {}

    string getName() const { return name; }
    int getDuration() const { return duration; }
    ExerciseType getType() const { return type; }
};