#ifndef _STACK_H_
#define _STACK_H_
/*

   使用顺序结构完成栈

*/

#include "container.h"
#define MAX_SIZE  100

template <typename T>

class Stack:public Container<T> 
{
private:
	T * base;			//基地址
	int top;			//头游标
	int size;			//栈申请空间
public:
	Stack();			//构造函数

	Stack(const Stack&);//复制构造函数

	int push(T data);	//入栈
    
	int pop(T  &);			//出栈

	int getTop(T &);		//获得栈头，不弹出

	int isEmpty();		//是否为空栈

	int length();		//获得元素数量

	int Size();			//栈大小

	int clear();		//清空

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