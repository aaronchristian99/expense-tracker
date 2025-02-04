#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Expense.cpp"

using namespace std;

vector<Expense> load_file(string filename) {
    ifstream file(filename);
    vector<Expense> expenses;

    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return expenses;  // Return an empty vector
    }

    string line;

    // Description, Amount, Day , Month, Year\n
    getline(file, line); //get first line
    while (getline(file, line)) {
        stringstream ss(line);
        string description, amountStr, dayStr, monthStr, yearStr;

        // Extract CSV values
        getline(ss, description, ',');
        getline(ss, amountStr, ',');
        getline(ss, dayStr, ',');
        getline(ss, monthStr, ',');
        getline(ss, yearStr, ',');

        try {
            double amount = stod(amountStr);
            int day = stoi(dayStr);
            int month = stoi(monthStr);
            int year = stoi(yearStr);

            expenses.push_back(Expense(description, amount, day, month, year));
        } catch (const exception& e) {
            cerr << "ERROR parsing line: " << line << " | " << e.what() << endl;
        }
    }

    file.close();

    return expenses;
}
