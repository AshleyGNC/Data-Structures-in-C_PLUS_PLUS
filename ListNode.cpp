/*
 * Lab13.cpp
 *
 *  Created on: May 4, 2022
 *      Author: Ashley
 */

struct ListNode {
	int data; // element stored in each node
	ListNode *next; // pointer to the next node (nullptr if none)

	ListNode(int d, ListNode *p) {
		data = d;
		next = p;
	}
};

#include <iostream>
#include "vector.h"
#include "simpio.h"
using namespace std;

ListNode* vectorTolinkedlist(const Vector<int> &v) {
	if (v.size() == 0) {
		// vector is empty
		return nullptr;
	}
	ListNode *tmp = new ListNode(v[0], nullptr);
	ListNode *head = tmp;
	ListNode *current = head;
	// iterate each element in the vector
	for (int i = 1; i < v.size(); i++) {
		// add the element to the linkedlist
		// create a listnode using the element
		ListNode *tmp = new ListNode(v[i], nullptr);
		current->next = tmp;
		current = tmp;
	}
	// return the pointer to the head of the linkedlist
	return head;
}

int size(ListNode *head) {
	ListNode *curr = head;
	int size = 0;
	while (curr != nullptr) {
		size++;
		curr = curr->next;
	}
	return size;
}

void print(ListNode *head) {

	if (head == nullptr) {
		cout << "empty list" << endl;
	}
	ListNode *curr = head;
	while (curr != nullptr) {
		cout << curr->data << "->";
		curr = curr->next;
	}
	cout << endl;
}

int get(ListNode *head, int index) {
	// check if index is legal or not
	if (index < 0 || index >= size(head)) {
		throw "Index is out of bound!!!";
	}
	ListNode *curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	// curr is pointing to the index-th node
	return curr->data;

}

void add(ListNode *&head, int data) {
	ListNode *newNode = new ListNode(data, nullptr);

	if (head == nullptr) {
		// if the linked list is empty
		head = newNode;
	} else {

		// if the linked list is not empty
		ListNode *curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		// curr is pointing to the last node in the list
		curr->next = newNode;
	}
}

ListNode* remove(ListNode *&head, int index) {
	int ret;
	ListNode *toDelete = nullptr;
	// check if index is legal or not
	if (index < 0 || index >= size(head)) {
		throw "Index is out of bound!!!";
	}
	if (index == 0) {
		// remove the first node
		toDelete = head;
		ret = head->data;
		head = head->next;

		// delete the node
		delete toDelete;
	} else {
		ListNode *curr = head;
		for (int i = 0; i < index - 1; i++) {
			curr = curr->next;
		}
		// curr is pointing to the previous node
		toDelete = curr->next;
		ret = curr->next->data;
		curr->next = curr->next->next;

		// delete the node
		delete toDelete;
	}

	return toDelete;
}

void insert(ListNode *&head, int index, int data) {
	if (index < 0 || index > size(head)) {
		throw "Index is out of bound!!!";
	}
	if (index == 0) {
		// insert to the front

		head = new ListNode(data, head);
	} else {
		ListNode *curr = head;
		for (int i = 0; i < index - 1; i++) {
			curr = curr->next;
		}
		// curr is pointing to (i-1)-th node
		curr->next = new ListNode(data, curr->next);

	}
}

ListNode* insertionSortList(ListNode *head) {
	if(head == nullptr) return nullptr;
	ListNode* newHead = head;
	ListNode *temp, *ptr;
	ListNode* curr = head->next;
	head->next = nullptr;

	while(curr != nullptr){
		if(curr->data < newHead->data){
			temp = curr->next;
			curr->next = newHead;
			newHead = curr;
			curr = temp;
		}else{
			ptr = newHead;
			while(ptr->next != nullptr && curr->data > ptr->next->data){
				ptr = ptr->next;
			}
			temp = curr->next;
			curr->next = ptr->next;
			ptr->next = curr;
			curr = temp;
		}
	}
	/*
	if(head == nullptr) return nullptr;
	ListNode *temp = head->next;
	if(head->data <= temp->data){
		insertionSortList(temp->next);
	}else{
		head->next = head->next->next;
		temp->next = head;
		insertionSortList(head);
	}
	return temp;
	*/
	return newHead;
}

int main()
{
	Vector<int> v = { 4, 1, 7, -4, 5 };
	ListNode *front = vectorTolinkedlist(v);
	print(insertionSortList(front));
	int x = getInteger();
	return 0;
}
