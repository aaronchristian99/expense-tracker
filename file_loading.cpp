#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Expense.h"

using namespace std;

vector<Expense> load_file(string filename) {
    
    ifstream file(filename);
    vector<Expense> expenses;
    string line;

    // Description, Amount, Day , Month, Year\n 
    while (getline(file, line)){
        int description_end = line.find(",");
        string description = line.substr(0, description_end);

        int amount_end = line.find(",", description_end);
        cout << line.substr(description_end + 2, amount_end - 2) << endl;
        double amount = stod(line.substr(description_end + 2, amount_end - 2));

        int day_end = line.find(",", amount_end);
        int day = stoi(line.substr(amount_end + 2, day_end - 2));

        int month_end = line.find(",", day_end);
        int month = stoi(line.substr(day_end + 2, month_end - 2));

        int year = stoi(line.substr(month_end + 2));

        expenses.push_back(Expense(description, amount, day, month, year));
    }

    return expenses;

}

int main (){
    vector<Expense> vi = load_file("test.txt");
    for(auto i : vi){
        cout << i.toString();
    }
    
}
