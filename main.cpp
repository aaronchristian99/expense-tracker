#include <iostream>
#include <fstream>
#include <vector> 
#include "Expense.cpp"
#include "file_loading.cpp"

using namespace std;

int main() {
    vector<Expense> expenseList = load_file("expense_init.csv");
    int numOfExpenses = expenseList.size();
    int option;
    string userInput;
    bool run = true;
    cout << "------------------ Expense Tracker ---------------------" << endl;

    while(run == true){
        int day, month, year;
        float amount;
        string desc;

        cout << "1. Add Expense" << endl
             << "2. View Expenses" << endl
             << "3. Save to File" << endl
             << "4. Exit Program" << endl
             << "Enter your input: ";
        cin >> option;

        switch(option){ //i just threw everything in here to just set things up
            case 1: //Add Expense

                cout << "Please enter the description of the expense: " << endl;
                cin.ignore();
                getline(cin, desc);
                cout << "Please enter the amount of the expense: " << endl;
                cin >> amount;

                while(true){
                    cout << "Would you like to use todays date? (y/n)." << endl;
                    cin >> userInput;

                    if(userInput == "y"){
                        expenseList.push_back(Expense(desc,amount));
                        cout << "Expense added." << endl;;
                        numOfExpenses++;
                        break;

                    }else if(userInput == "n"){ //this is awful ik, could make some date parser later on
                        cout << "Please enter the day (dd)"  << endl;
                        cin >> day;
                        cout << "Please enter the month (mm)" << endl;
                        cin >> month;
                        cout << "Please enter the year (yyyy)" << endl;
                        cin >> year;
                        expenseList.push_back(Expense(desc,amount,day,month,year));
                        cout << "Expense added." << endl;
                        numOfExpenses++;
                        break;

                    }else{
                        cout << "Invalid option" << endl;
                    }
                }
                break;

            case 2: //View Expenses
                if(expenseList.size() > 0){
                    cout << "List of expenses: " << endl;
                    for(int i = 0; i < numOfExpenses; i++){
                        cout << "ID: " << i << ", " << expenseList[i].toString() << endl;
                    }
                } else {
                    cerr << "No expenses are present." << endl;
                }

                break;

            case 3: { //Save to File
                ofstream file("Expenses.csv");

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
                cout << "See you later neeeeeeeeerd";
                run = false;
                break;
        }
    }
    
    return 0;
}
