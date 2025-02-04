#pragma once
#include <array>
#include <string>
#include <sstream>
#include <iomanip>
#include "currentDate.cpp"

using namespace std;

class Expense {
    private:
        int id, day, month, year, category;
        string desc;
        double amount;

    public:
        Expense(string desc, double amount, int day = -1, int month = -1, int year = -1, int category = -1) : desc(desc), amount(amount), day(day), month(month), year(year), category(category) {
            
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

        string getDesc() {
            return desc;
        }

        int getAmount() {
            return amount;
        }

        int getDate() {
            return getUnixTime(day, month, year);
        }

        int getCategory(){
            return category;
        }

        // formatted for "View Expenses"
        string toString() {
            std::ostringstream amountStream;
            amountStream << std::fixed << std::setprecision(2) << amount;
            string amountStr = amountStream.str();
            
            return "$" + amountStr + ", " + desc + ", " + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + ", " + to_string(category);
        }

        // formatted for expenses_output.csv (export)
        string toCsv() {
            return desc + ',' + to_string(amount) + ',' + to_string(day) + '/' + to_string(month) + '/' + to_string(year) + ',' + to_string(category);
        }

        // formatted for file saving/loading
        string toInitCsv() {
            return desc + ',' + to_string(amount) + ',' + to_string(day) + ',' + to_string(month) + ',' + to_string(year) + ',' + to_string(category);
        }


};