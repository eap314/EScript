#include <stdlib.h>
#include <limits.h>

extern void err(int);

typedef struct ints{
	int data;
	struct ints *next;
}ints;
typedef struct chars{
	char data;
	struct chars *next;
}chars;
ints *new_i(int data){
	ints *st=(ints *)malloc(sizeof(ints));
	if(st==NULL) err(1);
	st->data=data;
	st->next=NULL;
	return st;
}
int isEmpty_i(ints *root){
	return !root;
}
void push_i(ints **root, int data){
	ints *st=new_i(data);
	st->next=*root;
	*root=st;
}
int pop_i(ints **root){
	if(isEmpty_i(*root)) return INT_MIN;
	ints *temp=*root;
	*root=(*root)->next;
	int popped=temp->data;
	free(temp);
	return popped;
}
int peek_i(ints *root){
	if(isEmpty_i(root)) return INT_MIN;
	return root->data;
}
chars *new_c(char data){
	chars *st=(chars *)malloc(sizeof(chars));
	if(st==NULL) err(1);
	st->data=data;
	st->next=NULL;
	return st;
}
int isEmpty_c(chars *root){
	return !root;
}
void push_c(chars **root, int data){
	chars *st=new_c(data);
	st->next=*root;
	*root=st;
}
char pop_c(chars **root){
	if(isEmpty_c(*root)) return 0;
	chars *temp=*root;
	*root=(*root)->next;
	char popped=temp->data;
	free(temp);
	return popped;
}
char peek_c(chars *root){
	if(isEmpty_c(root)) return 0;
	return root->data;
}
