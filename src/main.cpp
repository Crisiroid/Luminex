#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "headers/token.h"

std::vector<token> generate_token(const std::string& str) {
    std::vector<token> tokens{};
    std::string buf;
    for(int i = 0; i < str.length(); i++) {
        char current_character = str.at(i);
        if(std::isalpha(current_character)) {
            buf.push_back(current_character);
            i++;
            while (std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            if(buf == "return") {
                tokens.push_back({.type = type_of_token::return_key});
                buf.clear();
            }else {
                std::cerr << "Something's wrong";
                exit(EXIT_FAILURE);
            }
        }else if(std::isdigit(current_character)) {
            buf.push_back(current_character);
            i++;
            while (std::isdigit(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = type_of_token::integer_value, .return_value = buf});
            buf.clear();

        }else if(std::isspace(current_character)) {
            continue;
        }else if(current_character == ';') {
            tokens.push_back({.type = type_of_token::semicolon});
            buf.clear();
        }else {
            std::cerr << "Input Problem";
            exit(EXIT_FAILURE);
        }
    }
    return tokens;
}

int main(int argc, char* argv[]) {
    std::stringstream str_file_content;
    std::string content;


    if(argc != 2) {
        std::cerr << "Wrong Input Format!" << std::endl << "Try lum <filename>";
    }

    std::fstream input(argv[1], std::ios::in);
    str_file_content << input.rdbuf();
    input.close();
    content = str_file_content.str();
    std::cout << content << std::endl;
    std::vector<token> objects = generate_token(content);
    std::cout<<argv[1] << std::endl;
}