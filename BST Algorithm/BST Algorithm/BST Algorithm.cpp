#include <iostream>
//#include <format>
using namespace std;

struct Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node(int value) : data(value),  left(nullptr), right(nullptr) {}
};

class BST {
	Node* root;
	private:
		Node* node;

		Node* insertion(Node* node, int value) {
			if (node == nullptr) {
				return new Node(value);
			}
			if (value < node->data) {
				node->left = insertion(node->left, value);
			}
			else if (value > node->data) {
				node->right = insertion(node->right, value);
			}
			return node;
		}   

		bool searchNodes(Node* node, int value) {
			if (node == nullptr) { // value nullptr and node->data nullptr => false
				return false;
			}
			if (node->data == value) { // value 9 and node->data 9 => true
				return true;
			}
			else if (value < node->data) { // value 9 and node->data 12 => true
				return searchNodes(node->left, value);
			}
			else { // value 9 and node->data 1 => true
				return searchNodes(node->right, value);
			}
		}

		Node* findMin(Node* node) {
			while(node->left != nullptr) {
				node = node->left;
			}
			return node; 
		}

		Node* findMax(Node* node) {
			while (node->right != nullptr) {
				node = node->right;
			}
			return node;
		}

		Node* deleteNode(Node* node, int value) {
			if (node == nullptr) { return node; }

			if (value < node->data) {
				node->left = deleteNode(node->left, value);
			}
			else if (value > node->data) {
				node->right = deleteNode(node->right, value);
			}
			else {
				if (node->left == nullptr) {
					Node* temp = node->right;
					delete node;
					return temp;
				} else if (node->right == nullptr) {
					Node* temp = node->left;
					delete node;
					return temp;
				}

				Node* temp = findMin(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data);

			}

			return node;
		}

		void inorder(Node* node) {
			if (node==nullptr)return;
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}

		void preorder(Node* node) {
			if (node == nullptr) return;
			cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}

		void postorder(Node* node) {
			if (node == nullptr) return;
			
			postorder(node->left);
			postorder(node->right);
			cout << node->data << " ";
		}

	public:
		BST() : root(nullptr) {}

		void insert(int value) {
			root = insertion(root, value); 
		}
		bool search(int value) { 
			return searchNodes(root, value); 
		}
		void remove(int value) { root = deleteNode(root, value); }
		void infix() {
			inorder(root);
			cout << endl;
		}
		void prefix() {
			preorder(root);
			cout << endl;
		}
		void postfix() {
			postorder(root);
			cout << endl;
		}
};

int main()
{
	BST tree;
	int tcount;
	int val;
	cout << "count of tree : ";
	cin >> tcount;

	cout << "\n";

	for (int i = 0; i <= tcount; i++) {
		cout << "tree values " << i << " : ";
		cin >> val;

		tree.insert(val);
	}

	cout << "inorder (LNR) ";
	tree.infix();

	cout << "\n";

	cout << "preorder (NLR) ";
	tree.prefix();

	cout << "\n";

	cout << "postorder (LRN) ";
	tree.postfix();

	cout << "\n";
	cout << "search in bst";

	int x;
	cin >> x;
	cout << "search " << x << ": " << (tree.search(x) ? "Found" : "Not Found") << endl;

	return 0;
}








