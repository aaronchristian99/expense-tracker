#include <iostream>
#include "Expense.cpp"
using namespace std;

int main() {
    int option;

    while (option != 5) {
        std::cout << "------------------ Expense Tracker ---------------------" << std::endl;
        std::cout << "1. View Expense" << std::endl << "2. Add Expense" << std::endl << "3. Filter Expense" << std::endl << "4. Save to File" << std::endl
                  << "5. Visualize" << std::endl << "6. Exit" << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                // expense.viewExpense();
                break;

            case 2:
                // expense.addExpense();
                break;

            case 3:
                // expense.filterExpense();
                break;

            case 4:
                // expense.saveToFile();
                break;

            case 5:
                // expense.visualize();
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
}
