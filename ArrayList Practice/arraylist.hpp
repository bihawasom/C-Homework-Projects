/*
* Name: Bih Awasom
* Section: 102
*/
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
using namespace std;

template <typename T>
void ArrayList<T>::grow() {
	T* tmp = new T[m_max * 2];
	for (int k = 0; k < m_max; k++) {
		tmp[k] = m_data[k];
	}
	delete[] m_data;
	m_data = tmp;

	m_max = m_max*2;
	return;
}

template <typename T>
void ArrayList<T>::shrink() {
	T* tmp = new T[m_max / 2];
	for (int k = 0; k < m_max; k++) {
		tmp[k] = m_data[k];
	}
	delete[] m_data;
	m_data = tmp;
	m_max = m_max / 2;
	return;
}

template <typename T> 
ArrayList<T>::ArrayList(int s, const T& x) {
	m_size = s;
	m_max = s;
	m_data = new T[m_max];
	for (int i = 0; i < s; i++) {
		m_data[i] = x;
	}
}

template <typename T>
ArrayList<T>::~ArrayList() {
	m_size = 0;
	m_max = 0;
	delete[] m_data;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs){
	if (this != &rhs) {
		delete[] m_data;
		m_size = rhs.m_size;
		m_max = rhs.m_max;
		m_data = new T[m_max];
		for (int k = 0; k < m_size; k++) {
			m_data[k] = rhs.m_data[k];
		}
	}
	return *this;
}

template <typename T> 
ArrayList<T>::ArrayList(const ArrayList<T>& cpy) {
	m_data = NULL;
	*this = cpy;
}

template <typename T>
int ArrayList<T>::size() const {
	return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const {
	return m_data[0];
}

template <typename T>
T& ArrayList <T>::operator[](int i){
	return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const {
	return m_data[i];
}

template <typename T>
int ArrayList<T>::search(const T& x) const {
	for (int k = 0; k < m_size; k++) {
		if (m_data[k] == x) {
			return k;
		}
	}
	return -1;
}

template <typename T>
void ArrayList<T>::clear() {
	delete[] m_data;
	m_data = new T[m_max];
	m_max = 4;
	m_size = 0;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x) {
	if (m_size < m_max) {
		m_data[m_size] = x;
	}
	else {
		grow();
		m_data[m_size] = x;
	}
	m_size++;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i) {
	while(i > m_max) {
		grow();
	}
	for (int k = m_size; k > i; k--) {
		m_data[k] = m_data[k - 1];
	}
	m_data[i] = x;
	m_size++;
}

template <typename T>
void ArrayList<T>::remove(int i) {
	for (int k = i + 1; k < m_size; k++) {
		m_data[k - 1] = m_data[k];
	}
	m_size--;
}

template <typename T>
void ArrayList<T>::swap(int i, int k) {
		T* tmp = new T[m_max];
		tmp[0] = m_data[i];
		m_data[i] = m_data[k];
		m_data[k] = tmp[0];
		delete[] tmp;
}

template <typename T>
void ArrayList<T>::purge() {
	for (int i = 0; i <= m_size; i++) {
		for (int j = i + 1; j < m_size; j++) {
			if (m_data[i] == m_data[j]) {
				remove(j);
				m_size--;
				j--;
			}
		}
	}
}

template <typename T>
void ArrayList<T>::reverse() {
	T* tmp = new T[m_max];
	int a = m_size - 1;
	for (int k = 0; k < m_size; k++) {
		tmp[k] = m_data[a];
		a--;
	}
	for (int i = 0; i < m_size; i++) {
		m_data[i] = tmp[i];
	}
	delete[] tmp;
}

#endif
