//@NILANJANA LODH
/**Implementation of an LRU cache using hashtable and doubly linked list **/
#include <bits/stdc++.h>
#include "DList.cpp"

using namespace std;
class Cache
{
    unordered_map<int,int> value;
    unordered_map<int,Node*> pointer;//pointers to the Nodes in keylist
    int size; //current number of elements in cache
    int maxsize; //max cache size
    DList *keylist;//The list of keys sorted in increasing order of access times
public:
    Cache(int _maxsize)
    {
        size = 0;
        maxsize = _maxsize;
        keylist = new DList();
    }

    /** \brief returns the value associated with the key,
     *          -1 if the key doesnt exist
     *
     */

    int get(int key)
    {

        if(value.find(key)==value.end()) /** key isn't there in the cache **/
            return -1;

        /** place the key at the end of the list of keys, as its access time is now the largest **/
        Node *p = pointer[key];
        keylist->detachNode(p);
        keylist->insertLast(p);

        return value[key];
    }

    int put(int key, int val)
    {
        if(value.find(key)!=value.end())
        {
            /** if the key is already there, just change its value **/
            value[key] = val;

            /** place the key at the end of the list of keys, as its access time is now the largest **/
            Node *p = pointer[key];
            keylist->detachNode(p);
            keylist->insertLast(p);
        }
        else
        {
            if(size == maxsize)
            {
                /**cache full, get rid of the least recently used element to make room for the new one!**/
                Node *lru_node = keylist->getFirst();
                int lru_key = lru_node->getData();
                keylist->detachNode(lru_node);
                delete lru_node;
                value.erase(lru_key);
            }
            else
                size++; /** there's still room in the cache, so no need to eliminate; just add! **/

            value[key] = val;
            Node *p = new Node(val);
            keylist->insertLast(p);
            pointer[key] = p;
        }
    }
};

int main()
{
    Cache cache(4);
    /**
    input format :
    For put:
    p <key> <val>

    For get:
    g <key>
    **/
    while(true)
    {
        char c;
        cin>>c;
        if(c == 'g')
        {
            int key;
            cin>>key;
            cout<<cache.get(key)<<endl;
        }
        else
        {
            int key, val;
            cin>>key>>val;
            cache.put(key,val);
        }
    }

}
