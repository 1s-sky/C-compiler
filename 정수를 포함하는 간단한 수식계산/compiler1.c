#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	enum{INT, FLOAT} type;
	union {
		int i;
		float f;
	} value;
}Type;

Type num;
char string[20];
char ch;
enum { BLANK, NUMBER, PLUS, STAR, LP, RP, END } token;

Type expression();
Type term();
Type factor();
void get_token();
void error(int);

void main() {
	Type result;
	printf("수식을 입력하세요 : ");
	get_token();
	result = expression();
	if (token != END)
		error(3);
	else {
		if(result.type == INT) printf("%d \n", result.value.i);
		else printf("%f \n", result.value.f);
	}
}

Type expression() {
	Type result;
	result = term();
	while (token == PLUS) {
		get_token();
		Type temp = term();
		if (result.type == INT && temp.type == INT) {
			result.value.i = result.value.i + temp.value.i;
		}
		else if (result.type == INT && temp.type == FLOAT) {
			result.type = FLOAT;
			result.value.f = result.value.i + temp.value.f;
		}
		else if (result.type == FLOAT && temp.type == INT) {
			result.value.f = result.value.f + temp.value.i;
		}
		else {
			result.value.f = result.value.f + temp.value.f;
		}
	}
	return(result);
}

Type term() {
	Type result;
	result = factor();
	while (token == STAR) {
		get_token();
		Type temp = factor();
		if (result.type == INT && temp.type == INT) {
			result.value.i = result.value.i * temp.value.i;
		}
		else if (result.type == INT && temp.type == FLOAT) {
			result.type = FLOAT;
			result.value.f = result.value.i * temp.value.f;
		}
		else if (result.type == FLOAT && temp.type == INT) {
			result.value.f = result.value.f * temp.value.i;
		}
		else {
			result.value.f = result.value.f * temp.value.f;
		}
	}
	return(result);
}

Type factor() {
	Type result;
	if (token == NUMBER) {
		result = num;
		get_token();
	}
	else if (token == LP) {
		get_token();
		result = expression();
		if (token == RP)
			get_token();
		else
			error(2);
	}
	else
		error(1);
	return(result);
}

void get_token() {
	if (token != NUMBER) {
		ch = getchar();
	}
	if (ch >= '0' && ch <= '9') {
		token = NUMBER;
		num.type = INT;		
		char temp1[100] = "";
		char temp2[10] = "";
		while ((ch >= '0' && ch <= '9') || ch == '.') {
			if (ch == '.') {
				num.type = FLOAT;
				strcat(temp1, ".");
			}
			else {
				sprintf(temp2, "%c", ch);
				strcat(temp1, temp2);
			}
			ch = getchar();
		}
		if (num.type == INT) num.value.i = atoi(temp1);
		else num.value.f = atof(temp1);
	}
	else if (ch == '+')
		token = PLUS;
	else if (ch == '*')
		token = STAR;
	else if (ch == '(')
		token = LP;
	else if (ch == ')')
		token = RP;
	else if (ch == '\n')
		token = END;
	else if (ch == ' ')
		token = BLANK;
	else
		error(4);
}

void error(int i) {
	switch (i) {
		case 1: printf("factor() 에러! 수식의 시작이 NUMBER나 LP가 아닙니다."); break;
		case 2: printf("factor() 에러! LP만 있고 RP가 없습니다."); break;
		case 3: printf("main() 에러! 비정상 종료되었습니다."); break;
		case 4: printf("get_token() 에러! 입력오류"); break;
	}
}
