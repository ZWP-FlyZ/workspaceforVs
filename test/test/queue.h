#ifndef _QUEUE_H_
#define _QUEUE_H_
/*

使用链式结构完成队列

*/

template <typename T>
class Queue:public Container<T>
{
private:
	struct Node
	{
		T		data;
		Node *	next;
	};
	Node * head;			//头指针
	Node * tail;			//尾指针
	int len;			//队列长度
public:
	Queue();			//构造函数

	Queue(const Queue&);//复制构造函数

	int push(T data);	//入列

	int pop(T  &);		//出列

	int getTop(T &);	//获得列头，不弹出

	int appand(const Queue & c);//将c队列放入当前队列

	int isEmpty();		//是否为空列

	int length();		//获得元素数量

	int clear();		//清空列

	int getArry(T *c, int Len);		//导出数组

	~Queue();			
};

template <class T >
Queue<T>::Queue()
{
	head = new Node;
	tail = head;
	head->next = NULL;
	len = 0;
}

template <class T >
Queue<T>::Queue(const Queue& copy)
{
	Node* p = copy.head->next;
	head = new Node;
	head->next = NULL;
	Node *q = head;
	len = copy.len;

	while (p)
	{
	    Node *tmp = new Node;
		tmp->data = p->data;
		q->next = tmp;
		q = tmp;
		p = p->next;
	}

	tail = q;
	tail->next = NULL;

}

template <class T>
int Queue<T>::push(T data)
{
	if (!head)			return -1;
	
	Node * tmp = new Node;
	tmp->data = data;
	tmp->next = NULL;
	tail->next = tmp;
	tail = tmp;
	len++;

	return len;
}

template <class T>
int Queue<T>::getTop(T &data)
{
	if		(!head) return -1;
	else if (!len)	return -2;

	Node *q = head->next;
	data = q->data;
	
	return len;
}

template <class T>
int Queue<T>::pop(T &data)
{
	if		(!head)	return -1;
	else if (!len)	return -2;

	Node *q = head->next;
	head->next = q->next;
	data = q->data;
	delete q;
	len--;

	return 0;
}

template <class T>
int Queue<T>::appand(const Queue& c)
{
	Node *p = c.head->next;
	Node *q = tail;
	len += c.len;
	while (p)
	{
		Node *tmp = new Node;
		tmp->data = p->data;
		q->next = tmp;
		q = tmp;
		p = p->next;
	}

	tail = q;
	tail->next = NULL;
	return 0;
}

template <class T>
int Queue<T>::isEmpty()
{
	return len ? 0 : 1;
}

template <class T>
int Queue<T>::length()
{
	return len;
}
template <class T>
int Queue<T>::clear()
{
	if (!head) return -1;
	
	Node *q = head->next;
	head->next = NULL;

	while (q)
	{
		Node *p = q->next;
		delete q;
		q = p;
	}

	return len = 0;
}

template <class T>
int Queue<T>::getArry(T  *c, int Len)
{
	Node * p = head->next;
	if (Len <= 0||c==NULL) return -1;
	int tmp = len > Len ? Len : len;
	for (int i = 0; i < tmp; i++)
	{
		c[i] = p->data;
		p = p->next;
	}
	return tmp;
}


template <class T>
Queue<T>::~Queue()
{
	while (head)
	{
		Node *p = head->next;
		delete head;
		head = p;
	}
}

#endif