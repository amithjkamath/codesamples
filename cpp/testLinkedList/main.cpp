#include <iostream>
#include <alinkedlist.h>

int main()
{
	node* root = initLList();
	
	appendToLList(root, 5);
	appendToLList(root, 6);

	printLList(root);

	appendToLList(root, 7);
	appendToLList(root, 18);

	printLList(root);

	releaseLList(root);
	return 0;
}
