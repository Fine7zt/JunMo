#include "NODE.h"

template<typename T>
Node<T>::Node()
{
	node_data = new DATA<T>();
}

template<typename T>
Node<T>::Node(const Node& obj)
{
	node_data = new DATA<T>(obj);
}

template<typename T>
Node<T>::~Node()
{
	front = nullptr;
	next = nullptr;
	delete node_data;
}
