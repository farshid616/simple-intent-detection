//
// Created by farshid on 6/20/21.
//

#ifndef ASSESSMENT_TESTS_TESTS_H
#define ASSESSMENT_TESTS_TESTS_H

#include <gtest/gtest.h>

#include "../RulesManager.h"
#include "../SentenceParser.h"

//Test the GetWeatherRules function with default argument
TEST(RulesManager, GetWeatherRulesDefault) {
    ASSERT_EQ(2, RulesManager::GetWeatherRules().size());
}

//Test the GetWeatherCityRules function with default argument
TEST(RulesManager, GetWeatherCityRulesDefault) {
    ASSERT_EQ(1, RulesManager::GetWeatherCityRules().size());
}

//Test the GetFactRules function with default argument
TEST(RulesManager, GetFactRulesDefault) {
    ASSERT_EQ(1, RulesManager::GetFactRules().size());
}

//Test the GetWeatherRules function with argument
TEST(RulesManager, GetWeatherRules) {
    ASSERT_EQ(8, RulesManager::GetWeatherRules("../../weather_rules").size());
}

//Test the GetWeatherCityRules function with argument
TEST(RulesManager, GetWeatherCityRules) {
    ASSERT_EQ(1, RulesManager::GetWeatherCityRules("../../weather_city_rules").size());
}

//Test the GetFactRules function with argument
TEST(RulesManager, GetFactRules) {
    ASSERT_EQ(1, RulesManager::GetFactRules("../../fact_rules").size());
}

//Test the GetRules function with existing file
TEST(RulesManager, GetRules) {
    ASSERT_EQ(1, RulesManager::GetFactRules("../../fact_rules").size());
}

//Test the GetRules function with doesn't existing file
TEST(RulesManager, GetRulesFalult) {
    ASSERT_EQ(0, RulesManager::GetFactRules("nothing").size());
}

//Test the GetIntent function for a sentence with intent of Get Weather
TEST(SentenceParser, GetIntentWeather) {
    ASSERT_EQ("Get Weather", SentenceParser::GetInstance()->GetIntent("How is the Weather?"));
}

//Test the GetIntent function for a sentence with intent of Get Weather City
TEST(SentenceParser, GetIntentWeatherCity) {
    ASSERT_EQ("Get Weather City", SentenceParser::GetInstance()->GetIntent("How is the Weather in Berlin?"));
}

//Test the GetIntent function for a sentence with intent of Get Fact
TEST(SentenceParser, GetIntentFact) {
    ASSERT_EQ("Get Fact", SentenceParser::GetInstance()->GetIntent("Give me a fact"));
}

//Test the GetIntent function for a sentence with unknown intent
TEST(SentenceParser, GetIntentOther) {
    ASSERT_EQ("Not Detected!", SentenceParser::GetInstance()->GetIntent("How do you do?"));
}
#endif //ASSESSMENT_TESTS_TESTS_H
