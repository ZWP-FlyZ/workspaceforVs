#ifndef _QUEUE_H_
#define _QUEUE_H_
/*

ʹ����ʽ�ṹ��ɶ���

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
	Node * head;			//ͷָ��
	Node * tail;			//βָ��
	int len;			//���г���
public:
	Queue();			//���캯��

	Queue(const Queue&);//���ƹ��캯��

	int push(T data);	//����

	int pop(T  &);		//����

	int getTop(T &);	//�����ͷ��������

	int appand(const Queue & c);//��c���з��뵱ǰ����

	int isEmpty();		//�Ƿ�Ϊ����

	int length();		//���Ԫ������

	int clear();		//�����

	int getArry(T *c, int Len);		//��������

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