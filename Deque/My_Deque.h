#pragma once
#ifndef _MY_DEQUE_H
#define _MY_DEQUE_H

#include "NODE.h"
#include "Deque_Iterator.h"



template <typename T>
class My_Deque {
public:
	using iterator = Deque_Iterator<T>;
	My_Deque();
	My_Deque(My_Deque& obj);

	iterator begin() {
		iterator current(head, head, head->node_data->begin());
		return current;
	}

	iterator end() {
		Node<T>* Dir = head;
		while (Dir->next != nullptr) {
			Dir = Dir->next;
		}
		iterator current(head, Dir, Dir->node_data->end());
		return current;
	}

	//返回第i个元素的引用
	T& operator[](int i);
	//返回当前大小
	int size();
	//判断是否为空
	bool empty();
	//返回第一个元素的引用
	T& front();
	//返回最后一个元素的引用
	T& back();
	//插入到开头
	void push_front(const T& obj);
	//插入到尾部
	void push_back(const T& obj);
	//删除第一个元素并返回其引用
	T& pop_front();
	//删除尾部元素并返回其引用
	T& pop_back();

	//返回头节点的指针
	Node<T>* Head();

	//在ite迭代器处插入obj并返回其迭代器
	iterator insert(iterator ite, T& obj) {

	}

private:
	Node<T>* head = nullptr;

};




#endif // !_HEAD_H



