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
	char	key	=	0;
	string	tmpMsg = "";

	Map map;			//ӳ��ͼ
	Stack<char> stack;	//����ջ
	Queue<char> queue;	//�������

	stack.clear();

	cout << "Input key: ";
	while (cin >> key)
	{
		if		(key == '!')		break;
		else if (key > 'Z' || key < 'A')
		{
			cout << endl << "Input key: ";
			continue;
		}
		else
		{
			string val;
			cout <<endl<< "Input valuse: ";
			cin >> val;
			map.put(key, val);
		}
		cout <<endl<<"Input key: ";
	}


	cout << endl << "Input  massage: ";
	if (cin >> tmpMsg, tmpMsg != "~")
		msg = tmpMsg;

	PushToCtn(msg,stack,1);//��ħ��������ջ

	Decode(stack, queue, map);//�����ý��


	//�����������ڷ���
	int len = queue.length();
	char *t = new char[len+1];
	queue.getArry(t, len);

	//�������
	string sss = change(t, len);
	
	show(queue);
	cout<<endl << sss << endl;

	delete[] t;
	system("PAUSE");
}





