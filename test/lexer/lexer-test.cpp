#include <vector>

#include "lexer/lexer.hpp"
#include "gtest/gtest.h"

Lexer lexer;

TEST(LexerTest, If) {
    std::vector<Token> tokens = lexer.tokenize("if");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), If) << "lexer cannot recognize keyword if";
    EXPECT_EQ(tokens[0].getValue(), "if") << "lexer cannot read keyword if";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Else) {
    std::vector<Token> tokens = lexer.tokenize("else");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Else) << "lexer cannot recognize keyword else";
    EXPECT_EQ(tokens[0].getValue(), "else") << "lexer cannot read keyword else";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, For) {
    std::vector<Token> tokens = lexer.tokenize("for");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), For) << "lexer cannot recognize keyword for";
    EXPECT_EQ(tokens[0].getValue(), "for") << "lexer cannot read keyword for";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, While) {
    std::vector<Token> tokens = lexer.tokenize("while");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), While) << "lexer cannot recognize keyword while";
    EXPECT_EQ(tokens[0].getValue(), "while") << "lexer cannot read keyword while";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Null) {
    std::vector<Token> tokens = lexer.tokenize("null");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Null) << "lexer cannot recognize keyword null";
    EXPECT_EQ(tokens[0].getValue(), "null") << "lexer cannot read keyword null";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Func) {
    std::vector<Token> tokens = lexer.tokenize("func");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Func) << "lexer cannot recognize keyword func";
    EXPECT_EQ(tokens[0].getValue(), "func") << "lexer cannot read keyword func";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Return) {
    std::vector<Token> tokens = lexer.tokenize("return");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Return) << "lexer cannot recognize keyword return";
    EXPECT_EQ(tokens[0].getValue(), "return") << "lexer cannot read keyword return";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Addition) {
    std::vector<Token> tokens = lexer.tokenize("+");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Add) << "lexer cannot recognize operator +";
    EXPECT_EQ(tokens[0].getValue(), "+") << "lexer cannot read operator +";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Subtraction) {
    std::vector<Token> tokens = lexer.tokenize("-");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Sub) << "lexer cannot recognize operator -";
    EXPECT_EQ(tokens[0].getValue(), "-") << "lexer cannot read operator -";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Division) {
    std::vector<Token> tokens = lexer.tokenize("/");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Div) << "lexer cannot recognize operator /";
    EXPECT_EQ(tokens[0].getValue(), "/") << "lexer cannot read operator /";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Multiplication) {
    std::vector<Token> tokens = lexer.tokenize("*");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Mul) << "lexer cannot recognize operator *";
    EXPECT_EQ(tokens[0].getValue(), "*") << "lexer cannot read operator *";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Modulus) {
    std::vector<Token> tokens = lexer.tokenize("%");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Mod) << "lexer cannot recognize operator %";
    EXPECT_EQ(tokens[0].getValue(), "%") << "lexer cannot read operator %";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Less) {
    std::vector<Token> tokens = lexer.tokenize("<");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Less) << "lexer cannot recognize operator <";
    EXPECT_EQ(tokens[0].getValue(), "<") << "lexer cannot read operator <";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, LessEqual) {
    std::vector<Token> tokens = lexer.tokenize("<=");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), LessEqual) << "lexer cannot recognize operator <=";
    EXPECT_EQ(tokens[0].getValue(), "<=") << "lexer cannot read operator <=";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Greater) {
    std::vector<Token> tokens = lexer.tokenize(">");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Greater) << "lexer cannot recognize operator >";
    EXPECT_EQ(tokens[0].getValue(), ">") << "lexer cannot read operator >";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, GreatEqual) {
    std::vector<Token> tokens = lexer.tokenize(">=");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), GreatEqual) << "lexer cannot recognize operator >=";
    EXPECT_EQ(tokens[0].getValue(), ">=") << "lexer cannot read operator >=";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Equal) {
    std::vector<Token> tokens = lexer.tokenize("==");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Equal) << "lexer cannot recognize operator ==";
    EXPECT_EQ(tokens[0].getValue(), "==") << "lexer cannot read operator ==";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Assign) {
    std::vector<Token> tokens = lexer.tokenize("=");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Assign) << "lexer cannot recognize operator =";
    EXPECT_EQ(tokens[0].getValue(), "=") << "lexer cannot read operator =";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, IntDec) {
    std::vector<Token> tokens = lexer.tokenize("int");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), IntDec) << "lexer cannot recognize keyword int";
    EXPECT_EQ(tokens[0].getValue(), "int") << "lexer cannot read keyword int";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, DoubDec) {
    std::vector<Token> tokens = lexer.tokenize("double");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), DoubDec) << "lexer cannot recognize keyword double";
    EXPECT_EQ(tokens[0].getValue(), "double") << "lexer cannot read keyword double";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, BoolDec) {
    std::vector<Token> tokens = lexer.tokenize("bool");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), BoolDec) << "lexer cannot recognize keyword bool";
    EXPECT_EQ(tokens[0].getValue(), "bool") << "lexer cannot read keyword bool";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, StrDec) {
    std::vector<Token> tokens = lexer.tokenize("string");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), StrDec) << "lexer cannot recognize keyword string";
    EXPECT_EQ(tokens[0].getValue(), "string") << "lexer cannot read keyword string";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Int) {
    std::vector<Token> tokens = lexer.tokenize("4560");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Int) << "lexer cannot recognize integer";
    EXPECT_EQ(tokens[0].getValue(), "4560") << "lexer cannot read integer value";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, DoubleDot) {
    std::vector<Token> tokens = lexer.tokenize(".057");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Double) << "lexer cannot recognize double that starts with .";
    EXPECT_EQ(tokens[0].getValue(), ".057") << "lexer cannot read double value that starts with .";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, DoubleDigit) {
    std::vector<Token> tokens = lexer.tokenize("56.057");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Double) << "lexer cannot recognize double that starts with digit";
    EXPECT_EQ(tokens[0].getValue(), "56.057") << "lexer cannot read double value that starts with digit";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, BoolTrue) {
    std::vector<Token> tokens = lexer.tokenize("true");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Bool) << "lexer cannot recognize true boolean";
    EXPECT_EQ(tokens[0].getValue(), "true") << "lexer cannot read boolean value true";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, BoolFalse) {
    std::vector<Token> tokens = lexer.tokenize("false");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Bool) << "lexer cannot recognize false boolean";
    EXPECT_EQ(tokens[0].getValue(), "false") << "lexer cannot read boolean value false";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, typeStrings) {
    std::vector<Token> tokens = lexer.tokenize("\"string test\"");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), String) << "lexer cannot recognize string";
    EXPECT_EQ(tokens[0].getValue(), "\"string test\"") << "lexer cannot read string value";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Colon) {
    std::vector<Token> tokens = lexer.tokenize(":");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Colon) << "lexer cannot recognize symbol colon";
    EXPECT_EQ(tokens[0].getValue(), ":") << "lexer cannot read symbol colon";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, LeftParen) {
    std::vector<Token> tokens = lexer.tokenize("(");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), LeftParen) << "lexer cannot recognize symbol left-paren";
    EXPECT_EQ(tokens[0].getValue(), "(") << "lexer cannot read symbol left-paren";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, RightParen) {
    std::vector<Token> tokens = lexer.tokenize(")");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), RightParen) << "lexer cannot recognize symbol right-paren";
    EXPECT_EQ(tokens[0].getValue(), ")") << "lexer cannot read symbol right-paren";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, LeftBrace) {
    std::vector<Token> tokens = lexer.tokenize("{");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), LeftBrace) << "lexer cannot recognize symbol left-brace";
    EXPECT_EQ(tokens[0].getValue(), "{") << "lexer cannot read symbol left-brace";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, RightBrace) {
    std::vector<Token> tokens = lexer.tokenize("}");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), RightBrace) << "lexer cannot recognize symbol right-brace";
    EXPECT_EQ(tokens[0].getValue(), "}") << "lexer cannot read symbol right-brace";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, LeftBlock) {
    std::vector<Token> tokens = lexer.tokenize("[");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), LeftBlock) << "lexer cannot recognize symbol left-block";
    EXPECT_EQ(tokens[0].getValue(), "[") << "lexer cannot read symbol left-block";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, RightBlock) {
    std::vector<Token> tokens = lexer.tokenize("]");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), RightBlock) << "lexer cannot recognize symbol right-brace";
    EXPECT_EQ(tokens[0].getValue(), "]") << "lexer cannot read symbol right-block";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Semicolon) {
    std::vector<Token> tokens = lexer.tokenize(";");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Semicolon) << "lexer cannot recognize symbol semicolon";
    EXPECT_EQ(tokens[0].getValue(), ";") << "lexer cannot read symbol semicolon";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Endline) {
    std::vector<Token> tokens = lexer.tokenize("\n");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Endline) << "lexer cannot recognize symbol \\n";
    EXPECT_EQ(tokens[0].getValue(), "\\n") << "lexer cannot read symbol \\n";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Space) {
    std::vector<Token> tokens = lexer.tokenize(" ");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Space) << "lexer cannot recognize space";
    EXPECT_EQ(tokens[0].getValue(), " ") << "lexer cannot read space";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}

TEST(LexerTest, Identifier) {
    std::vector<Token> tokens = lexer.tokenize("test");
    ASSERT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0].getType(), Identifier) << "lexer cannot recognize identifier";
    EXPECT_EQ(tokens[0].getValue(), "test") << "lexer cannot read indentifier test";
    EXPECT_EQ(tokens[1].getType(), EndOfInput) << "lexer does not end output with EOI";
}
