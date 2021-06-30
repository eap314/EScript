#ifndef STACK_H_
#define STACK_H_

typedef struct ints ints;
typedef struct chars chars;
ints *new_i(int);
int isEmpty_i(ints *);
void push_i(ints **, int);
int pop_i(ints **);
int peek_i(ints *);
chars *new_c(char);
int isEmpty_c(chars *);
void push_c(chars **, char);
char pop_c(chars **);
char peek_c(chars *);

#endif /* STACK_H_ */
