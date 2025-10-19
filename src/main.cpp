#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>

using namespace std;

string trim(const string& s) {
    string result = s;
    // remove leading whitespace and \r
    result.erase(result.begin(), find_if(result.begin(), result.end(),
        [](unsigned char ch){ return !isspace(ch) && ch != '\r'; }));
    // remove trailing whitespace and \r
    result.erase(find_if(result.rbegin(), result.rend(),
        [](unsigned char ch){ return !isspace(ch) && ch != '\r'; }).base(), result.end());
    return result;
}



int safeStoi(const string& s){
    try{
        return stoi(s);
    }catch(...){
        return 0;
    }
}

double safeStod(const string& s){
    try{
        return stod(s);
    }catch(...){
        return 0.0;
    }
}

struct Crime{
    string INCIDENT_NUMBER;
    string OFFENSE_CODE;
    string OFFENSE_CODE_GROUP;
    string OFFENSE_DESCRIPTION;
    string DISTRICT;
    string REPORTING_AREA;
    string SHOOTING;
    string OCCURRED_ON_DATE;
    int YEAR;
    int MONTH;
    string DAY_OF_WEEK;
    int HOUR;
    string UCR_PART;
    string STREET;
    double Lat;
    double Long;
    string Location; // (quoted "(Lat, Long)"
};

Crime parseLine(const string& line){
    Crime c; //create crime object
    stringstream ss(line); //instantiate stringstream
    string cell; //each of the cell is a string

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

    //read rest of the line as Location
    getline(ss, c.Location);
    return c;
}


int main(){
    string filename = "crime.csv"; 
    ifstream file(filename);

    if(!file.is_open()){
        cerr << "Failed to open file: " << filename << endl;
        return 1;
    }

    string line;
    vector<Crime> crimes;

    //skip the header
    getline(file, line);


    while(getline(file,line)){
        Crime c = parseLine(line);
        crimes.push_back(c);
    }

    file.close();

    for(size_t i = 0; i < crimes.size() && i < 5; i++){
        cout << crimes[i].INCIDENT_NUMBER << " | "
        << crimes[i].OFFENSE_DESCRIPTION << " | "
        << crimes[i].HOUR << " | "
        << crimes[i].Location << endl;
    }
    return 0;
}