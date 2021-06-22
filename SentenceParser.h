//
// Created by farshid on 6/21/21.
//

#ifndef SIMPLE_INTENT_DETECTION_SENTENCEPARSER_H
#define SIMPLE_INTENT_DETECTION_SENTENCEPARSER_H

#include <string>
#include <vector>

class SentenceParser {
public:
    SentenceParser();
    ~SentenceParser() = default;
    //Deleting copy constructor to preventing singleton from copy
    SentenceParser(const SentenceParser&) = delete;
    //Deleting move constructor to preventing singleton from move
    SentenceParser(SentenceParser&&) = delete;
    //Deleting copy assignment operator to preventing singleton from assignment
    SentenceParser& operator=(const SentenceParser&) = delete;
    //Deleting move assignment operator to preventing singleton from move assignment
    SentenceParser& operator=(SentenceParser&&) = delete;

    std::string GetIntent(const std::string& sentence);
    static SentenceParser* GetInstance();

private:
    bool IsRulesMatch(const std::string& sentence, const std::vector<std::string>& rules);
    //Using vector of string to store rules
    std::vector<std::string> weather_rules_;
    std::vector<std::string> weather_city_rules_;
    std::vector<std::string> fact_rules_;
};


#endif //SIMPLE_INTENT_DETECTION_SENTENCEPARSER_H
