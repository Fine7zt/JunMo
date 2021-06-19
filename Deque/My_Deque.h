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

	//���ص�i��Ԫ�ص�����
	T& operator[](int i);
	//���ص�ǰ��С
	int size();
	//�ж��Ƿ�Ϊ��
	bool empty();
	//���ص�һ��Ԫ�ص�����
	T& front();
	//�������һ��Ԫ�ص�����
	T& back();
	//���뵽��ͷ
	void push_front(const T& obj);
	//���뵽β��
	void push_back(const T& obj);
	//ɾ����һ��Ԫ�ز�����������
	T& pop_front();
	//ɾ��β��Ԫ�ز�����������
	T& pop_back();

	//����ͷ�ڵ��ָ��
	Node<T>* Head();

	//��ite������������obj�������������
	iterator insert(iterator ite, T& obj) {

	}

private:
	Node<T>* head = nullptr;

};




#endif // !_HEAD_H



