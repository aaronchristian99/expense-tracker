#include <iostream>
#include <fstream>
#include <vector> 
#include "Expense.cpp"
#include "file_loading.cpp"

using namespace std;

void badCin(){
    cout << endl << "Invalid option. Please try again." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Expense> expenseList = load_file("expenses_init.csv");
    int numOfExpenses = expenseList.size();
    int option;
    string userInput;
    bool run = true;
    cout << "------------------ Expense Tracker ---------------------" << endl;

    while(run == true){
        int day, month, year;
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

        switch(option){ //i just threw everything in here to just set things up
            case 1: { //Add Expense
                cout << "Please enter the description of the expense: " << endl;
                cin.ignore();
                getline(cin, desc);
                
                while(true){
                    cout << "Please enter the amount of the expense: " << endl;
                    cin >> amount;
                    if(amount > 0){
                        break;
                    }else{
                        badCin();
                    }

                }
                

                ofstream tempFile;
                tempFile.open("expenses_init.csv", ios::app);

                if(!tempFile.is_open()){
                    cout << "File could not be opened" << endl;
                }

                while(true) {
                    cout << "Would you like to use todays date? (y/n)." << endl;
                    cin >> userInput;

                    if(userInput == "y"){
                        Expense newExpense = Expense(desc,amount);
                        expenseList.push_back(newExpense);
                        tempFile << endl << newExpense.toInitCsv();
                        cout << "Expense added." << endl;;
                        numOfExpenses++;
                        break;

                    } else if(userInput == "n"){ //this is awful ik, could make some date parser later on
                        cout << "Please enter the day (dd)"  << endl;
                        cin >> day;
                        cout << "Please enter the month (mm)" << endl;
                        cin >> month;
                        cout << "Please enter the year (yyyy)" << endl;
                        cin >> year;
                        Expense newExpense = Expense(desc,amount,day,month,year);
                        expenseList.push_back(newExpense);
                        tempFile << endl << newExpense.toInitCsv();
                        cout << "Expense added." << endl;
                        numOfExpenses++;
                        break;
                    }else{
                        badCin();
                    }
                }

                tempFile.close();
                break;
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
