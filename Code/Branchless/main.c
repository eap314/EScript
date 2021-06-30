#include <stdlib.h>
#include <string.h>

extern void parse(char *);

void cpy(char **str, char *txt){
	*str=(char *)malloc(strlen(txt)+1);
	strcpy(*str, txt);
}
int main(int argc, char *argv[]){
	//argument 1 is argv[1]
	//program name is argv[0]

	//if(!strcmp(argv[1], "ql")){parse(argv[2]);}

	parse("/users/eap/desktop/c+c/offline/3d/main.ql");
	return 0;
}
