#include <iostream>
#include "SentenceParser.h"

int main() {
    std::cout << "Please enter your sentence or q for exit:" << std::endl;
    std::string input;
    //Loop to receiving input and response after detecting intent of input sentence
    while (true) {
        getline(std::cin, input);
        //Exit when the user inputs q
        if(!std::cin || input == "q" || input == "Q")
            break;
        std::cout<<"Intent: "<<SentenceParser::GetInstance()->GetIntent(input)<<std::endl;
        std::cout << "Please enter your sentence or q for exit:" << std::endl;
    }
    return 0;
}
