#pragma warning(disable:4996)

#include <iostream>
#include "stack.h"
#include "queue.h"
#include "command.h"
#include <string>
using namespace std;

void show(Stack<char> s)
{
	s.push(100);
	while (s.isEmpty())
	{	
		char te = 0;
		int state = s.pop(te);
		cout << te << endl;
	}
}

void show(Queue<char> s)
{
	s.push(100);
	while (!s.isEmpty())
	{
		char te = 0;		
		int state = s.pop(te);
		cout << te;
	}
}


int main()
{
	Stack<char> stack;
	Queue<char> queue;

	stack.clear();


	stack.push('B');
	stack.push(')');
	stack.push('z');
	stack.push('g');
	stack.push('x');
	stack.push('n');
	stack.push('h');
	stack.push('e');
	stack.push('(');
	stack.push('B');

	Decode(stack,queue);

	char *t = new char[100];
	int len = queue.length();
	queue.getArry(t, len);

	string sss = change(t, len);

	show(queue);
	cout << sss << endl;

	int i = 0;
	scanf("%d",&i);

}



