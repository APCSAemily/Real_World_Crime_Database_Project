#include "ParseCSV.h"
#include <fstream>
#include <iostream>
#include <sstream>

CrimeData parseLine(const std::string &line) {
    CrimeData c;                // create crime object
    std::stringstream ss(line); // instantiate stringstream
    std::string cell;           // each of the cell is a string
    std::vector<std::string> columns; // holds all of the column names

    // more efficient way of parsing csv files
    while (std::getline(ss, cell, ',')) {
        columns.push_back(cell); // now with a vector of all columns we can extract the one we need
    }

    // check to prevent against errors 
    if (columns.size() >= 4) {
        c.OFFENSE_DESCRIPTION = columns[3]; // the 4th column (index 3) is the offense description
    }

    return c;
}

// pretty much what was in main function before
std::vector<CrimeData> returnCrimeData(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    std::vector<CrimeData> crimes;

    // skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        CrimeData c = parseLine(line);
        crimes.push_back(c);
    }

    file.close();
}