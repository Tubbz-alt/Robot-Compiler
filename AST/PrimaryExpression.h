//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_PRIMARYEXPRESSION_H
#define COMPILER_PRIMARYEXPRESSION_H

#include "AST.h"

class PrimaryExpression: public AST {
public:
    std::string describe() override;
};


#endif //COMPILER_PRIMARYEXPRESSION_H
