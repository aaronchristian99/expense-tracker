#pragma once
#include <array>
#include <string>
#include "currentDate.cpp"

using namespace std;

class Expense {
    private:
        int id, day, month, year;
        string desc;
        double amount;

    public:
        Expense(string desc, double amount, int day = -1, int month = -1, int year = -1) : desc(desc), amount(amount), day(day), month(month), year(year) {
            
            if(day == -1 || month == -1 || year == -1){
                array<int, 3> currentDate = getCurrentDate();
                this->day = currentDate[0];
                this->month = currentDate[1];
                this->year = currentDate[2];
            }else{
                this->day = day;
                this->month = month;
                this->year = year;
            }
        };

        string toString() {
            return "$" + to_string(amount) + " " + desc + " " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        };
        string toCsv() {
            return desc + ',' + to_string(amount) + ',' + to_string(day) + '/' + to_string(month) + '/' + to_string(year);
        }
};