#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
using namespace std;

class Expense {
    private:
        int id, date, month, year;
        string desc;
        double amount;
    public:
        Expense(string desc, double amount, int date, int month, int year) : desc(desc), amount(amount), date(date), month(month), year(year) {};

        string toString() {
            return "$" + to_string(amount) + desc + to_string(date) + "/" + to_string(month) + "/" + to_string(year);
        };
};

#endif // GRANDPARENT_H
