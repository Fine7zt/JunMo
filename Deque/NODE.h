#pragma once
#ifndef _NODE
#define _NODE

#include "DATA.h"

template<typename T>
class My_Deque;

template<typename T>
class Deque_Iterator;

template<typename T>
class Node {
public:
	Node();
	Node(const Node& obj); 
	~Node();
	friend class My_Deque<T>;
	friend class Deque_Iterator<T>;
private:
	DATA<T>* node_data = nullptr;
	Node* front = nullptr;
	Node* next = nullptr;
};



#endif
