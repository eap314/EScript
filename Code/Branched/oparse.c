//new parser
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "stack.h"

int ch1=0, linenum=1, charnum=0;
extern int err(int);
double calc(char *op, double a, double b){
	int c=a,d=b;
	if(strcmp(op, "==")) return (a==b);
	if(strcmp(op, ">")) return (a>b);
	if(strcmp(op, ">=")) return (a>=b);
	if(strcmp(op, "<")) return (a<b);
	if(strcmp(op, "<=")) return (a<=b);
	if(strcmp(op, "|")) return (c|d);
	if(strcmp(op, "||")) return (a||b);
	if(strcmp(op, "&")) return (c&d);
	if(strcmp(op, "&&")) return (a&&b);
	if(strcmp(op, "^")) return (c^d);
	if(strcmp(op, "!")) return (!a);
	if(strcmp(op, "!=")) return (a!=b);
	if(strcmp(op, "~")) return (~c);
	if(strcmp(op, "+")) return (a+b);
	if(strcmp(op, "-")) return (a-b);
	if(strcmp(op, "*")) return (a*b);
	if(strcmp(op, "**")) return (a<0&&d!=b?err(0):pow(a,b));
	if(strcmp(op, "/")) return (a==0?err(0):a/b);
	if(strcmp(op, "%")) return (c%d);
	return 0;
}
int token(FILE *f){
	char ch=getc(f);
	int ret=0;
	if(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
	}else{
		if(ret==0){

		}else{
			ungetc(ch, f);
		}
	}
	return 0;
}
int prec(char* op){
	if(strchr(",;", op[0])) return 0;
	if(!(strcmp(op, "=")&&strcmp(op, "&=")&&strcmp(op, "|=")&&strcmp(op, "^=")&&
			strcmp(op, "**=")&&strcmp(op, "+=")&&strcmp(op, "-=")&&strcmp(op, "*=")&&strcmp(op, "/=")&&strcmp(op, "%="))) return 1;
	if(!(strcmp(op, "&")&&strcmp(op, "|")&&strcmp(op, "^")&&strcmp(op, "&&")&&strcmp(op, "||"))) return 2;
	if(!(strcmp(op, "$")&&strcmp(op, "==")&&strcmp(op, "!=")&&strcmp(op, ">")&&strcmp(op, ">=")&&strcmp(op, "<")&&strcmp(op, "<="))) return 3;
	if(!(strcmp(op, "+")&&strcmp(op, "-"))) return 5;
	if(!(strcmp(op, "*")&&strcmp(op, "/")&&strcmp(op, "%"))) return 6;
	if(!(strcmp(op, "**"))) return 7;
	if(!(strcmp(op, "!")&&strcmp(op, "~"))) return 8;
	if(strchr("{}[]().", op[0])) return 9;
	return 0;
}
int isRight(char* op){
	if(!strcmp(op, "**")) return 1;
	return 0;
}
int maths(int lhs, int min, FILE *f){
	int lookahead = token(f);
	while(prec(lookahead)>=min){
		int op = lookahead;
		int rhs = token(f);
		lookahead = token(f);
		while(prec(lookahead) > prec(op)||(prec(lookahead)==prec(op)&&isRight(lookahead))){
			rhs=maths(rhs, min + 1, f);
			lookahead = token(f);
		}
		//lhs op= rhs;
	}
	return lhs;
}
void parse_exp(char *f){
	FILE *es=fopen(f, "rt");
	if(es==NULL){
		err(2);
		return;
	}
	chars* root=NULL;
	while(1){
		ch1=getc(es);
		push_c(&root, ch1);
		charnum++;
		if(ch1==EOF) break;
	}
}
