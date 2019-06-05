#include "Parser.h"

//
// Created by cybex on 2019/05/03.
//

Parser::Parser(std::string sentence) {
    currentToken = nullptr;
    curTokenPos = -1;
    this->sentence = std::move(sentence);
}

/**
 * Builds the AST defined by Production Rules and performs syntax checks while building the tree
 */
void Parser::checkSyntax() {
    Scanner *s = new Scanner(std::move(sentence));
    printf("Building Token List...");
    int success = s->buildTokenList();
    if (success == 1) {
        // Error message handle in buildTokenList
        return;
    }
    printf(ANSI_COLOR_GREEN "Success\n" ANSI_COLOR_RESET);
    tokenList = s->getTokens();

    printf("Building AST...");
    success = buildAST(tokenList);
    if (success == 1) {
        // Error message handle in buildAST
        return;
    }
    printf(ANSI_COLOR_GREEN "Success\n" ANSI_COLOR_RESET);
}

/**
 * Performs the contextual analysis ensuring correct variable scopes are used.
 */
void Parser::checkContext() {

}


//Expression Parser::parseExpression() {
//    PrimaryExpression_Expression *p1 = parsePrimary();
//    Operater *o = parseOperator();
//    PrimaryExpression_Expression *p2 = parsePrimary();
//    return {p1, o, p2};
//}

void Parser::acceptIt() {
    fetchNextToken();
}

void Parser::accept(TokenType type) {
    if (currentToken->matchesType(type)) {
        fetchNextToken();
    } else {
        std::cout << "Syntax error in Parser::accept(TokenType)";
    }
}

void Parser::fetchNextToken() {
    curTokenPos++;
    currentToken = (curTokenPos < tokenList.size())
                   ? &tokenList.at(curTokenPos)
                   : nullptr;
}
//
//PrimaryExpression_Expression* Parser::parsePrimary() {
//    PrimaryExpression_Expression *pe = nullptr;
//    if (currentToken == nullptr) {
//        return nullptr;
//    }
//    switch (currentToken->getType()) {
//        case Identifier: {
////            pe = new IdentifierPE(parseIdentifier());
//            break;
//        }
//        case LPar: {
//            acceptIt();
////            pe = new BracketsPE(parseExpression());
//            accept(RPar);
//            break;
//        }
//        default: {
//            std::cout << "Syntax error in Parser::parsePrimary";
//            break;
//        }
//    }
//    return pe;
//}

int Parser::buildAST(std::vector<Token> vector) {
    return 0;
}

//Identifier Parser::parseIdentifier() {
//    auto *i = new Identifier(currentToken->getValue());
//    accept(Identifier);
//    return *i;
//}
//
//Operater* Parser::parseOperator() {
//    auto *o = new Operater(currentToken->getValue());
//    accept(Operater);
//    return o;
//}