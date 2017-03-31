#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void addToList(struct node* list, int pos, int value);

void printList(struct node* nodeRoot);

void resizeList(struct node* nodeRoot, int newSize);

void removeAt(struct node* nodeRoot, int pos);

int main(int argc, char* argv[])
{
	// head node.
	struct node* root = NULL;
	
	// Create a node by calling malloc, and assign root to point to it.
	root = (struct node*) malloc(sizeof(struct node));

	// started empty, so that we make sure it's length is 0.
	root->data = 0;
	root->next = NULL;	
	
	// now we use the function to add data.
	addToList(root, 1, 13);
	addToList(root, 0, 9);
	addToList(root, 5, 16);
	removeAt(root, 5);
	addToList(root, 15, 15);
	resizeList(root, 7);
	// now we will traverse through the linked list and get the data stored in a loop.
	// assign the link pointer to the starting of the list.
	printList(root);
	
	return 0;
}

void addToList(struct node* listRoot, int pos,  int value)
{
	struct node* temp = listRoot;
	int i = 0;
	for(i = 0; i < pos; i++)
	{
		if(temp->next == NULL) // if the list is not as long as pos, create the list on the fly.
		{
			//create a new container called here.
			struct node* here = (struct node*)malloc(sizeof(struct node));
			// set the data to default 0.
			here->data = 0;
			// point next field of temp (which is already in the list) to here.
			temp->next = here;
			// to maintain the conditions to come here, make here's next Null.
			here->next = NULL;
		}
		temp = temp->next;
	}
	if(pos == 0) // this is to take into account pos == 0, where temp is identically equal to listRoot.
	{
		temp = listRoot;
	}
	temp->data = value;
}

void printList(struct node* nodeRoot)
{
	struct node* link = nodeRoot;
	int i = 0;
	while(link->next != 0) // until the next field of the pointer is not null
	{
		printf("The %d th element of the list is %d\n",i,link->data);
		link = link->next;
		i++;
	}
	printf("The %d th element of the list is %d\n",i,link->data);
}

void resizeList(struct node* nodeRoot, int newSize)
{
	int i = 1; //since we are jumping n-1 times for the nth element.
	for(i = 1; i < newSize; i++)
	{
		nodeRoot = nodeRoot->next;
	}
	nodeRoot->next = NULL;
}

void removeAt(struct node* nodeRoot, int pos)
{
	int i = 0;
	for(i = 0; i < pos-1; i++)
	{
		nodeRoot = nodeRoot->next;
	}
	nodeRoot->next = (nodeRoot->next)->next; //skip that node.
}

// manual adding of elements. note the (link->next)->next sequence.
	//// add data into the linked list by putting 5 into the data field of root.
	//root->data = 5;
	
	//// if there are no more elements in the list, enter 0 for the address of the next field.
	//root->next = 0;
	
	// //to add another link to the list, create a new memory block using malloc again.
	// struct node* link = (struct node*)malloc(sizeof(struct node));
	
	// // point the next pointer in root to link
	// root->next = link;
	
	// // and add data into link by looking into the data field.
	// link->data = 6;
	
	// //end the list here by giving the next address to be null.
	// link->next = 0;
	
	// //to add another link to the list, create a new memory block using malloc again.
	// link = (struct node*)malloc(sizeof(struct node));
	
	// // point the next pointer in root to link
	// (root->next)->next = link;
	
	// // and add data into link by looking into the data field.
	// link->data = 7;
	
	// //end the list here by giving the next address to be null.
	// link->next = 0;
	
	// //to add another link to the list, create a new memory block using malloc again.
	// link = (struct node*)malloc(sizeof(struct node));
	
	// // point the next pointer in root to link
	// ((root->next)->next)->next = link;
	
	// // and add data into link by looking into the data field.
	// link->data = 8;
	
	// //end the list here by giving the next address to be null.
	// link->next = 0;