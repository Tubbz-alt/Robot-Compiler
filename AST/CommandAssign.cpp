#include <utility>

#include <utility>

#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommandAssign.h"

CommandAssign::CommandAssign(VarName varName, Expression expression) : varName(std::move(varName)),
                                                                                     expression(std::move(expression)) {}
