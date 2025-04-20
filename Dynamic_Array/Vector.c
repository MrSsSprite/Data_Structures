/*----------------------------- Private Includes -----------------------------*/
#include "Vector.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*--------------------------- Private Includes END ---------------------------*/

/*----------------------------- Private Structs ------------------------------*/
struct vector
{
   void *st, *cav, *ed;
   size_t elem_sz;
};
/*--------------------------- Private Structs END ----------------------------*/

/*---------------------------- Exported Functions ----------------------------*/
struct vector *Vector_init_elem_sz(size_t elem_sz)
{
   struct vector *this = malloc(sizeof(struct vector));
   
   if (this == NULL)
      return NULL;

   this->elem_sz = elem_sz;
   this->st = this->cav = this->ed = NULL;

   return this;
}

void Vector_destroy(struct vector *this)
{
   free(this->st);
   free(this);
}

int Vector_push(struct vector *this, void *item)
{
}
/*-------------------------- Exported Functions END --------------------------*/

/*---------------------------- Private Functions -----------------------------*/
static struct vector *resize(struct vector *this, size_t new_size)
{
   if (new_size == 0)
   {
      free(this->st);
      return 0;
   }
}
/*-------------------------- Private Functions END ---------------------------*/
