#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "stack.h"
#include "queue.h"
#include <string>
using namespace std;

string change(char *c, int len)
{
	string tmp = "";
	for (int i = 0; i < len; i++)
	{
		switch (c[i])
		{
			case't':
			tmp += "��"; break;
			case'd':
			tmp += "��"; break;
			case's':
			tmp += "��"; break;
			case'a':
			tmp += "һֻ"; break;
			case'e':
			tmp += "��"; break;
			case'z':
			tmp += "׷"; break;
			case'g':
			tmp += "��"; break;
			case'x':
			tmp += "��"; break;
			case'n':
			tmp += "��"; break;
			case'h':
			tmp += "��"; break;
		}
	}
	return tmp;
}



int Decode(Stack<char> & stack, Queue<char> & result)
{
	char ctmp = 0;
	char insert = 0;

	Stack<char> Stmp;	//����ջ
	result.clear();		//��ս������
	Stmp.clear();		//��ջ������

	while (!stack.isEmpty())
	{
		char tmp=0;
		if (stack.pop(tmp) >= 0)
		{
			switch (tmp)
			{
			case'A':// A  ->  sae 
				result.push('s');
				result.push('a');
				result.push('e');
				break;
			
			case'B':// B  ->  tAdA 
				stack.push('A');
				stack.push('d');
				stack.push('A');
				stack.push('t');
				break;
			case'(':   
				Stmp.clear();
				stack.pop(insert);
				if (insert == ')')
					continue;
				while (stack.pop(ctmp), ctmp != ')')
					Stmp.push(ctmp);
				while (!Stmp.isEmpty())
				{
					result.push(insert);
					Stmp.pop(ctmp);
					result.push(ctmp);
				}
				result.push(insert);
				break;
			default:
				result.push(tmp);

			}
		}
		else return -1;	
	}	
	return 0;
};





#endif