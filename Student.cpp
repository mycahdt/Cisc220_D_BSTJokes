/*
 * Student.cpp
 *
 *  Created on: Oct 13, 2021
 *      Author: 13027
 */


#include "Student.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


Student::Student() {
	first = "Wendy";
	last = "Adams";
	fav_num = 13;
	joke = "I picked up a hitchhiker the other day. He climbed in and said, 'I'm actually surprised you picked me up.  Weren't you afraid I could be a serial killer?'  I replied, 'Nah, what are the odds of there being 2 serial killers in one car?'";
}
Student::Student(string f, string l, int n, string j){
	first = f;
	last = l;//
	fav_num = n;
	joke = j;
}
