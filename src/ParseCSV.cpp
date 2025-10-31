#include "ParseCSV.h"
#include <fstream>
#include <iostream>
#include <sstream>

// the number that our heap will prioritize based on
int getSeverityScore(const std::string &OFFENSE_CODE_GROUP) {
    // there is no murder/homicide data and the shooting category is all null values
    if (OFFENSE_CODE_GROUP == "Robbery" || OFFENSE_CODE_GROUP == "Residential Burglary" || OFFENSE_CODE_GROUP == "Simple Assault" || OFFENSE_CODE_GROUP == "Fire Related Reports") {
        return 15;
    }
    if (OFFENSE_CODE_GROUP == "Auto Theft" || OFFENSE_CODE_GROUP == "Drug Violation" || OFFENSE_CODE_GROUP == "Ballistics") {
        return 10;
    }
    if (OFFENSE_CODE_GROUP == "Larceny" || OFFENSE_CODE_GROUP == "Larceny From Motor Vehicle" || OFFENSE_CODE_GROUP == "Vandalism" ||
        OFFENSE_CODE_GROUP == "Restraining Order Violations") {
        return 5;
    }
    if (OFFENSE_CODE_GROUP == "Harassment" || OFFENSE_CODE_GROUP == "Verbal Disputes" || OFFENSE_CODE_GROUP == "Property Lost" ||
        OFFENSE_CODE_GROUP == "Investigate Property") {
        return 2;
    }

    // for all others
    return 1;
}

Crime parseLine(const std::string &line) {
    Crime c;                          // create crime object
    std::stringstream ss(line);       // instantiate stringstream
    std::string cell;                 // each of the cell is a string
    std::vector<std::string> columns; // holds all of the column names

    // more efficient way of parsing csv files
    while (std::getline(ss, cell, ',')) {
        columns.push_back(cell); // now with a vector of all columns we can extract the one we need
    }

    // check to prevent against errors
    if (columns.size() >= 3) {
        c.OFFENSE_CODE_GROUP = columns[2]; // the 3rd column (index 2) is the offense code OFFENSE_CODE_GROUP
    }

    return c;
}

// pretty much what was in main function before
std::vector<Crime> returnCrimeData(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    std::vector<Crime> crimes;

    // skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        Crime c = parseLine(line);
        crimes.push_back(c);
    }

    file.close();
}