#ifndef STRUCT_TYPE_PROJECT_2_H
#define STRUCT_TYPE_PROJECT_2_H

#include <iostream>
#include <fstream>
#include <map>

struct CityCode {
    std::string city;
    std::string code;
};

void saveDictionary(const std::map<std::string, std::string>& dict, const std::string& fileName);
void loadDictionary(std::map<std::string, std::string>& dict, const std::string& fileName);
void addRecord(std::map<std::string, std::string>& dict);
void deleteRecord(std::map<std::string, std::string>& dict);
void printDictionary(const std::map<std::string, std::string>& dict);

#endif // STRUCT_TYPE_PROJECT_2_H
