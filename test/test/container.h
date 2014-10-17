#ifndef _CONTAINER_H_
#define _CONTAINER_H_

template <typename T>
class Container
{
public :
	virtual int push(T data)
	{
		return 0;
	}

	virtual int pop(T  &)
	{
		return 0;
	}

	virtual int getTop(T &)
	{
		return 0;
	}

	virtual int isEmpty()
	{
		return 0;
	}

	virtual int length()
	{
		return 0;
	}
			
	virtual int clear()
	{
		return 0;
	}
};


#endif