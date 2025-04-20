#ifndef __QUEUE_H
#define __QUEUE_H

/*----------------------------- Public Includes ------------------------------*/
#include <stddef.h>
/*--------------------------- Public Includes END ----------------------------*/

/*------------------------------ Public Structs ------------------------------*/
struct queue_toolbox
{
   int (*enqueue)(void*, void*);
   void (*dequeue)(void*);
   void *(*front)(void*);
   size_t (*size)(void*);
};
struct queue
{
   void *engine;
   const struct queue_toolbox *fn;
};
/*---------------------------- Public Structs END ----------------------------*/

/*------------------------------ Public Typedef ------------------------------*/
typedef struct queue Queue;
/*---------------------------- Public Typedef END ----------------------------*/

/*------------------------------ Public Macros -------------------------------*/
#define Queue_enqueue(this, item) ((this).fn->enqueue((this).engine, (item)))
#define Queue_dequeue(this) ((this).fn->dequeue((this).engine))
#define Queue_front(this) ((this).fn->front((this).engine))
#define Queue_size(this) ((this).fn->size((this).engine))
/*---------------------------- Public Macros END -----------------------------*/

#endif
