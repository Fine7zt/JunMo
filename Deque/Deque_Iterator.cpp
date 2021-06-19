#include"Deque_Iterator.h"


template<typename T>
Deque_Iterator<T>::Deque_Iterator( Node<T>* Head, Node<T>* Dir, My_Iterator<T> Ite)
{
	head = Head;
	dir = Dir;
	ite = Ite;
}

template<typename T>
Deque_Iterator<T>::Deque_Iterator(const My_Deque<T>& obj)
{
	head = obj.Head();
	dir = obj.Head();
	ite = obj.Head()->node_data->begin();
}

template<typename T>
Deque_Iterator<T>::Deque_Iterator(const Deque_Iterator<T>& obj)
{
	head = obj.head;
	dir = obj.dir;
	ite = obj.ite;
}

template<typename T>
void Deque_Iterator<T>::Set_Head(My_Deque<T>& obj)
{
	head = obj.Head();
	dir = obj.Head();
	ite = obj.Head()->node_data->begin();
}

template<typename T>
T& Deque_Iterator<T>::operator*()
{
	return *ite;
}

template<typename T>
Deque_Iterator<T>& Deque_Iterator<T>::operator++()
{
	ite++;
	if ((ite == dir->node_data->end()) && (dir->next != nullptr)) {
		dir = dir->next;
		ite = dir->node_data->begin();
	}
	return *this;
}

template<typename T>
Deque_Iterator<T>& Deque_Iterator<T>::operator++(int)
{
	Deque_Iterator<T> current(*this);
	ite++;
	if ((ite == dir->node_data->end()) && (dir->next != nullptr)) {
		dir = dir->next;
		ite = dir->node_data->begin();
	}
	return current;
}

template<typename T>
Deque_Iterator<T>& Deque_Iterator<T>::operator--()
{
	if ((ite == dir->node_data->begin()) && (dir->front != nullptr)) {
		dir = dir->front;
		ite = dir->node_data->end();
	}
	ite--;
	return *this;
}

template<typename T>
Deque_Iterator<T>& Deque_Iterator<T>::operator--(int)
{
	Deque_Iterator<T> current(*this);
	if ((ite == dir->node_data->begin()) && (dir->front != nullptr)) {
		dir = dir->front;
		ite = dir->node_data->end();
	}
	ite--;
	return current;
}

template<typename T>
Deque_Iterator<T>& Deque_Iterator<T>::operator=(const Deque_Iterator<T>& obj)
{
	head = obj.head;
	dir = obj.dir;
	ite = obj.ite;
	return *this;
}

template<typename T>
Deque_Iterator<T>& Deque_Iterator<T>::operator=(const T* obj)
{
	dir = head;
	ite = dir->node_data->begin();
	while (ite != obj) {
		*this++;
	}
	return *this;
}

template<typename T>
bool Deque_Iterator<T>::operator==(const Deque_Iterator<T>& obj)
{
	return this->ite == obj.ite;
}

template<typename T>
bool Deque_Iterator<T>::operator!=(const Deque_Iterator<T>& obj)
{
	return !(*this == obj);
}

template<typename T>
bool Deque_Iterator<T>::operator==(const T* obj)
{
	return this->ite == obj;
}

template<typename T>
bool Deque_Iterator<T>::operator!=(const T* obj)
{
	return !(*this == obj);
}
