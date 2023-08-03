/*
 * Student.hpp
 *
 *  Created on: Oct 13, 2021
 *      Author: 13027
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <stdlib.h>
#include <iostream>
using namespace std;

class Student {
	friend class bstNode;
	friend class TreeInterface;
	friend class bst;
	string first;
	string last;
	int fav_num;
	string joke;
public:
	Student();
	Student(string f, string l, int n, string j);
};



#endif /* STUDENT_HPP_ */
