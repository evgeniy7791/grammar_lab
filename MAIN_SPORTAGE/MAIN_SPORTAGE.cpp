


#include <iostream>

#include "mygrammarBaseVisitor.h"
#include "mygrammarLexer.h"
#include "mygrammarParser.h"
#include "mygrammarVisitor.h"
#include "mygrammarBaseVisitor.h"
#include "UserVisitor.h"

int main() {
	std::string expression = "((2+3)+7*4)/11;";
	std::stringstream stream(expression);
	antlr4::ANTLRInputStream input(stream);
	mygrammarLexer lexer(&input);
	antlr4::CommonTokenStream token(&lexer);
	mygrammarParser parser(&token);
	UserVisitor surmik;

	std::cout << expression << std::endl;
	surmik.visit(parser.prog());

	for (int count = 0; count < surmik.data.size(); ++count) {
		if (surmik.data.empty()) {
			std::cout << "EMPTY" << std::endl;
		}
		std::cout << surmik.data[count] << std::endl;
	}


	return 0;
}