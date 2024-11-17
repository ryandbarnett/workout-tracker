// #include "../../include/view/TrackerDisplay.h"
// #include "../../include/view/ExerciseDisplay.h"
// #include <iostream>

// using namespace std;

// namespace Display {
//     void displayExerciseLibrary(const Tracker& tracker) {
//         const auto& exercises = tracker.getExercises();
//         if (exercises.empty()) {
//             cout << "No exercises found." << endl;
//         }
//         else {
//             cout << "====== Exercise Library ======" << endl;
//             int index = 1;
//             for (const auto& exercise : exercises) {
//                 cout << index << ". ";
//                 displayExercise(exercise);
//                 ++index;
//             }
//         }
//     }
// }