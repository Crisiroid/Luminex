//
// Created by Crisiroid on 8/7/2024.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <optional>
#include <iostream>
#include "type_of_token.h"


struct token {
    type_of_token type;
    std::optional<std::string> return_value;
};

#endif //TOKEN_H
