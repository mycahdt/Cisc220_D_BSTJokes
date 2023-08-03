//============================================================================
// Name        : BSTJokes.cpp
// Author      : Mycah Detorres and Karl Antonio
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "bstNode.hpp"
#include <iostream>
using namespace std;

bstNode::bstNode(){
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 0;
	student = NULL;
}

bstNode::bstNode(string f, string l, int n, string j){
	student = new Student(f, l, n, j);
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
}

bstNode::~bstNode(){
	delete student;
	cout << "Destroying: " << student->first << endl;
}

void bstNode::printNode(){
	cout << "Student: " << student->first << " " << student->last << ", Height: " << height << endl;
	cout << "Favorite Number: " << student->fav_num << endl;
	cout << "Joke: " << student->joke << endl;
	cout << "*************************************" << endl;
}

