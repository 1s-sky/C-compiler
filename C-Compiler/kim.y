%{
#include <stdio.h>
#include <stdlib.h>
void yyerror();
extern int yylex();
%}
%token IDENTIFIER TYPE_IDENTIFIER FLOAT_CONSTANT INTEGER_CONSTANT CHARACTER_CONSTANT STRING_LITERAL PLUS MINUS STAR PERCENT ASSIGN PLUSPLUS MINUSMINUS ARROW LSS GTR LEQ GEQ EQL NEQ DOTDOTDOT AMP AMPAMP BAR BARBAR COLON SEMICOLON PERIOD COMMA EXCL SLASH LP RP LB RB LR RR AUTO_SYM STATIC_SYM SIZEOF_SYM BREAK_SYM DEFAULT_SYM ENUM_SYM RETURN_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM IF_SYM CASE_SYM CONTINUE_SYM DO_SYM ELSE_SYM FOR_SYM
%start program
%%
program 
: translation_unit

translation_unit
: external_declaration
| translation_unit external_declaration

external_declaration
: function_definition
| declaration

function_definition
: declaration_specifiers declarator compound_statement
| declarator compound_statement

declaration
: declaration_specifiers init_declarator_list_opt SEMICOLON

declaration_specifiers
: type_specifier
| storage_class_specifier
| type_specifier declaration_specifiers
| storage_class_specifier declaration_specifiers

storage_class_specifier
: AUTO_SYM | STATIC_SYM | TYPEDEF_SYM

init_declarator_list_opt
:
| init_declarator_list

init_declarator_list
: init_declarator
| init_declarator_list COMMA init_declarator

init_declarator
: declarator
| declarator ASSIGN initializer

type_specifier
: struct_specifier
| enum_type_specifier
| TYPE_IDENTIFIER

struct_specifier
: struct_or_union IDENTIFIER LR struct_declaration_list RR
| struct_or_union LR struct_declaration_list RR
| struct_or_union IDENTIFIER

struct_or_union
: STRUCT_SYM
| UNION_SYM

struct_declaration_list
: struct_declaration
| struct_declaration_list struct_declaration

struct_declaration
: type_specifier struct_declarator_list SEMICOLON

struct_declarator_list
: struct_declarator
| struct_declarator_list COMMA struct_declarator

struct_declarator
: declarator 

enum_type_specifier
: ENUM_SYM IDENTIFIER LR enumerator_list RR
| ENUM_SYM LR enumerator_list RR 
| ENUM_SYM IDENTIFIER

enumerator_list
: enumerator
| enumerator_list COMMA enumerator

enumerator
: IDENTIFIER
| IDENTIFIER ASSIGN constant_expression

declarator
: pointer direct_declarator
| direct_declarator

pointer
: STAR
| STAR pointer

direct_declarator
: IDENTIFIER 
| LP declarator RP
| direct_declarator LB constant_expression_opt RB
| direct_declarator LP parameter_type_list_opt RP

parameter_type_list_opt
: 
| parameter_type_list

parameter_type_list
: parameter_list
| parameter_list COMMA DOTDOTDOT

parameter_list
: parameter_declaration
| parameter_list COMMA parameter_declaration

parameter_declaration
: declaration_specifiers declarator
| declaration_specifiers abstract_declarator_opt

abstract_declarator_opt
:
| abstract_declarator

abstract_declarator
: pointer
| direct_abstract_declarator
| pointer direct_abstract_declarator

direct_abstract_declarator
: LP abstract_declarator RP
| LB constant_expression_opt RB
| LP parameter_type_list_opt RP
| direct_abstract_declarator LB constant_expression_opt RB
| direct_abstract_declarator LP parameter_type_list_opt RP

initializer
: constant_expression
| LR initializer_list RR

initializer_list
: initializer
| initializer_list COMMA initializer

statement
: labeled_statement
| compound_statement
| expression_statement
| selection_statement
| iteration_statement
| jump_statement

labeled_statement
: CASE_SYM constant_expression COLON statement
| DEFAULT_SYM COLON statement

compound_statement
: LR declaration_list statement_list RR

declaration_list
:
| declaration_list declaration

statement_list
:
| statement_list statement

expression_statement
: SEMICOLON
| expression SEMICOLON

selection_statement
: IF_SYM LP expression RP statement
| IF_SYM LP expression RP statement ELSE_SYM statement
| SWITCH_SYM LP expression RP statement

iteration_statement
: WHILE_SYM LP expression RP statement 
| DO_SYM statement WHILE_SYM LP expression RP SEMICOLON
| FOR_SYM LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP statement

expression_opt 
:
| expression 

jump_statement
: RETURN_SYM expression_opt SEMICOLON
| CONTINUE_SYM SEMICOLON
| BREAK_SYM SEMICOLON

arg_expression_list_opt
:
| arg_expression_list

arg_expression_list
: assignment_expression
| arg_expression_list COMMA assignment_expression

constant_expression_opt
:
| constant_expression

constant_expression
: expression

expression
: comma_expression

comma_expression
: assignment_expression

assignment_expression
: conditional_expression
| unary_expression ASSIGN assignment_expression

conditional_expression
: logical_or_expression

logical_or_expression
: logical_and_expression
| logical_or_expression BARBAR logical_and_expression

logical_and_expression
: bitwise_or_expression
| logical_and_expression AMPAMP bitwise_or_expression

bitwise_or_expression
: bitwise_xor_expression

bitwise_xor_expression
: bitwise_and_expression

bitwise_and_expression
: equality_expression

equality_expression
: relational_expression
| equality_expression EQL relational_expression
| equality_expression NEQ relational_expression

relational_expression
: shift_expression
| relational_expression LSS shift_expression
| relational_expression GTR shift_expression
| relational_expression LEQ shift_expression
| relational_expression GEQ shift_expression

shift_expression
: additive_expression

additive_expression
: multiplicative_expression
| additive_expression PLUS multiplicative_expression
| additive_expression MINUS multiplicative_expression

primary_expression
: IDENTIFIER
| INTEGER_CONSTANT
| FLOAT_CONSTANT
| CHARACTER_CONSTANT
| STRING_LITERAL 
| LP expression RP

postfix_expression
: primary_expression
| postfix_expression LB expression RB
| postfix_expression LP arg_expression_list_opt RP
| postfix_expression PERIOD IDENTIFIER
| postfix_expression ARROW IDENTIFIER
| postfix_expression PLUSPLUS
| postfix_expression MINUSMINUS

unary_expression
: postfix_expression
| PLUSPLUS unary_expression
| MINUSMINUS unary_expression
| AMP cast_expression
| STAR cast_expression
| EXCL cast_expression
| MINUS cast_expression
| PLUS cast_expression
| SIZEOF_SYM unary_expression
| SIZEOF_SYM LP type_name RP 

cast_expression
: unary_expression 
| LP type_name RP cast_expression

type_name
: declaration_specifiers
| declaration_specifiers abstract_declarator

multiplicative_expression
: cast_expression
| multiplicative_expression STAR cast_expression
| multiplicative_expression SLASH cast_expression
| multiplicative_expression PERCENT cast_expression

%%
void main(){
	yyparse();
	printf("success!\n");
}

int yywrap(){
	return 1;
}

extern int line_no;
extern char* yytext;

void yyerror(char *s)
{
    printf("%s line : %d token : %s\n", s, line_no, yytext);
    exit(1);
}
