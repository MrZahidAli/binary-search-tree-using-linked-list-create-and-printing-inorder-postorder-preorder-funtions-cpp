//(BST) Binary search tree using linked list

#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *left, *right;
};
class linkList{
	public:
		node *root;
	public:
		linkList(){
			root = NULL;
		}
//creating BST
		void creatList(int value){
			node *temp = new node;
			node *copyRoot = root;
			temp -> data = value;
			temp -> left = NULL;
			temp -> right = NULL;
			if(root == NULL){
				root = temp;
				copyRoot = temp;
			}
			else{
				while(copyRoot != NULL ){
					if(temp -> data < copyRoot -> data){
						if(copyRoot -> left == NULL){
							copyRoot -> left = temp;
							return;
						}else{
							copyRoot = copyRoot -> left;
						}
					}else{
						if(copyRoot -> right == NULL){
							copyRoot -> right = temp;
							return;
						}else{
							copyRoot = copyRoot -> right;
						}
					}
				}
			}
			
		}
//printing BST in inorder
		void printInorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				cout << temp -> data;
				printInorder(temp -> right);
			}
		}
//printing BST in postorder
		void printPostorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				printInorder(temp -> right);
				cout << temp -> data;
			}
		}
//printing BST in preorder
		void printPreorder(node *temp){
			if(temp != NULL){
				cout << temp -> data;
				printInorder(temp -> left);
				printInorder(temp -> right);
			}
		}
};
int main(){
	linkList B;
	B.creatList(5);
	B.creatList(3);
	B.creatList(4);
	B.creatList(1);
	B.creatList(7);
	B.creatList(6);
	cout << endl << "inorder list: ";
	B.printInorder(B.root);
//	cout << endl << "postorder list: ";
//	B.printPostorder(B.root);
//	cout << endl << "preorder list: ";
//	B.printPreorder(B.root);
	return 0;
}
