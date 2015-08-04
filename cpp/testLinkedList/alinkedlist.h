
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
