#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Passenger {
    int survived;
    string sex;
    float age;
};

int main() {
    ifstream file("titanic.csv");
    string line, word;
    vector<Passenger> passengers;

    // Skip header
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        while (getline(ss, word, ',')) {
            row.push_back(word);
        }

        Passenger p;
        p.survived = stoi(row[1]);
        p.sex = row[2];
        p.age = row[3].empty() ? -1 : stof(row[3]);
        passengers.push_back(p);
    }

    // EDA
    int total = passengers.size();
    int survived = 0, male = 0, female = 0;

    for (auto &p : passengers) {
        if (p.survived == 1) survived++;
        if (p.sex == "male") male++;
        else if (p.sex == "female") female++;
    }

    cout << "Total Passengers: " << total << endl;
    cout << "Survived: " << survived << " (" << (100.0 * survived / total) << "%)" << endl;
    cout << "Male Passengers: " << male << endl;
    cout << "Female Passengers: " << female << endl;

    return 0;
}