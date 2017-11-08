#ifndef _HASHABLE
#define _HASHABLE
#include <bits/stdc++.h>

using namespace std;

/**
 * Contains some definitions for "hashable" data types
 */
class Integer
{
public:
	int num;
	Integer()
	{
		num = 0;
	}
	Integer(int n)
	{
		num = n;
	}
	int hash(int lim) const 
	{
		if(num<0)
			return (-num)%lim;
		return num%lim;
	}
	bool operator==(const Integer& i) const
	{
		return i.num == num;
	}
};

#endif 

