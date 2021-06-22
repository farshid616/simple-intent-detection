//
// Created by farshid on 6/21/21.
//

#include "RulesManager.h"

#include <fstream>
#include <iostream>

RulesManager::RulesManager() {

}

//This function will call the GetRules function with the defined or predefined location of
//weather_rules file, and will return result of extracted rules from file
//file_address is a related path from executable to the weather_rules file
//usage: GetWeatherRules("weather_rules") <rules file is beside the executable>
const std::vector<std::string> RulesManager::GetWeatherRules(const std::string& file_address) {
    return GetRules(file_address);
}

//This function will call the GetRules function with the defined or predefined location of
//weather_city_rules file, and will return result of extracted rules from file
//file_address is a related path from executable to the weather_city_rules file
//usage: GetWeatherCityRules("weather_city_rules") <rules file is beside the executable>
const std::vector<std::string> RulesManager::GetWeatherCityRules(const std::string& file_address) {
    return GetRules(file_address);
}

//This function will call the GetRules function with the defined or predefined location of
//fact_rules file, and will return result of extracted rules from file
//file_address is a related path from executable to the fact_rules file
//usage: GetFactRules("fact_rules") <rules file is beside the executable>
const std::vector<std::string> RulesManager::GetFactRules(const std::string& file_address) {
    return GetRules(file_address);
}

//This function will receive a file path as a parameter and will return the all of existing line
//in that file as a vector of string
//usage: GetRules("weather_rules") <named file is beside the executable>
const std::vector<std::string> RulesManager::GetRules(const std::string& file_address) {
    std::fstream rules_file;
    std::string line;
    std::vector<std::string> rules;
    rules_file.open(file_address, std::ios::in | std::ios::app) ;
    if (rules_file.is_open()) {
        while (std::getline(rules_file, line)) {
            if (!line.empty() && line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);
            rules.push_back(line);
        }

        rules_file.close();
    }
    return std::move(rules);
}