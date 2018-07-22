/*
 * LinkedList.cpp
 *
 *  Created on: 26 juin 2018
 *      Author: Administrator
 */

#include "LinkedList.h"
#include <iostream>



template <class Type>
LinkedList<Type>::LinkedList(){
	head = new Node<Type>(0);
	head->next = NULL;
}

template <class Type>
LinkedList<Type>::LinkedList(Type data){
	head = new Node<Type>(data);
	head->next = NULL;
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& list){
	head = new Node<Type>(list.head->value);
	Node<Type>* p1 = head;
	Node<Type>* p2 = list.head->next;
	while(p2!=NULL){
		Node<Type>* temp = new Node<Type>(p2->value);
		p1->next = temp;
		p1 = p1->next;
		p2 = p2->next;
	}
}

template <class Type>
LinkedList<Type>::~LinkedList(){
	Node<Type>* p1 = head;
	Node<Type>* p2 = p1->next;
	while(p1!=NULL){
		delete p1;
		p1 = p2;
		if(p1!=NULL){
			p2 = p1->next;
		}
	}
	head=NULL;
}

template <class Type>
Node<Type>* LinkedList<Type>::findElement(Type value){
	Node<Type>* p = head;
	while(p!=NULL && p->value!=value){
		p = p->next;
	}
	return p;
}

template <class Type>
int LinkedList<Type>::insertElement(Node<Type>* pos, Type value){
	Node<Type>* p = NULL;
	p =	new Node<Type>(value);
	if(p==NULL){
		return -1;
	}
	p->next = pos->next;
	pos->next = p;
	return 0;
}

template <class Type>
int LinkedList<Type>::removeElement(Node<Type>* pos){
	Node<Type>* p = head;
	if(pos==head){
		head=pos->next;
		delete pos;
		return 0;
	}

	while(p->next!=pos){
		if(p->next==NULL){
			return -1;
		}
		p = p->next;
	}
	p->next = pos->next;
	delete pos;
	return 0;
}

template <class Type>
void LinkedList<Type>::display(){
	Node<Type>* p = head;
	while(p!=NULL){
		std::cout << p->value << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
