/*
 * TreeInterface.hpp
 *
 *  Created on: Oct 13, 2021
 *      Author: 13027
 */

#ifndef TREEINTERFACE_HPP_
#define TREEINTERFACE_HPP_

#include <iostream>
#include <stdlib.h>
#include "bst.hpp"
using namespace std;

class TreeInterface {
	string fn;
public:
	bst *tree;
	TreeInterface(string filename);
	void readFile();
	void strip(string s,  int *n, string *j);

	void Interface();
//	void addPhrases();
//	void deletePhrases();
//	void printPhrases();

};




#endif /* TREEINTERFACE_HPP_ */
