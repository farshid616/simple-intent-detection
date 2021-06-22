//
// Created by farshid on 6/21/21.
//

#include "SentenceParser.h"
#include <regex>
#include "RulesManager.h"

//Initializing our rules vector in constructor
SentenceParser::SentenceParser() {
    weather_rules_ = RulesManager::GetWeatherRules();
    weather_city_rules_ = RulesManager::GetWeatherCityRules();
    fact_rules_ = RulesManager::GetFactRules();
}

//This function receives a string as input and will return the detected sentence intent
//It will detect Get weather, Get Weather City, Get Fact and return them as output.
std::string SentenceParser::GetIntent(const std::string &sentence) {
    std::string input = sentence;
    //Remove special character from sentence
    input.resize(remove_if(input.begin(), input.end(),
                           [](char x){return !isalnum(x) && !isspace(x);})-input.begin());
    //Convert sentence to all lower case letters
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    //Add a space in beginning and end of the sentence duo to our predefined rules
    input = " "+input+" ";

    if (IsRulesMatch(input, weather_rules_)) {
        if (IsRulesMatch(input, weather_city_rules_)) {
            return "Get Weather City";
        }
        return "Get Weather";
    } else if (IsRulesMatch(input, fact_rules_)) {
        return "Get Fact";
    }
    else {
        return "Not Detected!";
    }
}

//This function will return the single instance of the class
SentenceParser* SentenceParser::GetInstance() {
    static SentenceParser instance;
    return &instance;
}


//This function receives a string sentence and a vector of predefined rules and will return a bool for
//result of validity of rules on the sentence
bool SentenceParser::IsRulesMatch(const std::string& sentence, const std::vector<std::string>& rules) {
    for (auto item: rules) {
        if (std::regex_match(sentence, std::regex(item)))
            return true;
    }
    return false;
}