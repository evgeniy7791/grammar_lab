#pragma once

#include "mygrammarBaseVisitor.h"

class UserVisitor : public mygrammarBaseVisitor {

    std::any visitLexprR(mygrammarParser::LexprRContext* context) {
        return visit(context->expr());
    }

    std::any visitExprADDexpr(mygrammarParser::ExprADDexprContext* context) {
        int first = std::any_cast<int>(visit(context->expr(0)));
        int second = std::any_cast<int>(visit(context->expr(1)));
       
        if (context->ADD())
            return first + second;
        return first - second;
    }

    std::any visitExprMULexpr(mygrammarParser::ExprMULexprContext* context) {
        int first = std::any_cast<int>(visit(context->expr(0)));
        int second = std::any_cast<int>(visit(context->expr(1)));
        if (context->DIV())
            return first / second;
        return first * second;
    }

    std::any visitINTEGER(mygrammarParser::INTEGERContext* context) {
        return std::stoi(context->INT()->getText());
    }

    std::any visitExpr_sep(mygrammarParser::Expr_sepContext* context) {
        return visit(context->expr());
    }

    std::any visitProg_row(mygrammarParser::Prog_rowContext* context) {
        int val = std::any_cast<int>(visit(context->row()));
        data.push_back(val);
        return visit(context->prog());
    }

    std::any visitOneLineProg(mygrammarParser::OneLineProgContext* context) {
        int val = std::any_cast<int>(visit(context->row()));
        data.push_back(val);
        return val;
    }

public:
    std::vector <double> data;
};