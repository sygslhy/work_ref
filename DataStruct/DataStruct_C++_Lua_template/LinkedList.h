/*
 * LinkedList.h
 *
 *  Created on: 26 juin 2018
 *      Author: Administrator
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <class Type>
struct Node{
	Type  value;
	Node* next;
	Node(Type data):value(data),next(0){}
};

template <class Type>
class LinkedList{
public:
	LinkedList();
	LinkedList(Type data);
	LinkedList(const LinkedList<Type>& list);
	~LinkedList();
	Node<Type>* findElement(Type value);
	int insertElement(Node<Type>* pos, Type value);
	int removeElement(Node<Type>* pos);
	void display();
	Node<Type>* head;
};

#endif /* LINKEDLIST_H_ */
