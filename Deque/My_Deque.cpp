#include "My_Deque.h"

template<typename T>
My_Deque<T>::My_Deque()
{
	head = new Node<T>();
}

template<typename T>
My_Deque<T>::My_Deque(My_Deque& obj)
{
	head = new Node<T>(*obj.head);
	Node<T>* current = head;
	Node<T>* obj_current = obj.head;
	while (obj_current->next != nullptr) {
		current->next = new Node<T>(*obj_current->next);
		obj_current = obj_current->next;
		current->next->front = current;
		current = current->next;
	}
}


template<typename T>
T& My_Deque<T>::operator[](int i)
{
	Node<T>* current = this->head;
	int h = i / 8;
	for (int n = 0; n < h; n++) {
		current = current->next;
	}
	return current->node_data->show(i - h * 8);
}

template<typename T>
int My_Deque<T>::size()
{
	int h = 0;
	Node<T>* current = head;
	while (current->next != nullptr) {
		h++;
		current = current->next;
	}
	return (h * 8 + (current->node_data->size()));
}

template<typename T>
bool My_Deque<T>::empty()
{
	return head->node_data->empty();
}

template<typename T>
T& My_Deque<T>::front()
{
	return head->node_data->front();
}

template<typename T>
T& My_Deque<T>::back()
{
	Node<T>* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	return current->node_data->back();
}

template<typename T>
void My_Deque<T>::push_front(const T& obj)
{
	Node<T>* current = head;
	T overflow=obj;

	if (current->node_data->full() && current->next == nullptr) {
		current->next = new Node<T>();
		current->next->front = current;
	}
	overflow = current->node_data->push_front(overflow);

	while (current->next != nullptr){
		current = current->next;
		if (current->node_data->full() && current->next == nullptr) {
			current->next = new Node<T>();
			current->next->front = current;
		}
		overflow = current->node_data->push_front(overflow);
	} 
}

template<typename T>
void My_Deque<T>::push_back(const T& obj)
{
	Node<T>* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	if (current->node_data->full()) {
		current->next = new Node<T>();
		current->next->front = current;
		current = current->next;
	}
	current->node_data->push_back(obj);
}

template<typename T>
T& My_Deque<T>::pop_front()
{
	T overflow;
	Node<T>* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	overflow = current->node_data->pop_front();
	while (current->front != nullptr) {
		current = current->front;
		if (current->next->node_data->empty()) {
			current->next->~Node();
			current->next = nullptr;
		}
		overflow = current->node_data->push_back(overflow);
	}
	return overflow;
}

template<typename T>
T& My_Deque<T>::pop_back()
{
	T del;
	Node<T>* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	del = current->node_data->pop_back();
	if ((current->node_data->empty()) && (current->front!=nullptr)) {
		current = current->front;
		current->next->~Node();
		current->next = nullptr;
	}
	return del;
}


template<typename T>
Node<T>* My_Deque<T>::Head()
{
	return head;
}
