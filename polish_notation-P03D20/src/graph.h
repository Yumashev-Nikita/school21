#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "draw_module/draw.h"
#include "stack_module/stack.h"
#include "defs.h"

#define _VALID_INPUT_ "0123456789+-*/^sinqrtcostgln()x\n\0"

void _ATLAS_();
void st_copy(stack* from, stack** to);
char* read_line();
stack* parse(char* line);
void print_switch(int code);
void binary_parse(stack** output, stack** operas, char symb);
void binary_while(stack** output, stack** operas, char symb);
int switcheroo(char symb);
void reverse(stack** rev_output, stack** output);
int C01(stack** output, stack** operas, char symb);
int C02(stack** output, stack** operas, char* line, char symb, int *i);
int C03(stack** output, stack** operas, char symb);
int C04(stack** output, stack** operas, char symb);
int C05(stack** operas, char symb);
int C06(stack** output, stack** operas);
int C07(stack** operas, char symb);
int C08(stack** operas, char** line, int *i);
int C09(stack** operas, char** line, int *i);
int C10(stack** operas, char** line, int *i);
int C11(stack** operas, char** line, int *i);
int C12(stack** output, char symb);
int C13(stack** output, char* line, char symb, int *i);

#endif  //  SRC_GRAPH_H_
