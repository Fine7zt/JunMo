#pragma once
#ifndef _DAQUE_ITERATOR_H
#define _DEQUE_ITERATOR_H


#include"My_Deque.h"

template<typename T>
class Deque_Iterator {
public:

	Deque_Iterator(Node<T>* Head, Node<T>* Dir, My_Iterator<T> Ite);
	Deque_Iterator(const My_Deque<T>& obj);
	Deque_Iterator(const Deque_Iterator<T>& obj);

	//iterator÷ÿ∂®œÚ
	void Set_Head(My_Deque<T>& obj);

	T& operator*();
	Deque_Iterator<T>& operator ++();
	Deque_Iterator<T>& operator ++(int);
	Deque_Iterator<T>& operator --();
	Deque_Iterator<T>& operator --(int);
	Deque_Iterator<T>& operator =(const Deque_Iterator<T>& obj);
	Deque_Iterator<T>& operator =(const T* obj);
	bool operator==(const Deque_Iterator<T>& obj);
	bool operator !=(const Deque_Iterator<T>& obj);
	bool operator==(const T* obj);
	bool operator !=(const T* obj);

private:
	Node<T>* head = nullptr;
	Node<T>* dir = nullptr;
	My_Iterator<T> ite = nullptr;
};

#endif