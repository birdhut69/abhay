
#include<iostream>
using namespace std;
//creating a node using struct

struct BstNode {
	int data; 
	BstNode* left;//contains left address location
	BstNode* right;//contains right address location
};

// Function to create a new Node in memory location 
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;//returning the address of new node
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // if there is an empty tree then it will create an tree as root Node
		root = GetNewNode(data);//return the address of new NODE
	}
	// if the given data is less then the key value of root node then the data is inserted to the left of the NODE 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// if the value is greater then the key value of root element then the data is inseted to the right of the NODE 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//Function to search the value from the tree 
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
    cout<<"enter the root value";
    int val1;
    cin>>val1;
	root = Insert(root,val1);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true)
    { 
        cout<<"Found\n";
    }
    else 
    {
        cout<<"Not Found\n";
    }
}