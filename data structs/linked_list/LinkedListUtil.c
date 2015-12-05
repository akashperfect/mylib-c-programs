#ifndef LINKEDLISTUTIL_H_INCLUDED
#define LINKEDLISTUTIL_H_INCLUDED
#include "Linkops.h"

/*	function to break the linked list in two parts
	where alternate nodes are in separate list
	eg 1->2->3->4->5->6->7
	list 1: 1->3->5->7
	list 2: 2->4->6
*/

void
ll_break_alternate_node(NODE *start, NODE *temp)
{
	if(*start == NULL){
		printf("Starting List pointer is NULL\n");
		return ;
	}
	NODE odd = *start, even = (*start)->next;
	*temp = even;
	while(odd != NULL || even != NULL){
		odd->next = odd->next->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}
	if(odd == NULL){
		even->next = NULL;
	}
	if(even == NULL){
		odd->next = NULL;
	}
}

#endif