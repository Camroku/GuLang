#pragma once
#include <gul/lexer/token.h>

struct ast {} typedef ast_t;

struct numstr {
    ast_t ast;
    token_t token;
    int value;
} typedef num_ast_t;

struct binopstr {
    ast_t ast;
    ast_t left;
    token_t token;
    ast_t value;
} typedef binop_ast_t;

token_t parse_tokens(token_t(*lexer_next_token)());