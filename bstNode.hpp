/*
 * bstNode.hpp
 *
 *  Created on: Oct 27, 2021
 *      Authors: Mycah Detorres and Karl Antonio
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_

#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Student.hpp"

class bst;

class bstNode{
	friend class bst;
	friend class Student;
	friend class TreeInterface;
	bstNode *left;
	bstNode *right;
	bstNode *parent;
	int height;
	Student *student;
public:

	bstNode();
	bstNode(string f, string l, int n, string j);
	~bstNode();
	void printNode();
};



#endif /* BSTNODE_HPP_ */
