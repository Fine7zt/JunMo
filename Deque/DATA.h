#pragma once
#ifndef _DATA_H
#define _DATA_H

#include"My_Iterator.h"

template<typename T>
class DATA {
public:
	using iterator = My_Iterator<T>;

	DATA();
	DATA(DATA& obj);
	//~DATA();

	iterator begin() { return data_begin; }
	iterator end() { return data_end;}
	
	//�����������
	int max_size();
	//���ص�ǰ��С
	int size();
	//�ж��Ƿ�Ϊ
	bool full();
	//�ж��Ƿ�Ϊ��
	bool empty();
	//���ص�һ��Ԫ�ص�����
	T& front();
	//�������һ��Ԫ�ص�����
	T& back();
	//���뵽��ͷ�������������Ƴ����һλԪ�ز�����������
	T& push_front(const T& obj);
	//���뵽β��,�����������Ƴ���һλԪ�ز�����������
	T& push_back(const T& obj);
	//ɾ����һ��Ԫ�ز�����������
	T& pop_front();
	//ɾ��β��Ԫ�ز�����������
	T& pop_back();
	T& show(int i);

	void playout() {
		for (int i = 0; i < 8; i++) {
			std::cout << data[i];
		}
	}

	DATA<T> operator =(const DATA& obj);
	T& operator[](int i);

private:
	T data[9];
	iterator data_end = nullptr;
	iterator data_begin = nullptr;
	iterator data_max = nullptr;
};

#endif 

