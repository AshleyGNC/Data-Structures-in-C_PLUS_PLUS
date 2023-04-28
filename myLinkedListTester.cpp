/*
 * myLinkedListTester.cpp
 *
 *  Created on: Apr 20, 2022
 *      Author: Ashley
 */

#include <iostream>
//#include "console.h"
#include "myLinkedList.h"

using namespace std;


int main() {
	myLinkedList<int> list1;
	cout<< list1 << endl;
	list1.add(-3);
	list1.add(9);
	myLinkedList<int> list2;
	list2.add(4);
	list2.add(17);
	cout << list1 << endl;
	cout << list2 << endl;

	myLinkedList<int> list3 = list1 + list2;
	cout << list3 << endl;
	myLinkedList<string> list4;
	list4.add("Hello");
	list4.add("World");
	list4.add("World");
	list4.remove(1);
	cout << list4 << endl;
	Vector<string> v {"Nice", "to", "meet", "you"};
	myLinkedList<string> list5(v);
	cout << list5 << endl;

	return 0;
}
