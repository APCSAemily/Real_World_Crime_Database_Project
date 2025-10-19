#include "ParseCSV.h"
#include <fstream>
#include <iostream>

Crime parseLine(const string &line) {
    Crime c;               // create crime object
    stringstream ss(line); // instantiate stringstream
    string cell;           // each of the cell is a string

    getline(ss, c.INCIDENT_NUMBER, ',');
    getline(ss, c.OFFENSE_CODE, ',');
    getline(ss, c.OFFENSE_CODE_GROUP, ',');
    getline(ss, c.OFFENSE_DESCRIPTION, ',');
    getline(ss, c.DISTRICT, ',');
    getline(ss, c.REPORTING_AREA, ',');
    getline(ss, c.SHOOTING, ',');
    getline(ss, c.OCCURRED_ON_DATE, ',');

    getline(ss, cell, ',');
    c.YEAR = safeStoi(cell);
    getline(ss, cell, ',');
    c.MONTH = safeStoi(cell);
    getline(ss, cell, ',');
    // cout << "DAY_OF_WEEK raw: " << "[" << cell << "]" << endl;
    c.DAY_OF_WEEK = trim(cell);
    getline(ss, cell, ',');
    // cout << "HOUR raw: " << "[" << cell << "]" << endl;
    c.HOUR = safeStoi(trim(cell));

    getline(ss, c.UCR_PART, ',');
    getline(ss, c.STREET, ',');
    getline(ss, cell, ',');
    c.Lat = safeStod(cell);
    getline(ss, cell, ',');
    c.Long = safeStod(cell);

    // read rest of the line as Location
    getline(ss, c.Location);
    return c;
}

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