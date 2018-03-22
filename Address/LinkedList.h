#pragma once
#include <iostream>
using namespace std;
// ���ø� Ŭ���� LinkedList
template <typename T>
class LinkedList
{
public:
	class Node
	{
	public:
		T data = NULL;		// ������ ����� ���ø� ������
		Node* next = NULL;	// ���� �ּҸ� ���� Node�� ������

		// Node�� ������
		Node(T _data) {
			data = _data;
		}

		// Node�� �Ҹ���
		~Node()	{
			if (data != NULL)
				delete data;
		}
	};

private:
	Node* headNode = NULL;
	Node* tailNode = NULL;
	int size = 0;

public:
	LinkedList<T>() {};
	~LinkedList<T>() {};

	unsigned int Size() { return size; }

	void AddHead(T data);
	void AddTail(T data);
	void Insert(T data, unsigned int index);
	void Remove(unsigned int index);
	void Clear();
	T At(unsigned int index);

};

template<typename T>
inline void LinkedList<T>::AddHead(T data)
{
	Node* newNode = new Node(data);

	if (headNode != NULL)
		newNode->next = headNode;
	else
		tailNode = newNode;

	headNode = newNode;
	size++;
}

template<typename T>
inline void LinkedList<T>::AddTail(T data)
{
	Node* newNode = new Node(data);
	if (tailNode != NULL)
		tailNode->next = newNode;
	else
		headNode = newNode;

	tailNode = newNode;
	size++;
}

template<typename T>
inline void LinkedList<T>::Insert(T data, unsigned int index)
{
	if (index == 0) {
		AddHead(data);
		return;
	}
	if (index > size)
	{
		cout << index <<"��°�� ����Ʈ�� ������ ����ϴ�." << endl;
		cout << "�����͸� ���� �� �����ϴ�. (���� ũ�� = " << size << ")" << endl;
		return;
	}

	if (headNode != NULL)	// Insert�� ���������� �Ǿ�� �ϴ� ���
	{
		Node* newNode = new Node(data);
		Node* currentNode = headNode;
		for (int count = 1; count < index; ++count)
				currentNode = currentNode->next;

		if (currentNode->next == NULL)
			tailNode = newNode;

		newNode->next = currentNode->next;
		currentNode->next = newNode;

		size++;
	}
	else				// headNode == NULL�̸� �׳� AddHead�� ȣ���Ѵ�.
	{
		AddHead(data);
	}
}

template<typename T>
inline void LinkedList<T>::Remove(unsigned int index)
{
	Node* delNode;
	if (index == 0) {
		if (headNode == tailNode) {
			delNode = headNode;
			headNode = tailNode = NULL;
			delete(delNode);
			return;
		}
		headNode = delNode->next;
		delete delNode;
		size--;
		return;
	}
	if (index >= size) {
		cout << index << "��°�� ����Ʈ�� ������ ����ϴ�." << endl;
		cout << "�����͸� ������ �� �����ϴ�. (���� ũ�� = " << size << ")" << endl;
		return;
	}
	if (headNode != NULL)	// Insert�� ���������� �Ǿ�� �ϴ� ���
	{
		Node* currentNode = headNode;
		for (int count = 1; count < index; ++count)
			currentNode = currentNode->next;
		if (currentNode->next == tailNode)
			tailNode = currentNode;

		delNode = currentNode->next;
		currentNode->next = delNode->next;
		delNode->next = NULL;
		delete delNode;
		size--;
		return;
	}
}

template<typename T>
inline void LinkedList<T>::Clear()
{
	Node* currNode = headNode;
	while (currNode !- NULL) {
		Node* nextNode = currNode->next;
		delete currentNode;
		size--;
		currNode = nextNode;
	}

	headNode = NULL;
	tailNode = NULL;
	return;
}

template<typename T>
inline T LinkedList<T>::At(unsigned int index)
{
	if (index > size)
		cout << index << "������ ����Ʈ�� ������ ����ϴ�.\n�����͸� ������ �� �����ϴ�. (���� ũ�� = " << size << ")" << endl;
	Node* currentNode = headNode;
	for (int count = 0; count < index; ++count) {
		currentNode = currentNode->next;
	}
	return currentNode->data;
	return T();
}
