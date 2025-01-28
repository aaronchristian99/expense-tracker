#include <iostream>
#include <vector> 
#include "Expense.cpp"
using namespace std;

int main() {
    //Test code
    // Expense expense1("test", 45.75);
    // Expense expense2("Grocery Shopping",500, 24,2,2020);
    // cout << expense1.toString() << endl;
    // cout << expense2.toString() << endl;

    vector<Expense> expenseList;
    int numOfExpenses = 1;
    int option;
    string userInput;
    bool run = true;
    cout << "------------------ Expense Tracker ---------------------" << endl;

    while(run == true){
        int day, month, year;
        float amount;
        string desc;

        cout << "1. Add Expense" << endl << "2. View Expenses" << endl << "3. Save to File" << endl << "4. Exit Program" << endl << "Enter your input: ";
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
                cout << "List of expenses: " << endl;
                for(int i = 0; i < numOfExpenses; i++){
                    cout << "ID: " << i << ", " << expenseList[i].toString() << endl;
                }
                break;
            
            case 3: //Save to File
                break;
            
            case 4: //Exit Program
                cout << "See you later neeeeeeeeerd";
                run = false;
                break;
        }        
    }
    
    return 0;
}
