/*
 * TreeInterface.cpp
 *
 *  Created on: Oct 13, 2021
 *      Author: 13027
 */


#include "TreeInterface.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


TreeInterface::TreeInterface(string name) {
	fn = name;
	tree = new bst();
	readFile();
}


void TreeInterface::Interface() {
	char c = 'a';
	while (c != 'q') {
		cout <<endl<<"****************************************************"<<endl;
		cout <<"Choose Option:\n  a\tGet Student\n  b\tadd a student\n  c\tremove a student\n  d\tprint tree\n  q\tquit"<< endl;
		cin >> c;
		switch (c) {
		case 'a': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			bstNode *t = tree->find(l,f);
			if (t == NULL) {
				char k;
				cout << f << " " << l <<" not found in database.  " << endl;
			}
			else {
				bstNode *s = tree->find(l,f);
				//s->printNode();
			}
			break;
		}
		case 'b':{
			string lname;
			string fname;
			int num;
			string jk;
			cout << "Enter Last: "<<endl;
			cin >> lname;
			cout << "Enter First: " << endl;
			cin >> fname;
			cout << "Enter favorite number " << endl;
			cin >> num;
			cout << endl << "Enter your favorite joke: ";
			cin.ignore();
			getline(cin, jk);

			if (tree->insert(fname, lname, num, jk)) {
				cout << endl <<fname << "\t" << lname<< " inserted successfully "<<endl;
			}
			else {
				bstNode *t = tree->find(lname,fname);
				t->printNode();
				cout << "... already in tree with " << endl;
			}
			break;
		}
		case 'c': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			bstNode *t = tree->remove(l,f);
			if (t == NULL) {
				cout << endl << f << " " << l << " not in tree " << endl;
			}
			else {
				//t->printNode();
				cout << " ...has been removed. "<<endl;
			}
			break;
		}
		case 'd': {
			cout << "Choose a for pre, b for in, or c for post-order\t";
			char k;
			cin >> k;
			cout << endl;
			cout << "************************************************"<<endl;
			if (k == 'a') {
				cout << "*********** Printing Tree Pre Order ************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePre();
			}
			else if (k == 'b') {
				cout << "*********** Printing Tree In Order *************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreeIO();
			}
			if (k == 'c') {
				cout << "*********** Printing Tree Post Order ***********"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePost();
			}

			break;
		}
		}
	}
}

void TreeInterface::strip(string s, int *n, string *j) {
	const char* WhiteSpace = " \t\n";
	const char* EndChar = "\t\n";
		size_t start = s.find_first_not_of(WhiteSpace);
		//cout << start << endl;
		int len = s.length();
		s = s.substr(start,len-start+1);
		size_t end = s.find_first_of(EndChar);
		//cout << end << endl;

		start = s.find_first_not_of(WhiteSpace);
		len = s.length();
		s = s.substr(start,len-start+1);
		end = s.find_first_of(EndChar);
		int num;
		if (end > 0){
			stringstream k(s.substr(0,end));
			num = 0;
			k>>num;
			s = s.substr(end+1, len-end);
		}

		start = s.find_first_not_of(WhiteSpace);
		len = s.length();
		s = s.substr(start,len-start+1);
		end = s.find_first_of(EndChar);
		if (end > 0){
			*j = s.substr(0,end);
			s = s.substr(end+1, len-end);
		}

	return;

}
void TreeInterface::readFile() {
	ifstream file(fn.c_str());
	string word;
	string phrase;
	string f;
	string l;
	int n;
	string j;
	file >> f;
	while (!file.eof()) {
		file >> l;
		getline(file,phrase);
		//cout << "Read: "<< phrase << endl;
		strip(phrase, &n, &j);
		cout << f << ", " << l << ", " << n << ", "<< j << endl;
		// for testing as I read in - you can comment this out you've gotten things working
		tree->insert(f, l, n, j);
		file >> f;
	}
	tree->printTreeIO();
	return;
}

//	BST *tree;
//	string fn;
//public:
//	Abbr(string filename);

//	AddPhrases();
//	DeletePhrases();
//	PrintPhrases();
//};


