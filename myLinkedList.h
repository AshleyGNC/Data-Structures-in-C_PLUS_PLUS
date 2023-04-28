/*
 * myLinkedList.h
 *
 *  Created on: Apr 20, 2022
 *      Author: Ashley
 */

#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_


#pragma once

#include <sstream>
#include <iostream>
#include "ListIntNode.h"
#include "vector.h"
#include <sstream>
using namespace std;

template <typename T>
class myLinkedList {
public:
	myLinkedList();
	myLinkedList(Vector<T>& v);
    string toString() const;
    void add(const T& value);
    void remove(int index);
    myLinkedList<T> operator +(const myLinkedList<T>& list2);

private:
    ListNode<T>* front;
};
template <typename T>
ostream& operator <<(ostream& out, myLinkedList<T>& list);

template <typename T>
myLinkedList<T>::myLinkedList() {
	// empty linkedlist
	front = nullptr;
}

template <typename T> //good
myLinkedList<T>::myLinkedList(Vector<T>& v) {
	if (v.size() == 0){
		front = nullptr;
	}else{
		ListNode<T> *head = new ListNode<T>(v[0], nullptr);
		ListNode<T> *prev = head;
		for (int i = 1; i < v.size(); i++) {
			ListNode<T> *node = new ListNode<T>(v[i], nullptr);
			prev->next = node;
			prev = node;
		}
		front = head;
	}
}

template <typename T> //good
string myLinkedList<T>::toString() const {
	if(front == nullptr){
		return "(this is an empty list)";
	}

	ostringstream out;
	out << "[";
	ListNode<T> *curr = front;
	while (curr != nullptr){
		out << curr->val << " ";
		curr = curr->next;
	}
	out << "]";
	return out.str();
/*

	string toReturn = "";
	ListNode<T> *curr = front;
	while (curr != nullptr){
		ostringstream out;
		T data = curr->val;
		out << data << " ";
		toReturn += out.str();
		curr = curr->next;
	}
	return toReturn;*/
}


template <typename T> //good
void myLinkedList<T>::add(const T& value) {
	    ListNode<T> *newNode = new ListNode<T>(value, nullptr);
	    if (front == nullptr) {
	        front = newNode;
	    } else {
	        ListNode<T>* current = front;
	        while (current->next != nullptr) {
	            current = current->next;
	        }
	        current->next = newNode;
	    }
}


template <typename T>
void myLinkedList<T>::remove(int index) {
	ListNode<T>* nodeToDelete = nullptr;
	    if (index == 0) {
	        nodeToDelete = front;
	        front = front->next;
	        delete nodeToDelete;
	    } else {
	        ListNode<T>* current = front;
	        for (int i = 0; i < index - 1; i++) {
	            current = current->next;
	        }

	        nodeToDelete = current->next;
	        current->next = current->next->next;
	        delete nodeToDelete;
	    }

}

template <typename T>
myLinkedList<T> myLinkedList<T>::operator +(const myLinkedList<T>& list2) {
	myLinkedList<T> newLinkedList;
	ListNode<T> *tailNewList = nullptr;

	ListNode<T> *curr = front;
	while(curr != nullptr){
		ListNode<T> *ptr = new ListNode<T>(curr->val);
		if (tailNewList == nullptr){
			newLinkedList.front = tailNewList = ptr;
		}else{
			tailNewList->next = ptr;
			tailNewList = ptr;
		}
		curr = curr->next;
	}
	curr = list2.front;
	while(curr != nullptr){
		ListNode<T> *ptr = new ListNode<T>(curr->val);
		if (tailNewList == nullptr){
			newLinkedList.front = tailNewList = ptr;
		}else{
			tailNewList->next = ptr;
			tailNewList = ptr;
		}
		curr = curr->next;
	}
	return myLinkedList();
/*	ListNode<T> *curr = list2.front;
	while(curr != nullptr){
		myLinkedList().add(curr->val);
	}
	return myLinkedList();*/
}

template <typename T> //good
ostream& operator <<(ostream& out, myLinkedList<T>& list) {
	out << list.toString();
	return out;
}


#endif /* MYLINKEDLIST_H_ */
