#ifndef CATEGORYSTATICDATA_H
#define CATEGORYSTATICDATA_H

#include <unordered_map>
#include <string>

const std::unordered_map<int, double> categoryLimits = {
    {1, 500},
    {2, 2000},
    {3, 1000},
    {4, 300}
};

const std::unordered_map<int, std::string> categories = {
    {1, "Food"},
    {2, "Entertainment"},
    {3, "Bills"},
    {4, "Utilities"}
};

#endif //CATEGORYSTATICDATA_H
