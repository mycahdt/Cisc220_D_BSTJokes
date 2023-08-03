/*
 * bst.cpp
 *
 *  Created on: Oct 27, 2021
 *      Authors: Mycah Detorres and Karl Antonio
 */



#include "bst.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

bst::bst() {  // empty constructor
    root = NULL;
}


bst::bst(string f, string l, int n, string j){
	root = new bstNode(f, l, n, j);
}


bool bst::insert(string f, string l, int n, string j){

	bstNode* currentNode = root;
	bstNode* parentNode = NULL;
	bool flag = true;

	if (root == NULL) {
		root = new bstNode(f,l,n,j);
	    return true;
	}
	while (currentNode != NULL) {
		parentNode = currentNode;
		if (currentNode->student->last != l) {
			if (l < currentNode->student->last) {
				currentNode = currentNode->left;
				flag = true;
			} else {
				currentNode = currentNode->right;
				flag = false;
			}
		} else if (currentNode->student->first != f) {
			if (f < currentNode->student->first) {
				currentNode = currentNode->left;
				flag = true;
			} else {
				currentNode = currentNode->right;
				flag = false;
			}
		} else {
			return false;
		}
	}

	if (flag) {
		parentNode->left = new bstNode(f,l,n,j);
		parentNode->left->parent = parentNode;
		setHeight(parentNode->left);
	} else {
		parentNode->right = new bstNode(f,l,n,j);
		parentNode->right->parent = parentNode;
		setHeight(parentNode->right);
	}

	return true;

}



bstNode *bst::find(string l, string f){

	if(root == NULL){
		return NULL;
	} else {
		bstNode *currentNode = root;
		while(currentNode != NULL){
			if(l < currentNode->student->last) {
				if(currentNode->left == NULL){
					return NULL;
				} else {
					currentNode = currentNode->left;
				}
			} else if (l > currentNode->student->last) {
				if(currentNode->right == NULL){
					return NULL;
				} else {
					currentNode = currentNode->right;
				}
			} else if (l == currentNode->student->last){
				if(f == currentNode->student->first){
					currentNode->printNode();
					return currentNode;
				} else if (f < currentNode->student->first){
					if(currentNode->left == NULL){
						return NULL;
					} else {
						currentNode = currentNode->left;
					}
				} else if(f > currentNode->student->first) {
					if(currentNode->right == NULL){
						return NULL;
					} else {
						currentNode = currentNode->right;
					}
				}
			} else {
				return NULL;
			}
		}
	}
	return NULL;
}





void bst::printTreeIO() {  // Just the start – you must write the recursive version
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void bst::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void bst::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}




void bst::printTreeIO(bstNode *n){
	if(n==NULL){
		return;
	} else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void bst::printTreePre(bstNode *n){
	if(n==NULL){
		return;
	} else {
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void bst::printTreePost(bstNode *n){
	if(n==NULL){
		return;
	} else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}





void bst::clearTree() {  	//clears out an old tree
//This calls the recursive clearTree with the root node
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void bst::clearTree(bstNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}




bstNode *bst::remove(string l, string f){




	bstNode *target = find(l, f);


	if(target == NULL || root == NULL){
		return NULL;
	}

	if(target->left == NULL && target->right == NULL){
		return removeNoKids(target);
	} else if (target->right != NULL && target->left == NULL){
		return removeOneKid(target, false);
	} else if (target->left != NULL && target->right == NULL){
		return removeOneKid(target, true);
	} else {


		bstNode *replacement = target->left;

		bool flag = true;
		while (flag){
			if (replacement->right != NULL){
				replacement = replacement->right;
			} else {
				flag = false;
			}
		}



		target->student->last = replacement->student->last;
		target->student->first = replacement->student->first;
		target->student->fav_num = replacement->student->fav_num;
		target->student->joke = replacement->student->joke;



		if(replacement->left != NULL){
			return removeOneKid(replacement, true);
		} else {
			return removeNoKids(replacement);
		}


		return target;


	}


	return NULL;
}








bstNode *bst::removeNoKids(bstNode *tmp){


	bstNode *removed = tmp;
	if(tmp != root){
		if(tmp->parent->left == tmp) {
			tmp->parent->left = NULL;
		} else {
			tmp->parent->right = NULL;
		}
	}
	delete tmp;
	return removed;


}




bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){


	bstNode *removed = tmp;
	if(tmp->parent->left == tmp) {
		if(leftFlag) {
			tmp->parent->left = tmp->left;
			tmp->left->parent = tmp->parent;
		} else {
			tmp->parent->left = tmp->right;
			tmp->right->parent = tmp->parent;
		}
	} else if (tmp->parent->right == tmp) {
		if(leftFlag) {
			tmp->parent->right = tmp->left;
			tmp->left->parent = tmp->parent;
		} else {
			tmp->parent->right = tmp->right;
			tmp->right->parent = tmp->parent;
		}
	}

	delete tmp;
	return removed;


}



void bst::setHeight(bstNode *n){
	n->height = 1;
	bool flag = true;

		while(flag && n!=NULL && n!= root){   //if n->parent->right->height + 1 == n->parent->height then you can stop

			if(n->parent->left != NULL && n->parent->right != NULL){
				if(n->parent->right->height > n->parent->left->height){

					if(n->parent->right->height + 1 != n->parent->height){
						n->parent->height = n->parent->right->height + 1;
						n = n->parent;
					} else{
						flag = false;
					}

				} else {

					if(n->parent->left->height + 1 != n->parent->height){
						n->parent->height = n->parent->left->height + 1;
						n = n->parent;
					} else{
						flag = false;
					}

				}
			} else {
				if(n->parent->left == NULL){

					if(n->parent->right->height + 1 != n->parent->height){
						n->parent->height = n->parent->right->height + 1;
						n = n->parent;
					} else{
						flag = false;
					}

				} else {

					if(n->parent->left->height + 1 != n->parent->height){
						n->parent->height = n->parent->left->height + 1;
						n = n->parent;
					} else{
						flag = false;
					}

				}
			}
		}


}





