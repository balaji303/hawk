//
// Created by lockna on 11/28/19.
//
#include <stdio.h>
#include <string.h>
#include <hawk/c_list.h>
#include <hawk/t_list.h>
#include <hawk/token.h>

#ifndef HAWK_LEXER_H
#define HAWK_LEXER_H

// The Lexer struct which contains the character list, the file, the token list and the function pointers

typedef struct Ha_Lexer {

    char *file;
    struct c_list *clist;
    struct t_list *tlist;

    // Function pointers for the clist
    int (*lex)(struct Ha_Lexer* lexer);
    int (*lexer_inputFile)(struct Ha_Lexer* lexer);
    int (*eval_List) (struct Ha_Lexer* lexer);



} Lexer;




Lexer new_Lexer(char* file);
static int _lexer_fileInput(struct Ha_Lexer* lexer);
int _lexing(struct Ha_Lexer* lexer);
static int _evaluate_List  (struct Ha_Lexer* lexer);
static int isSeperator(char value);
static int isSingleToken(char value);
static enum Ha_Tokens getTokenFromValue(char *value);
static int isKeyword(char *value, enum Ha_Tokens* token);
static int isNumber(char *value);

#endif //HAWK_LEXER_H