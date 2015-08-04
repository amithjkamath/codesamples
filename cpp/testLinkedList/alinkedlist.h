
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
	return NULL;
};
