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

    // types
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
    Newline,

    // misc
    EndOfInput,
    Unrecognized
};

#endif
