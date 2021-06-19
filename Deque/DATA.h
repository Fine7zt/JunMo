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
	
	//返回最大容量
	int max_size();
	//返回当前大小
	int size();
	//判断是否为
	bool full();
	//判断是否为空
	bool empty();
	//返回第一个元素的引用
	T& front();
	//返回最后一个元素的引用
	T& back();
	//插入到开头，如已满，则移出最后一位元素并返回其引用
	T& push_front(const T& obj);
	//插入到尾部,如已满，则移出第一位元素并返回其引用
	T& push_back(const T& obj);
	//删除第一个元素并返回其引用
	T& pop_front();
	//删除尾部元素并返回其引用
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
struct junmo{
};
#endif 

