#include "link_basics.h"

/*	Reverse the alternate nodes 
	and append at the end eg:
	Input : 1->2->3->4->5->6
	Output: 1->3->5->6->4->2
*/


void
reverse_alternate(List *l)
{
	NODE curr, end, rev;
	curr = l->head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	end = curr;
	curr = l->head;
	while(curr->next != end && curr != end){
		rev = curr->next;
		curr->next = curr->next->next;
		rev->next = end->next;
		end->next = rev;
		curr = curr->next;
	}
}


int main(int argc, char const *argv[])
{
	List l;
	CreateList(&l);
	CustomList(&l);
	PrintList(&l);
	NODE curr;
	
	reverse_alternate(&l);
	PrintList(&l);
	return 0;
}
