#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lin=1;
int cha=0;
int e=0;
int err(){
	if(e==0){return 0;}
	printf("\nError %i: line %i character %i: ", e, lin, cha);
	if(e==1){printf("?/0");}
	if(e==2){printf("File fail");}
	if(e==3){printf("Invalid token after '\\'");}
	return 1;
}
void esparse(char* f){
	FILE* es=fopen(f, "rt");
	if(es==NULL){e=2;err();return;}
	int ch=0;
	int str=0;
	int s=0;
	while(1){
		ch=fgetc(es);
		if(ch==EOF){break;}
		if(strchr("\"", ch)>0){
			if(str==0){str=1;}else if(str==1){str=0;}
		}if(strchr("\'", ch)>0){
			if(str==0){str=2;}else if(str==2){str=0;}
		}if(strchr("\n", ch)>0){lin++;cha=0;continue;}
		if((strchr("\t ", ch)>0)&&str==0){continue;}
		if(s==1){
			if(strchr("n", ch)>0){
				ch=(int)'\n';
			}else if(strchr("t", ch)>0){
				ch=(int)'\t';
			}else if(strchr("\\", ch)>0){
				ch=(int)'\\';
			}else{e=3;}s=0;
		}
		if(strchr("\\", ch)>0){s=1;continue;}
		if(strchr("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm", ch)>0){
		}if(strchr("$", ch)>0){
		}//math
		if(strchr("1234567890", ch)>0){
		}if(strchr("+", ch)>0){
		}if(strchr("-", ch)>0){
		}if(strchr("*", ch)>0){
		}if(strchr("/", ch)>0){
		}
		cha++;if(err()==1){break;}
		printf("%c", ch);
	}
	return;}
int main(void){
	esparse("/users/eap/desktop/C+C/offline/3d/3d.es");
	return 0;
}
