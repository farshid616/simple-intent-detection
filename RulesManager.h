//
// Created by farshid on 6/21/21.
//

#ifndef SIMPLE_INTENT_DETECTION_RULESMANAGER_H
#define SIMPLE_INTENT_DETECTION_RULESMANAGER_H

#include <vector>
#include <string>

//RulesManager is responsible for reading predefined rule files on the disk and prepare them for using in a vector.
//Rules are stored in three different files and each line contains a rule. We have different function that read and
//return related rules.
class RulesManager {
public:
    RulesManager();
    static const std::vector<std::string> GetWeatherRules(const std::string& file_address = "../weather_rules");
    static const std::vector<std::string> GetWeatherCityRules(const std::string& file_address = "../weather_city_rules");
    static const std::vector<std::string> GetFactRules(const std::string& file_address = "../fact_rules");
private:
    static const std::vector<std::string> GetRules(const std::string& file_address);
};


#endif //SIMPLE_INTENT_DETECTION_RULESMANAGER_H
