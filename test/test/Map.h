#ifndef _MAP_H_
#define _MAP_H_
#include <iostream>
#include <string>
#define LEN 26
using namespace std;

class Map
{
private :
	string	map[LEN];
	int		uesd;
public:
	Map()
	{
		for (int i = 0; i < LEN; i++)
			map[i] = "";
		uesd = 0;
	}

	int put(char key, string val)
	{
		if		(uesd>26)				return -1;
		else if (key<'A' || key>'Z')	return -2;
		else 
		{
			map[key - 'A'] = val;
			uesd++;
		}
		return 0;
	}
	int get(char key, string &val)
	{
		if (uesd==0)					return -1;
		else if (key<'A' || key>'Z')	return -2;
		else
		{
			val = map[key - 'A'];
			if (val == "")				return -3;
		}
		return 0;
	}

	int clear()
	{
		for (int i = 0; i < LEN; i++)
			map[i] = "";
		uesd = 0;
	}

};


#endif 