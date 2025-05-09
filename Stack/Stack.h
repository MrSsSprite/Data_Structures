#ifndef __STACK_H
#define __STACK_H

/*----------------------------- Public Includes ------------------------------*/
#include <stddef.h>
/*--------------------------- Public Includes END ----------------------------*/

/*------------------------------ Public Structs ------------------------------*/
struct stack_toolbox
{
   int (*push)(void*, const void*restrict);
   void (*pop)(void*);
   void *(*top)(void*);
   size_t (*size)(void*);
};
struct stack
{
   void *engine;
   struct stack_toolbox *fn;
};
/*---------------------------- Public Structs END ----------------------------*/

/*------------------------------ Public Typedef ------------------------------*/
typedef struct stack Stack;
/*---------------------------- Public Typedef END ----------------------------*/

/*------------------------------- Public Macro -------------------------------*/
#define stack_push(this, item) ((this).fn->push((this).engine, (item)))
#define stack_pop(this) ((this).fn->pop((this).engine))
#define stack_top(this) ((this).fn->top((this).engine))
#define stack_size(this) ((this).fn->size((this).engine))
/*----------------------------- Public Macro END -----------------------------*/

#endif
