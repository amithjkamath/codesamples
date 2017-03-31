
struct node {
	int data;
	node* next;
};

typedef struct node node;

node* initLList(){
	node* root = new node;
	root->data = 0;
	root->next = NULL;
	return root;	
};

node* appendToLList(node* root, int value){
	while(root->next != NULL)
		root = root->next;
	node* addNode = new node;
	addNode->data = value;
	addNode->next = NULL;
	root->next = addNode;
	return root;	
};

int listValueAt(node* root, int index){
	int idx = index;
	if(root->next != NULL)
		root = root->next;
	while(idx > 0){
		if(root->next != NULL){
			root = root->next;
			idx--;
		}
		else{
			std::cerr << "Invalid index: listValueAt" << std::endl;
			return -1;
		}
	}
	return root->data;
};

void insertAt(node* root, int index, int value){
	if((root->next != NULL) && (index != 0))
		root = root->next;
	for(int i = 0; i < index - 1; i++){
		if(root->next != NULL)
			root = root->next;
		else
		{
			std::cerr << "Error: bad index: insertAt LList" << std::endl;
			return;
		}
	}
	node* previousNode = root;
	if(root->next != NULL){
		//Inserting in between two existing nodes.
		node* nextNode = root->next;
		node* newNode = new node;
		previousNode->next = newNode;
		newNode->data = value;
		newNode->next = nextNode;
	}
	else
	{
		//At the end of the chain.
		node* newNode = new node;
		newNode->data = value;
		previousNode->next = newNode;
		newNode->next = NULL;
	}
};

void deleteAt(node* root, int index){
	if((root->next != NULL) && (index != 0))
		root = root->next;

	for(int i = 0; i < index - 1; i++){
		if(root->next != NULL)
			root = root->next;
		else
		{
			std::cerr << "Error: bad index: deleteAt LList" << std::endl;
			return;
		}
	}
	node* previousNode = root;
	if(root->next != NULL)
		root = root->next;
	node* togo = root;
	if(root->next != NULL)
		root = root->next;
	delete togo;
	// This already handles deleting the last node.
	previousNode->next = root;
};

void releaseLList(node* root){
	node* thisNode = root;
	node* nextNode = NULL;
	while(thisNode->next != NULL){
		nextNode = thisNode->next;
		delete thisNode;
		thisNode = nextNode;
	}
};

void printLList(node* root){
	int idx = 0;
	if(root->next != NULL)
		root = root->next;
	std::cout << "{ ";
	while(root->next != NULL){
		std::cout << root->data << ", ";
		idx++;
		root = root->next;
	}
	std::cout << root->data << " } " << std::endl;
};
