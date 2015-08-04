#include <iostream>
#include <alinkedlist.h>

int main()
{
	node* root = initLList();
	std::cout << "root data: " << root->data << std::endl;
	std::cout << "root next: " << root->next << std::endl;

	return 0;
}
