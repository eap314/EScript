#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//lines and characters
int lin=1;
int cha=0;
//simple strchr
int cc(const char* s, int c){if(strchr(s,c)>0){return 1;}return 0;}
//errors
int e=0;
int err(){
	if(e==0){return 0;}
	printf("\nError %i: line %i character %i: ", e, lin, cha);
	if(e==1){printf("?/0");}
	if(e==2){printf("File fail");}
	if(e==3){printf("Invalid token after '\\'");}
	return 1;
}//parse EScript file
void esparse(char* f){
	FILE* es=fopen(f, "rt");
	if(es==NULL){e=2;err();return;}
	int ch=0;
	int str=0;
	int s=0;
	int dc=0;
	int var=0;
	char* tvar="";
	while(1){
		ch=fgetc(es); //get character
		if(ch==EOF){break;}
		//string check
		if(cc("\"", ch)){
			if(str==0){str=1;}else if(str==1){str=0;}
		}if(cc("\'", ch)){
			if(str==0){str=2;}else if(str==2){str=0;}
		}if(cc("\n", ch)){lin++;cha=0;continue;}
		if((cc("\t ", ch))&&str==0){continue;}
		//escape check
		if(s==1){
			if(cc("n", ch)){
				ch=(int)'\n';
			}else if(cc("t", ch)){
				ch=(int)'\t';
			}else if(cc("\\", ch)){
				ch=(int)'\\';
			}else{e=3;}s=0;
		}
		if(cc("\\", ch)){s=1;continue;}
		//letter check
		if(cc("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm", ch)){
			//tvar append ch
			//var decl
			//var=0
		}if(cc("$", ch)){
			var=1;
		}//math
		if(cc("1234567890", ch)){
		}if(cc(".", ch)){
			dc=1;
		}if(cc("+", ch)){
		}if(cc("-", ch)){
		}if(cc("*", ch)){
		}if(cc("/", ch)){
		}
		cha++;if(err()==1){break;}
		printf("%c", ch);
	}
	return;}
int main(int argc, char *argv[]){
	//argument 1 is argv[1]
	//program name is argv[0]

	//if(strcmp(argv[1], "es")==0){esparse(argv[2]);}
	esparse("/users/eap/desktop/c+c/offline/3d/3d.es");
	printf("\n");
	return 0;
}
