
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
		else
			std::cerr << "Invalid index: listValueAt" << std::endl;
	}
	return root->data;
};

void insertAt(node* root, int index, int value){
	if(root->next != NULL)
		root = root->next;
	for(int i = 0; i < index - 1; i++){
		if(root->next != NULL)
			root = root->next;
		else
			std::cerr << "Error: bad index: insertAt LList" << std::endl;
	}
	node* previousNode = root;
	node* nextNode = root->next;
	node* newNode = new node;
	previousNode->next = newNode;
	newNode->data = value;
	newNode->next = nextNode;
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
