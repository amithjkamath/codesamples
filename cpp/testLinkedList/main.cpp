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
	
	appendToLList(root, 9);
	appendToLList(root, 30);
	
	printLList(root);
	
	insertAt(root, 4, 44);
	insertAt(root, 5, 55);

	printLList(root);

	std::cout << "4, " << listValueAt(root, 4) << std::endl;
	std::cout << "1, " << listValueAt(root, 1) << std::endl;
	std::cout << "0, " << listValueAt(root, 0) << std::endl;
	std::cout << "7, " << listValueAt(root, 7) << std::endl;

	releaseLList(root);

	return 0;
}
