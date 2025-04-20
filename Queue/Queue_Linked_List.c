/*----------------------------- Private Includes -----------------------------*/
#include "Queue_Adaptors.h"
#include "Queue.h"
#include "../Linked_List/List.h"
#include "../Linked_List/__List_struct__.h"
#include <stdlib.h>
#include <string.h>
/*--------------------------- Private Includes END ---------------------------*/

/*----------------------------- Private Structs ------------------------------*/
struct queue_linked_list
{
   void (*destructor)(struct queue_linked_list*);
   List container;
   List_Node tail;
};
/*--------------------------- Private Structs END ----------------------------*/

/*---------------------- Private Function Declarations -----------------------*/
static void queue_linked_list_destroy(struct queue_linked_list *this);
static int queue_linked_list_enqueue
(struct queue_linked_list *this, void *elem);
static void queue_linked_list_dequeue(struct queue_linked_list *this);
static void *queue_linked_list_front(struct queue_linked_list *this);
static size_t queue_linked_list_size(struct queue_linked_list *this);
/*-------------------- Private Function Declarations END ---------------------*/

/*---------------------------- Exported Variables ----------------------------*/
const struct queue_toolbox Queue_Linked_List_toolbox =
{
   .enqueue = (void*)queue_linked_list_enqueue,
   .dequeue = (void*)queue_linked_list_dequeue,
   .front = (void*)queue_linked_list_front,
   .size = (void*)queue_linked_list_size,
};
/*-------------------------- Exported Variables END --------------------------*/

/*---------------------------- Exported Functions ----------------------------*/
void *Queue_Linked_List_init(void *list)
{
   List container = list;
   struct queue_linked_list *this = malloc(sizeof(struct queue_linked_list));
   List_Node iter;

   if (this == NULL) return NULL;
   this->container = container;
   iter = container->head;
   if (iter)
   {
      while (iter->next)
         iter = iter->next;
      this->tail = iter;
   }
   else
      this->tail = NULL;
   this->destructor = queue_linked_list_destroy;

   return this;
}
/*-------------------------- Exported Functions END --------------------------*/

/*---------------------------- Private Functions -----------------------------*/
static void queue_linked_list_destroy(struct queue_linked_list *this)
{
   free(this);
}


static int queue_linked_list_enqueue(struct queue_linked_list *this, void *elem)
{
   List_Node new_node;
   int err_code;

   if (this->tail)
   {
      /* Setup new_node */
      new_node = malloc(sizeof(List_Node) + this->container->elem_size);
      if (new_node == NULL) return 1;
      new_node->next = NULL;
      memcpy(new_node->value, elem, this->container->elem_size);

      /* enqueue the new_node */
      this->tail->next = new_node;
      this->tail = new_node;
      this->container->size++;
   }
   else
   {
      err_code = List_push(this->container, elem);
      if (err_code) return err_code;
      this->tail = this->container->head;
   }

   return 0;
}


static void queue_linked_list_dequeue(struct queue_linked_list *this)
{
   List_pop(this->container);
   if (this->container->size == 0) this->tail = NULL;
}


static void *queue_linked_list_front(struct queue_linked_list *this)
{
   return List_head(this->container);
}


static size_t queue_linked_list_size(struct queue_linked_list *this)
{
   return this->container->size;
}
/*-------------------------- Private Functions END ---------------------------*/
