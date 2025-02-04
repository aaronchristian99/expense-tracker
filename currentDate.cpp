#include <chrono>
#include <array>

// returns current date as an array of 3 ints (day, month, year)
std::array<int, 3> getCurrentDate() { 
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    return {now->tm_mday, now->tm_mon + 1, now->tm_year + 1900};
}

// returns unix timestamp of date
long getUnixTime(int day, int month, int year) {
    struct tm timeStruct = {};
    
    timeStruct.tm_mday = day;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_year = year - 1900;

    return mktime(&timeStruct);
}