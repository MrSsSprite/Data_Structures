#ifndef __QUEUE_ADAPTORS_H
#define __QUEUE_ADAPTORS_H

/*------------------------------ Public Typedef ------------------------------*/
typedef void *Queue_Adaptor;
/**
 * @breif   The Adaptors can also be used as destructor function of themselves
 */
typedef void (*Queue_Adaptor_destructor)(void*);
/*---------------------------- Public Typedef END ----------------------------*/

/*------------------------ Public Function Prototypes ------------------------*/
/**
 * @brief   Linked List to Queue Adaptor
 * @param   list: List object, the underlying container
 * @return  Adaptor object that must be destroyed by calling the corresponding
 *          destructor.
 *          NULL if failed
 * @see     List
 */
void *queue_linked_list_init(void *list);
/*---------------------- Public Function Prototypes END ----------------------*/

/*----------------------------- Public Variables -----------------------------*/
extern const struct queue_toolbox Queue_Linked_List_toolbox;
/*--------------------------- Public Variables END ---------------------------*/

#endif
