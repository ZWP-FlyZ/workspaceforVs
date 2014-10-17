#ifndef _STACK_H_
#define _STACK_H_
/*

   ʹ��˳��ṹ���ջ

*/

#include "container.h"
#define MAX_SIZE  100

template <typename T>

class Stack:public Container<T> 
{
private:
	T * base;			//����ַ
	int top;			//ͷ�α�
	int size;			//ջ����ռ�
public:
	Stack();			//���캯��

	Stack(const Stack&);//���ƹ��캯��

	int push(T data);	//��ջ
    
	int pop(T  &);			//��ջ

	int getTop(T &);		//���ջͷ��������

	int isEmpty();		//�Ƿ�Ϊ��ջ

	int length();		//���Ԫ������

	int Size();			//ջ��С

	int clear();		//���

	~Stack();			
};

template <class T >
Stack<T>::Stack()
{
	top = 0;
	size = MAX_SIZE;
	base = new T[MAX_SIZE];
}

template <class T >
Stack<T>::Stack(const Stack& copy)
{
	top = copy.top;
	size = copy.size;
	base = new T[size];
	for (int i = 0; i < top; i++)
		base[i] = copy.base[i];
}

template <class T>
int Stack<T>::push(T data)
{
	if (!base)			return -1;
	if (top == size)
	{
		size += MAX_SIZE;
		T * temp = new T[size];
		for (int i = 0; i < top; i++)
			 temp[i] = base[i];
		delete[] base;
		base = temp;	
	}
	base[top++] = data;
	return top;
}

template <class T>
int Stack<T>::getTop(T &data)
{
	if (top == 0) return -1;
	data = base[top - 1];
	return top;
}

template <class T>
int Stack<T>::pop(T &data)
{
	if (top == 0) return -1;
	data = base[--top];
	return top;
}

template <class T>
int Stack<T>::isEmpty()
{
	return top? 0:1;
}

template <class T>
int Stack<T>::length()
{
	return top;
}

template <class T>
int Stack<T>::Size()
{
	return size;
}

template <class T>
int Stack<T>::clear()
{
	return top=0;
}

template <class T>
Stack<T>::~Stack()
{
	delete[] base;
	top = 0;
}

#endif