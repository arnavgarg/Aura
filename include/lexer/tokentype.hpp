#ifndef TOKENTYPE_HPP
#define TOKENTYPE_HPP

enum TokenType {
    // keywords
    If,
    Else,
    For,
    While,
    Null,
    Func,
    Return,

    // arithmatic operators
    Add,
    Sub,
    Div,
    Mul,
    Mod,

    // comparision operators
    Less,
    LessEqual,
    Greater,
    GreatEqual,
    Equal,

    // assignment operator
    Assign,

    // type declarations
    IntDec,
    DoubDec,
    BoolDec,
    StrDec,

    // type values
    Int,
    Double,
    Bool,
    String,

    // Delimiters
    Colon,
    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    LeftBlock,
    RightBlock,
    Semicolon,
    Endline,

    // misc
    Space,
    Identifier,
    EndOfInput,
    Unrecognized
};

/*
 * used as string reference for enum
 */
const char* const typeStrings[] = {
    // keywords
    "If",
    "Else",
    "For",
    "While",
    "Null",
    "Func",
    "Return",

    // arithmatic operators
    "Add",
    "Sub",
    "Div",
    "Mul",
    "Mod",

    // comparision operators
    "Less",
    "LessEqual",
    "Greater",
    "GreatEqual",
    "Equal",

    // assignment operator
    "Assign",

    // type declarations
    "IntDec",
    "DoubDec",
    "BoolDec",
    "StrDec",

    // type values
    "Int",
    "Double",
    "Bool",
    "String",

    // Delimiters
    "Colon",
    "LeftParen",
    "RightParen",
    "LeftBrace",
    "RightBrace",
    "LeftBlock",
    "RightBlock",
    "Semicolon",
    "Endline",

    // misc
    "Space",
    "Identifier",
    "EndOfInput",
    "Unrecognized"
};

#endif
