#pragma warning(disable:4996)

#include <string>
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "command.h"
#include "Map.h"

using namespace std;


int main()
{

	string tmpA = "";
	string tmpB = "";
	string tmpMsg = "";

	Map map;

	map.put('A', A);
	map.put('B', B);

	string test = "";

	map.get('A', test);

	cout << test << endl;

	Stack<char> stack;
	Queue<char> queue;//结果队列

	stack.clear();
	cout << "A->";
	if (cin >> tmpA, tmpA!="~")
		A = tmpA;
	cout << endl<<"B->";
	if (cin >> tmpB, tmpB!="~")
		B = tmpB;
	cout << endl << "msg:";
	if (cin >> tmpMsg, tmpMsg != "~")
		msg = tmpMsg;


	PushToCtn(msg,stack,1);//将魔王语言入栈
	Decode(stack, queue, map);//解码获得结果


	//导出数组用于翻译
	int len = queue.length();
	char *t = new char[len+1];
	queue.getArry(t, len);

	//翻译语句
	string sss = change(t, len);

	show(queue);
	cout<<endl << sss << endl;

	delete[] t;
	system("PAUSE");
}





