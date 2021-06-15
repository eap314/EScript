#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e=0, ch1=0, linenum=1, charnum=0;
int cc(const char* s, int c){
	if(strchr(s,c)>0){
		return 1;
	}
	return 0;
}
int err(){
	if(e==0){
		return 0;
	}
	printf("\nError %i: line %i character %i: ", e, linenum, charnum);
	if(e==1){printf("Division by 0");}
	if(e==2){printf("File fail");}
	if(e==3){printf("Invalid character after '\\': '%c'", ch1);}
	if(e==4){printf("Multiple dots in float");}
	return 1;
}
void lex(char* f){
	FILE* es=fopen(f, "rt");
	if(es==NULL){
		e=2;
		err();
		return;
	}
}
void parse(char* f){
	FILE* es=fopen(f, "rt");
	if(es==NULL){
		e=2;
		err();
		return;
	}
	int ch2=0, str=0, dc=0, var=0, isNum=0, flag=0;
	//char* tvar="";
	while(flag==0){
		if(err()==1){
			break;
		}
		isNum=0;
		ch1=fgetc(es);
		charnum++;
		//char cha=(char)ch;
		if(ch2==1){
			if(cc("\n",ch1)){
				ch2=0;
			}
			continue;
		}if(ch2==92){
			if(cc("n", ch1)){
				ch1=(int)'\n';
			}else if(cc("r", ch1)){
				ch1=(int)'\r';
			}else if(cc("t", ch1)){
				ch1=(int)'\t';
			}else if(cc("\\", ch1)){
				ch1=(int)'\\';
			}else{
				e=3;
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
				ch2=(int)'\\';
				flag=2;
				break;
			case '$':
				var=1;
				break;
			case '.':
				//class loop
				if(isNum==1){
					if(dc==1){
						e=4;
					}
					dc=1;
				}
				break;
			case '+':
				ch2=(int)'+';
				break;
			case '-':
				ch2=(int)'-';
				break;
			case '*':
				ch2=(int)'*';
				break;
			case '/':
				if(ch2==(int)'/'){
					ch2=1;
				}else{
					ch2=(int)'/';
				}
				break;
			case '<':
				ch2=(int)'<';
				break;
			case '>':
				ch2=(int)'>';
				break;
			case '|':
				ch2=(int)'|';
				break;
			case '&':
				ch2=(int)'&';
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
		if(flag==1){
			flag=0;
			break;
		}if(flag==2){
			flag=0;
			continue;
		}
		if(cc("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz", ch1)){
			//strncat(tvar, &cha, 1);
			//var decl
			//var=0
		}
		printf("%c", ch1);
	}
	return;
}
int main(int argc, char *argv[]){
	//argument 1 is argv[1]
	//program name is argv[0]

	//if(strcmp(argv[1], "es")==0){esparse(argv[2]);}
	parse("/users/eap/desktop/c+c/offline/3d/3d.es");
	printf("\n");
	return 0;
}
