#include"DATA.h"

template<typename T>
inline DATA<T>::DATA()
{
	for (int i = 0; i < 8; i++) {
		data[i] = *new T();
	}
	data_begin = &data[0];
	data_end = &data[0];
	data_max = &data[8];
}

template<typename T>
DATA<T>::DATA(DATA& obj)
{
	for (int i = 0; i < 8; i++) {
		data[i] = obj.data[i];
	}
	data_begin = &data[0];
	data_max = &data[8];

	int i = 0;
	for (iterator current=obj.begin(); current != obj.end(); current++) {
		i++;
	}
	data_end = &data[i];
}

/*template<typename T>
DATA<T>::~DATA()
{
	delete[] data;
}*/


template<typename T>
int DATA<T>::max_size()
{
	return 8;
}

template<typename T>
int DATA<T>::size()
{
	iterator current = data_begin;
	int i = 0;
	for (; current != data_end; current++) {
		i++;
	}
	return i;
}

template<typename T>
bool DATA<T>::full()
{

	return (data_max == data_end);
}

template<typename T>
bool DATA<T>::empty()
{
	return (data_begin == data_end);
}

template<typename T>
T& DATA<T>::front()
{

	if (!empty()) return data[0];
	else {
		T current = *new T();
		return current;
	}
}

template<typename T>
T& DATA<T>::back()
{
	if (!empty()) {
		iterator current = data_begin;
		int i = -1;
		for (; current != data_end; current++) {
			i++;
		}
		return data[i];
	}
	else {
		T current = *new T();
		return current;
	}

}

template<typename T>
T& DATA<T>::push_front(const T& obj)
{
	T overflow = data[7];
	if (data_end != data_max) data_end++;
	for (int i = 7; i > 0; i--) {
		data[i] = data[i - 1];
	}
	data[0] = obj;
	return overflow;
}

template<typename T>
T& DATA<T>::push_back(const T& obj)
{
	T overflow = data[0];
	if (data_end != data_max) {
		*data_end = obj;
		data_end++;
	}
	else {
		for (int i = 0; i < 7; i++) {
			data[i] = data[i + 1];
		}
		data[7] = obj;
	}
	return overflow;
}

template<typename T>
T& DATA<T>::pop_front()
{
	T del = *new T();
	if (data_end != data_begin) {
		del = data[0];
		for (int i = 0; i < 7; i++) {
			data[i] = data[i + 1];			
		}
		data_end--;
		*data_end = *new T();
	}
	return del;
}

template<typename T>
T& DATA<T>::pop_back()
{
	T del = *new T();
	if (data_end != data_begin) {
		data_end--;
		del = *data_end;
		*data_end = *new T();
	}
	return del;
}

template<typename T>
T& DATA<T>::show(int i)
{
	return data[i];
}

template<typename T>
DATA<T> DATA<T>::operator=(const DATA& obj)
{
	for (int i = 0; i < 8; i++) {
		this->data[i] = obj.data[i];
	}
	int i = 0;
	for (DATA<T>::iterator current = obj.begin(); current != obj.end(); current++) {
		i++;
	}
	this->data_end = &this->data[i];
	return *this;
}

template<typename T>
T& DATA<T>::operator[](int i)
{
	return data[i];
}
