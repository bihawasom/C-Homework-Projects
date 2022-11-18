/*
Name: Bih Awasom
Section:102
*/


#include <iostream>
using namespace std;

template <typename T>
void LinkedList<T>::insert_front(const T& x) {
	LLNode<T>* temp = new LLNode<T>(x, m_head->m_next);
	m_head->m_next = temp;
	m_size++;
	
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list) {
	//bruh
	LLNode<T>* runNode = list.m_head->m_next;
	out << "[";
	while (runNode != NULL) {
		out << runNode->m_data << ", ";
		runNode = runNode->m_next;
	}
	out << "]";
	return out;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
	if (m_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
int LinkedList<T>::size() const {
	return m_size;
}

template <typename T>
void LinkedList<T>::clear() {
	LLNode<T>* current = m_head->m_next;
	LLNode<T>* next;
	while (current != NULL) {
		next = current->m_next;
		delete current;
		current = next;
	}
	m_size = 0;
	m_head->m_next = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	LLNode<T>* tmp;
	while (m_head != NULL) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
}

template <typename T>
void LinkedList<T>::insert_back(const T& x) {
	LLNode<T>* temp = new LLNode<T>(x, nullptr);
	LLNode<T>* runner = m_head;
	while (runner->m_next != nullptr)
	{
		runner = runner->m_next;
	}
	runner->m_next = temp;
	++m_size;
}

template <typename T>
LLNode<T>* LinkedList<T>::getFirstPtr() {
	if (m_head != NULL) {
		return m_head->m_next;
	}
	else {
		return NULL;
	}
}

template <typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i) {
	int count = 0;
	LLNode<T>* runner = m_head->m_next;
	while (count < i && runner != nullptr)
	{
		++count;
		runner = runner->m_next;
	}

	return runner;
}

template <typename T>
void LinkedList<T>::remove(LLNode<T>* pos) {
	LLNode<T>* head = m_head;
	LLNode<T>* rp = m_head->m_next;
	while (rp != pos && rp != NULL) {
		head = rp;
		rp = rp->m_next;
	}
	if (pos == rp && rp != NULL) {
		head->m_next = rp->m_next;
		delete rp;
		m_size--;
	}
}

template <typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos) {
	LLNode<T>* tmp = new LLNode<T>;
	tmp->m_next = pos->m_next;
	tmp->m_data = pos->m_data;
	pos->m_next = tmp;
	pos->m_data = x;
	m_size++;
	tmp = NULL;
}

template <typename T> //
void LinkedList<T>::remove_back() {
	LLNode<T>* head = m_head;
	LLNode<T>* rp = m_head->m_next;
	while (rp->m_next != NULL) {
		head = rp;
		rp = rp->m_next;
	}
	head->m_next = NULL;
	delete rp;
	m_size--;
}

template <typename T>
void LinkedList<T>::remove_front() {
	LLNode<T>* front = m_head->m_next;
	m_head->m_next = front->m_next;
	delete front;
	m_size--;
}

template <typename T>
LLNode<T>* LinkedList<T>::find(const T& x) {
	LLNode<T>* rp = m_head;
	while (rp->m_next != NULL && rp->m_data != x) {
		rp = rp->m_next;
	}
	return rp;
}

template <typename T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs){
	LLNode<T>* rhsLL;
	LLNode<T>* lhsLL;
	LLNode<T>* tmp;

	m_size = rhs.m_size;
	lhsLL = m_head;
	rhsLL = rhs.m_head->m_next;
	
	while (rhsLL != NULL) {
		if (lhsLL->m_next != NULL) {
			tmp = lhsLL->m_next;
		}
		else{
			tmp = new LLNode<T>;
			lhsLL->m_next = tmp;
		}
		tmp->m_data = rhsLL->m_data;
		lhsLL = tmp;
		rhsLL = rhsLL->m_next;
	}

	while (lhsLL != NULL) {
		tmp = lhsLL->m_next;
		delete lhsLL;
		lhsLL = tmp;
	}
	return *this;
}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const {
	bool decide = (m_size != rhs.m_size);
	LLNode<T>* lhsrp = m_head->m_next;
	LLNode<T>* rhsrp = rhs.m_head->m_next;

	while (!decide && rhsrp != NULL && lhsrp != NULL) {
		if (rhsrp->m_data != lhsrp->m_data) {
			decide = true;
		}
		else {
			rhsrp = rhsrp->m_next;
			lhsrp = lhsrp->m_next;
		}
	}
	decide = (decide || !(rhsrp == NULL && lhsrp == NULL));
	
	return !decide;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
	LLNode<T>* lhsLL;
	LLNode<T>* rhsLL;
	LLNode<T>* tmp;

	m_head = new LLNode<T>;
	m_size = rhs.m_size;
	lhsLL = m_head;
	rhsLL = rhs.m_head;

	while (rhsLL->m_next != NULL) {
		rhsLL = rhsLL->m_next;
		tmp = new LLNode<T>;
		lhsLL->m_next = tmp;
		tmp->m_data = rhsLL->m_data;
		lhsLL = tmp;
	}
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& l2) {
	LLNode<T>* rp = m_head;
	LLNode<T>* l2rp = l2.m_head->m_next;
	m_size += l2.m_size;
	while (rp->m_next != NULL) {
		rp = rp->m_next;
	}
	while (l2rp != NULL) {
		LLNode<T>* tmp = new LLNode<T>(l2rp->m_data, NULL);
		rp->m_next = tmp;
		rp = tmp;
		l2rp = l2rp->m_next;
	}
}

template <typename T>
void LinkedList<T>::reverse() {
	LLNode<T>* head = m_head;
	LLNode<T>* rp = head->m_next;
	
	while (rp != NULL) {
		LLNode<T>* tmp = rp->m_next;
		rp->m_next = head;
		head = rp;
		rp = tmp;
	}
	m_head->m_next->m_next = NULL;
	m_head->m_next = head;
}

template <typename T>
void LinkedList<T>::slice(const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop) {
	LLNode<T>* rp = m_head;
	LLNode<T>* l2rp = l2.m_head;
	LLNode<T>* tmp;
	int counter = 0;
	while (l2rp != start && l2rp != NULL)
	{
		l2rp = l2rp->m_next;
	}

	while (l2rp != stop && l2rp != NULL)
	{
		if (rp->m_next != NULL)
		{
			tmp = rp->m_next;
		}
		else
		{
			tmp = new LLNode<T>;
			rp->m_next = tmp;
		}

		temp->m_data = l2Runner->m_data;
		runner = temp;
		l2Runner = l2Runner->m_next;
		++counter;
	}

	rp = rp->m_next;
	while (rp != NULL)
	{
		tmp = rp->m_next;
		delete rp;
		rp = tmp;
	}

	m_size = counter;
}
