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

int main(){
    return 0;
}