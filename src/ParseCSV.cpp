#include "ParseCSV.h"
#include <fstream>
#include <iostream>
#include <sstream>

Crime parseLine(const std::string &line) {
    Crime c;                // create crime object
    std::stringstream ss(line); // instantiate stringstream
    std::string cell;           // each of the cell is a string
    std::vector<std::string> columns; // holds all of the column names

    // more efficient way of parsing csv files
    while (std::getline(ss, cell, ',')) {
        columns.push_back(cell); // now with a vector of all columns we can extract the one we need
    }

    // check to prevent against errors 
    if (columns.size() >= 3) {
        c.OFFENSE_CODE_GROUP = columns[2]; // the 3rd column (index 2) is the offense code group
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