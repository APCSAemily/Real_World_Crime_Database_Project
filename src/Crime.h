#pragma once
#include <string>

// since we only need the offense code group to determine how serious a crime is, all the extra information is unnecessary and uses up memory
struct Crime {
    std::string OFFENSE_CODE_GROUP;
    int severityScore = 0; // this is the value used to choose what crimes to prioritize in the heap implementations.
};