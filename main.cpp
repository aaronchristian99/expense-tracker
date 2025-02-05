#include <iostream>
#include <fstream>
#include <vector> 
#include "Expense.cpp"
#include "file_loading.cpp"
#include "CategoryStaticData.h"

using namespace std;

/**
 * @brief Handles invalid user input in a loop.
 * Clears the input buffer and prompts the user to try again.
 */
void badCin(){
    cout << endl << "Invalid option. Please try again." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief User inputs the description for the expense.
 * Returns whatever the user inputs.
 */
string getExpenseDescription(){
    string desc;
    cout << "Enter the description of the expense: ";
    cin.ignore();
    getline(cin,desc);
    return desc;
}

/**
 * @brief User inputs the amount of the expense.
 * Returns whatever the user inputs and catches if the user enters a negative or wrong type.
 */
double getExpenseAmount(){
    double amount;
    while (true){
        cout << "Enter the amount of the expense: ";
        cin >> amount;
        if (amount > 0 ) return amount;
        badCin();
    }
}

/**
 * @brief Prompts the user to enter a valid date (day, month, year).
 *
 * Ensures that the input is within valid ranges for day (1-31), month (1-12), and a positive year.
 * Re-prompts the user until a valid date is provided.
 *
 * @return array<int, 3> An array containing day, month, and year in that order.
 */
array<int, 3> getDateFromUser() {
    int day, month, year;
    while (true) {
        cout << "Enter day (dd): ";
        cin >> day;
        cout << "Enter month (mm): ";
        cin >> month;
        cout << "Enter year (yyyy): ";
        cin >> year;

        if (day > 0 && day <= 31 && month > 0 && month <= 12 && year > 0) {
            return {day, month, year};
        } else {
            cout << "Invalid date. Please try again." << endl;
            badCin();
        }
    }
}

/**
* @brief Checks whether the sum of expenses of each category is the limit
* return void
*/
void checkExpenseLimits(vector<Expense> expenses) {
	unordered_map<int, double> categoryTotals;

    // Calculate total expenses for each category
    for (auto& expense : expenses) {
        categoryTotals[expense.getCategory()] += expense.getAmount();
    }

    // Compare each category total with the limit
    for (const auto& limit : categoryLimits) {
        int category = limit.first;
        double limitAmount = limit.second;
        double totalAmount = categoryTotals[category];

        if (totalAmount > limitAmount) {
            cout << "Warning: You have exceeded the budget for category " << categories.at(category) << "!" << endl;
        } else {
            cout << "Category " << categories.at(category) << " total expenses: $" << totalAmount
                 << " (within the limit of $" << limitAmount << ")" << endl;
        }
    }
}

int main() {
    vector<Expense> expenseList = load_file("expenses_init.csv");
    int numOfExpenses = expenseList.size();
    int option;
    string userInput;
    bool run = true;
    cout << "------------------ Expense Tracker ---------------------" << endl;

    while(run == true){
        int day, month, year, category;
        double amount;
        string desc;

        while(true) {
            cout << "1. Add Expense" << endl
                << "2. View Expenses" << endl
                << "3. Save to File" << endl
                << "4. Exit Program" << endl
                << "Enter your input: ";
            cin >> option;

            if(option >= 1 && option <= 4) {
                break;
            } else {
                badCin();
            }
        }

        switch(option){
            case 1: { //Add Expense
                string desc = getExpenseDescription();
                double amount = getExpenseAmount();
                array<int, 3> date;

                while(true) {
                    cout << "Would you like to use todays date? (y/n)." << endl;
                    cin >> userInput;

                    if(userInput == "y"){
                        date = getCurrentDate();
                        break;
                    } else if(userInput == "n"){
                        date = getDateFromUser();
                        break;
                    }else{
                        badCin();
                    }
                }

                while(true){
                    cout << "Please enter the category of the expense: " << endl << "The categories are: " << endl
                        << "1. Food" << endl << "2. Entertainment" << endl << "3. Bills" << endl << "4. Utilities" << endl;
                    cin >> category;

                    if (category >= 1 && category <= 4) {
                        ofstream tempFile;
                        tempFile.open("expenses_init.csv", ios::app);

                        if(!tempFile.is_open()){
                            cout << "File could not be opened" << endl;
                        }

                        Expense newExpense = Expense(desc, amount, category, date[0],date[1],date[2]);
                        expenseList.push_back(newExpense);
                        tempFile << endl << newExpense.toInitCsv();
                        cout << "Expense added." << endl;
                        numOfExpenses++;

                        tempFile.close();
                        break;
                    } else {
                        badCin();
                    }
                }

                checkExpenseLimits(expenseList);
            }

            case 2: //View Expenses
                if(expenseList.size() > 0){
                    cout << "List of expenses: " << endl;
                    for(int i = 0; i < numOfExpenses; i++){
                        cout << "ID: " << i + 1 << ", " << expenseList[i].toString() << endl;
                    }
                } else {
                    cerr << "No expenses are present." << endl;
                }

                checkExpenseLimits(expenseList);

                break;

            case 3: { //Save to File
                ofstream file("expenses_output.csv");

                if(!file.is_open()) {
                    cerr << "File could not be opened" << endl;
                    return 1;
                }

                file << "Description,Amount,Date" << endl;

                for (auto& expense : expenseList) {
                    file << expense.toCsv() << endl;
                }

                file.close();
                break;
            }

            case 4: //Exit Program
                cout << "Closing program.";
                run = false;
                break;
        }
    }
    
    return 0;
}
