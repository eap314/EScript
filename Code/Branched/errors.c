#include <stdio.h>

extern int ch1, linenum, charnum;

int err(int e){
	printf("\nError %i: line %i character %i: ", e, linenum, charnum);
	if(e==0) printf("Division by 0 or imaginary result");
	if(e==1) printf("Out of memory");
	if(e==2) printf("File fail");
	if(e==3) printf("Invalid character after '\\': '%c'", ch1);
	if(e==4) printf("Multiple dots in float");
	return e;
}
