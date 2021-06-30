//I'm making a new parser in the oparse file
#include <stdio.h>
#include <stdlib.h>

extern int ch1, linenum, charnum;
extern int err(int);

void parse(char *f){
	FILE *es=fopen(f, "rt");
	if(es==NULL){
		err(2);
		return;
	}
	int ch2=0, str=0, dc=0, var=0, isNum=0, flag=0;
	//char* tvar="";
	while(!flag){ // Break or continue flag
		isNum=0;
		ch1=fgetc(es);
		charnum++;
		//char cha=(char)ch;
		if(ch2==256){
			if(ch1=='\n') ch2=0;
			continue;
		}if(ch2==92){
			if(ch1=='n'){
				ch1='\n';
			}else if(ch1=='r'){
				ch1='\r';
			}else if(ch1=='t'){
				ch1='\t';
			}else if(ch1=='\\'){
				ch1='\\';
			}else{
				err(3);
				break;
			}
			ch2=0;
			continue;
		}
		switch(ch1){
			case EOF:
				flag=1;
				break;
			case '\"':
				if(str==0){
					str=1;
				}else if(str==1){
					str=0;
				}
				break;
			case '\'':
				if(str==0){
					str=2;
				}else if(str==2){
					str=0;
				}
				break;
			case '\n':
				flag=2;
				linenum++;
				charnum=0;
				break;
			case '\t':
				if(str==0){
					flag=2;
				}
				break;
			case ' ':
				if(str==0){
					flag=2;
				}
				break;
			case '\\':
				ch2='\\';
				flag=2;
				break;
			case '$':
				var=1;
				break;
			case '.':
				//class loop
				if(isNum==1){
					if(dc==1){
						err(4);
						flag=1;
					}
					dc=1;
				}
				break;
			case '+':
				ch2='+';
				break;
			case '-':
				ch2='-';
				break;
			case '*':
				ch2='*';
				break;
			case '/':
				if(ch2=='/'){
					ch2=256;
				}else{
					ch2='/';
				}
				break;
			case '<':
				ch2='<';
				break;
			case '>':
				ch2='>';
				break;
			case '|':
				ch2='|';
				break;
			case '&':
				ch2='&';
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				isNum=1;
				break;
		}
		if(flag==1) break;
		if(flag==2){
			flag=0;
			continue;
		}
		if((ch1>='a'&&ch1<='z')||(ch1>='A'&&ch1<='Z')){
			//strncat(tvar, &ch1, 1);
			//var decl
			//var=0
		}
		printf("%c", ch1);
	}
	fclose(es);
	return;
}
