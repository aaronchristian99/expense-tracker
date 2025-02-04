#include "Expense.cpp"
#include <vector> 

vector<Expense> filter_category(vector<Expense> &exp, int category){
    vector<Expense> filtered_expenses;
    for (Expense e: exp){
        if (e.getCategory() == category){
            filtered_expenses.push_back(e);
        }
    }
    return filtered_expenses;
}
