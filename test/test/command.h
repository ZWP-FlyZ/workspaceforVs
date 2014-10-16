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
			tmp += "天"; break;
			case'd':
			tmp += "地"; break;
			case's':
			tmp += "上"; break;
			case'a':
			tmp += "一只"; break;
			case'e':
			tmp += "鹅"; break;
			case'z':
			tmp += "追"; break;
			case'g':
			tmp += "赶"; break;
			case'x':
			tmp += "下"; break;
			case'n':
			tmp += "蛋"; break;
			case'h':
			tmp += "恨"; break;
		}
	}
	return tmp;
}



int Decode(Stack<char> & stack, Queue<char> & result)
{
	char ctmp = 0;
	char insert = 0;

	Stack<char> Stmp;	//缓存栈
	result.clear();		//清空结果队列
	Stmp.clear();		//清空缓存队列

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