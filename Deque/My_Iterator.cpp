#include"My_Iterator.h"

template<typename T>
My_Iterator<T>::My_Iterator() {}

template<typename T>
My_Iterator<T>::My_Iterator(T* obj) {
	it = obj;
}

template<typename T>
My_Iterator<T>::My_Iterator(const My_Iterator<T>& obj) {
	it = obj.it;
}

/*template<typename T>
My_Iterator<T>::~My_Iterator() {
	it == nullptr;
	delete it;
}*/



template<typename T>
T& My_Iterator<T>::operator*() {
	
	return *it;
}

template<typename T>
My_Iterator<T> My_Iterator<T>::operator++()
{
	this->it++;
	return *this;
}

template<typename T>
My_Iterator<T> My_Iterator<T>::operator++(int)
{
	T* data = new T(*it);
	this->it++;
	My_Iterator<T> current(data);
	return current;
}

template<typename T>
My_Iterator<T> My_Iterator<T>::operator--()
{
	this->it--;
	return *this;
}

template<typename T>
My_Iterator<T> My_Iterator<T>::operator--(int)
{
	T* data = new T(*it);
	this->it--;
	My_Iterator<T> current(data);
	return current;
}

template<typename T>
My_Iterator<T> My_Iterator<T>::operator=(const My_Iterator<T>& obj)
{
	it = obj.it;
	return *this;
	
}

template<typename T>
My_Iterator<T> My_Iterator<T>::operator=(T* obj)
{
	it = obj;
	return *this;
}

template<typename T>
bool My_Iterator<T>::operator==(const My_Iterator& obj)
{
	return this->it==obj.it;
}

template<typename T>
bool My_Iterator<T>::operator!=(const My_Iterator& obj)
{
	return !(*this == obj);
}

template<typename T>
bool My_Iterator<T>::operator==(const T* obj)
{
	return this->it == obj;
}

template<typename T>
bool My_Iterator<T>::operator!=(const T* obj)
{
	return !(*this == obj);
}

