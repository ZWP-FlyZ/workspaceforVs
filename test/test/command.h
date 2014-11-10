#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "stack.h"
#include "queue.h"
#include <string>
#include "Map.h"
using namespace std;

extern string msg	= "B(ehnxgz)B";

void show(Container<char> &s)
{
	
	while (!s.isEmpty())
	{
		char te = 0;
		int state = s.pop(te);
		cout << te;
	}
}

int PushToCtn(string &str, Container<char> &container,int back)//将string压入容器，back为1表示倒着入
{
	int len = str.length();
	if (back)
		for (int i = len-1; i >=0 ; i--)
			container.push(str.c_str()[i]);
	else
		for (int i = 0; i < len; i++)
			container.push(str.c_str()[i]);
	return 0;
}


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
			default:
				tmp += "*";
		
		}
	}
	return tmp;
}



int Decode(Stack<char> & stack, Queue<char> & result,Map &map )
{
	char ctmp = 0;
	char insert = 0;
	string strTmp = "";

	Stack<char> Stmp;	//缓存栈
	result.clear();		//清空结果队列
	Stmp.clear();		//清空缓存队列

	while (!stack.isEmpty())
	{
		char tmp=0;
		strTmp = "";

		if (stack.pop(tmp) >= 0)
		{
			if (!map.get(tmp, strTmp))
			{
				PushToCtn(strTmp, stack, 1);
			}
			else if (tmp == '(')
			{
				Stmp.clear();
				stack.pop(insert);
				if(insert == ')')
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
			}
			else 
				result.push(tmp);

		}
		else return -1;	
	}	
	return 0;
};





#endif