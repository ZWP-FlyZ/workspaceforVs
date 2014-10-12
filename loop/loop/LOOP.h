#ifndef _LOOP_H_
#define _LOOP_H_

class Loop
{
private:
	struct Elem
	{
		int id;
		int pass;
		Elem * next;
	};
	Elem *head;
	Elem *tail;
	int len;
public:
	Loop();
	
	int insert	(int id, int pass);
	int get		(int pass,int& id);
	int pop		(int pass, int& id);
	int clear();
	int length();

	~Loop();
};

Loop::Loop(){
	head = tail = NULL;
	len = 0;
}

Loop::~Loop(){
	clear();
}

int Loop::insert(int id, int pass){
	Elem * p = new Elem;
	p->id = id;
	p->pass = pass;
	p->next = NULL;

	if (!head)
	{
		tail = p;
		head = p;
		tail->next = head;
	}
	else 
	{
		p->next = head;
		tail->next = p;
		tail = p;
	}

	len++;
	return len;
		
}

int Loop::get(int pass, int& id){
	int ps = 1;

	if		(pass < 1)			return id = -1;
	else if (head == NULL)		return id = -2;
	else	
	{
		if (len == 1)		
			id = head->id;
		else
		{
			Elem * p = head;
			int tc = (id + 1) % len;
			for (int i = tc; i; i--)
				p = p->next;
			id = p->id;
			ps = p->pass;
		}
		return ps;

	}
}

int Loop::pop(int pass, int& id){
	int ps = 1;

	if (pass < 1)				return id = -1;
	else if (head == NULL)		return id = -2;
	else
	{
		if (len == 1)
		{
			id = head->id;
			ps = head->pass;
			delete head;
			head = tail = NULL;
		}
			
		else
		{
			Elem * p = tail;
			int tc = (pass -1) % len;
			for (int i = tc; i>0; i--)
				p = p->next;
			id = p->next->id;
			ps = p->next->pass;

			Elem *q = p->next;
			p->next = q->next;
			delete q;
			tail = p;
			head = tail->next;
		}
		len--;
		return ps;
	}

}

int Loop::clear(){
	
	if (head&&tail)
	{
		tail->next = NULL;
		while (head)
		{
			Elem *p = head->next;
			delete head;
			head = p;
		}
		len = 0;
	}
	return 0;
}

int Loop::length(){
	return len;
}
#endif