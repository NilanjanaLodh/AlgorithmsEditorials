#ifndef HTABLE
#define HTABLE

#include <bits/stdc++.h>

using namespace std;

#define DEF_CAPACITY 1000
/**
 * Hash Table implementation which uses chaining for collision resolution
 *
 * Key is expected to have the implementation for the following functions
 * int hash(int lim)
 * bool operator==(Key)
 *
 * Val should have a non parameterized constructor
 */
template<typename Key , typename Val>
class HashTable
{
private:
	int num_elements;
	int table_size;
	vector<list<pair<Key,Val>>> table;
public:
	HashTable(int capacity=DEF_CAPACITY);
	void insert(Key,Val);
	void remove(Key);
	bool contains(Key);
	Val lookup(Key);
	Val& operator[](const Key);
	int size();

};

template<typename Key, typename Val>
HashTable< Key ,Val>::HashTable(int capacity)
{
	num_elements = 0;
	table_size = capacity;
	table = vector<list<pair<Key,Val>>>(table_size);
}


template<typename Key, typename Val>
bool HashTable< Key ,Val>::contains(Key k)
{
	int table_index = k.hash(table_size);
	list<pair<Key,Val>> &l = table[table_index];

	for(pair<Key,Val> &p : l)
	{
		if(p.first == k)
			return true;
	}
	return false;
}

template<typename Key, typename Val>
Val HashTable< Key ,Val>::lookup(Key k)
{
	int table_index = k.hash(table_size);
	list<pair<Key,Val>> &l = table[table_index];

	for(pair<Key,Val> &p : l)
	{
		if(p.first == k)
			return p.second;
	}
	assert_perror(1);
}

template<typename Key, typename Val>
Val& HashTable< Key ,Val>::operator[](Key k)
{
	int table_index = k.hash(table_size);
	list<pair<Key,Val>> &l = table[table_index];

	for(pair<Key,Val> &p : l)
	{
		if(p.first == k)
			return p.second;
	}
	Val v;
	l.push_back(make_pair(k,v));
	num_elements++;

	auto lastpos = l.end();
	lastpos--;
	return (*lastpos).second;
}

template<typename Key, typename Val>
void HashTable< Key ,Val>::insert(Key k,Val v)
{
	HashTable &h = *this;
	h[k] = v;

}

template<typename Key, typename Val>
void HashTable< Key ,Val>::remove(Key k)
{
	int table_index = k.hash(table_size);
	list<pair<Key,Val>> &l = table[table_index];

	for(auto it = l.begin();it !=l.end();it++)
	{
		if((*it).first == k)
		{
			num_elements--;
			l.erase(it);
			return;
		}
	}
}

template<typename Key, typename Val>
int HashTable< Key ,Val>::size()
{
	return num_elements;
}
#endif

