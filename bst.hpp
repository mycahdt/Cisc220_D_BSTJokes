/*
 * bst.hpp
 *
 *  Created on: Oct 13, 2021
 *      Author: 13027
 */

#ifndef bst_HPP_
#define bst_HPP_


#include "bstNode.hpp"

class bst {
	friend class bstNode;
	bstNode *root;

public:
	bst();
	bst(string f, string l, int n, string j);
	bool insert(string f, string l, int n, string j);
	bstNode *find(string l, string f);
	void printTreeIO();
	void printTreeIO(bstNode *n);
	void printTreePre();
	void printTreePre(bstNode *n);
	void printTreePost();
	void printTreePost(bstNode *n);
	void clearTree();
	void clearTree(bstNode *tmp);
	bstNode *removeNoKids(bstNode *tmp);
	bstNode *removeOneKid(bstNode *tmp, bool leftFlag);
	bstNode *remove(string f, string l);
	void setHeight(bstNode *n);


	/******************New for AVL ***************************/
	//int getBalance(bstNode *tmp);
	//TNode *rotateRight(TNode *tmp);
	//TNode *rotateLeft(TNode *tmp);
};



#endif /* bst_HPP_ */
