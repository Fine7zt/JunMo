#include"My_Deque.cpp"
#include"NODE.cpp"
#include"DATA.cpp"
#include"My_Iterator.cpp"
#include"Deque_Iterator.cpp"


#include <iostream>

int main()
{	
	My_Deque<int> data;
	for (int i = 1; i < 20; i++) {
		data.push_back(i);
		std::cout<<data.back()<<" ";
	}
	std::cout << std::endl;
	/*
	std::cout << data.empty() << std::endl;

	std::cout << data.size() << std::endl;

	std::cout << data[18] << std::endl;

	std::cout << data.front() << std::endl;
	data.push_front(0);
	std::cout << data.front() << std::endl;

	std::cout << data.back() << std::endl;
	data.pop_back();
	std::cout << data.back() << std::endl;

	std::cout << data.front() << std::endl;
	data.pop_front();
	std::cout << data.front() << std::endl;
	*/
	My_Deque<int>::iterator it1 = data.begin();
	while (it1 != data.end()) {
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	My_Deque<int>::iterator it2 = data.begin();
	while (it2 != data.end()) {
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;

	My_Deque<int>::iterator it3 = data.end();
	while (it3 != data.begin()) {
		it3--;
		std::cout << *it3 << " ";
	}
	std::cout << std::endl;

	My_Deque<int>::iterator it4 = data.end();
	while (it4 != data.begin()) {
		--it4;
		std::cout << *it4 << " ";
	}
	std::cout << std::endl;
}


