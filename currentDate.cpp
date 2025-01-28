#include <chrono>
#include <array>

// returns current date as an array of 3 ints (day, month, year)
std::array<int, 3> getCurrentDate() { 
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    return {now->tm_mday, now->tm_mon + 1, now->tm_year + 1900};
}