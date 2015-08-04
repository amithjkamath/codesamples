#include <iostream>
#include <alinkedlist.h>

int main()
{
	node* root = initLList();
	node* nextVal = new node;
	nextVal->data = 5;
	root->next = nextVal;
	nextVal->next = NULL;
	std::cout << "root data: " << root->data << std::endl;
	std::cout << "root next: " << root->next << std::endl;

	std::cout << "next addr: " << nextVal << std::endl;

	std::cout << "next data: " << nextVal->data << std::endl;
	std::cout << "next next: " << nextVal->next << std::endl;

	releaseLList(root);
	return 0;
}
