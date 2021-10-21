#include <iostream>
using namespace std;

template <typename TData> class BSTree {
public:
	struct node {
		TData data;
		node* left;
		node* right;
	};

	typedef struct node node;

	BSTree() {};
	~BSTree() {};

	node * root = NULL;

	void add(TData);
	void search(TData);
	void printInOrder(node* root);
	void printPostOrder(node* root);
	void printPreOrder(node* root);

private:
	node * _newNode(TData);
	node* _add(node*, TData);

};

// private methods
template <typename TData> 
typename BSTree<TData>::node* BSTree<TData>::_newNode(TData data) {
	node * newNode = new node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

template <typename TData> 
typename BSTree<TData>::node* BSTree<TData>::_add(node* root, TData data) {
	if (root == NULL) {
		root = _newNode(data);
	}
	else if (data < root->data)
		root->left = _add(root->left, data);
	else if (data > root->data)
		root->right = _add(root->right, data);
	return root;
}

template <typename TData> 
void BSTree<TData>::printInOrder(node * root) {
	if (root != NULL) {
		printInOrder(root->left);
		cout << root->data << " ";
		printInOrder(root->right);
	}
}

template <typename TData>
void BSTree<TData>::printPreOrder(node * root) {
	if (root != NULL) {
		cout << root->data << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

template <typename TData> 
void BSTree<TData>::printPostOrder(node * root) {
	if (root != NULL) {
		printInOrder(root->left);
		printInOrder(root->right);
		cout << root->data << " ";
	}
}

template <typename TData> 
void BSTree<TData>::add(TData data) {

	root = _add(root, data);
}

int test_integers() {
	BSTree<int> tree;
	tree.add(6);
	tree.add(4);
	tree.add(8);
	tree.add(2);
	tree.add(5);
	tree.add(7);
	tree.add(9);

	cout << "\nTesting Integer PreOrder: "; tree.printPreOrder(tree.root);
	return 0;
}

int test_floats() {
	BSTree<float> tree;
	tree.add(6.3);
	tree.add(4.4);
	tree.add(8);
	tree.add(2);
	tree.add(5);
	tree.add(7.2);
	tree.add(9);

	cout << "\nTesting Float PostOrder: "; tree.printPostOrder(tree.root);
	return 0;
}

void main() {
	test_integers();
	test_floats();
	getchar();
}
