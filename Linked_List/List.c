/*----------------------------- Private Includes -----------------------------*/
#include "List.h"
#include "__List_struct__.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*--------------------------- Private Includes END ---------------------------*/

/*----------------------------- Private Structs ------------------------------*/
/*--------------------------- Private Structs END ----------------------------*/

/*---------------------------- Exported Functions ----------------------------*/
struct list *List_init_elem_sz(size_t elem_size)
{
   struct list *this = malloc(sizeof (struct list));
   if (this == NULL)
      return NULL;
   this->elem_size = elem_size;
   this->size = 0;
   this->head = NULL;

   return this;
}

void List_destroy(struct list *this)
{
   struct list_node *iter[2];
   int i = 0;

   iter[0] = this->head;
   while (iter[i])
   {
      iter[i ^ 1] = iter[i]->next;
      free(iter[i]);
      i ^= 1;
   }
   free(this);
}

int List_push(struct list *this, void *elem)
{
   struct list_node *new_node;
   new_node = malloc(sizeof(struct list_node) + this->elem_size);
   if (new_node == NULL)
      return 1;
   new_node->next = this->head;
   memcpy(new_node->value, elem, this->elem_size);
   this->head = new_node;
   this->size++;
   return 0;
}

void List_pop(struct list *this)
{
   struct list_node *iter = this->head;
   this->head = iter->next;
   this->size--;
   free(iter);
}

struct list_node *List_head(struct list *this)
{
   return this->head;
}

size_t List_size(struct list *this)
{
   return this->size;
}
/*-------------------------- Exported Functions END --------------------------*/
