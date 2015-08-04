
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
	while(root->next != NULL){
		std::cout << "Value at index: " << idx << " is " << root->data << std::endl;
		idx++;
		root = root->next;
	}
};
