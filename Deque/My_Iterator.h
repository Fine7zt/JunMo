#pragma once
#ifndef _ITERATOR_H
#define _ITERATOR_H

#include<iostream>



template <typename T>
class My_Iterator {

public:
	My_Iterator();
	My_Iterator(T* obj);
	My_Iterator(const My_Iterator& obj);
	//~My_Iterator();

	T& operator*();
	My_Iterator<T> operator ++();
	My_Iterator<T> operator ++(int);
	My_Iterator<T> operator --();
	My_Iterator<T> operator --(int);
	My_Iterator<T> operator =(const My_Iterator<T>& obj);
	My_Iterator<T> operator =(T* obj);
	bool operator==(const My_Iterator& obj);
	bool operator !=(const My_Iterator& obj);
	bool operator==(const T* obj);
	bool operator !=(const T* obj);



private:
	T* it=nullptr;

};
#endif