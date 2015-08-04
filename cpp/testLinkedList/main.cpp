#include <iostream>
#include <alinkedlist.h>

int main()
{
	node* root = initLList(5);
	
	appendToLList(root, 5);
	appendToLList(root, 6);

	printLList(root);

	appendToLList(root, 7);
	appendToLList(root, 18);

	printLList(root);
	
	appendToLList(root, 9);
	appendToLList(root, 30);

	std::cout << "Value at index 4 is " << listValueAt(root, 4) << std::endl;

	releaseLList(root);

	return 0;
}
