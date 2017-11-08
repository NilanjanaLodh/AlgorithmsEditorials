#include <bits/stdc++.h>
#include "Hashable.cpp"
#include "Hashtable.cpp"

using namespace std;


int main()
{
    HashTable<Integer,int> h;
    Integer i5(5);
    h[i5] = 5;
    Integer i3(3);
    h[i3] = 3;    
    h.insert(Integer(-3), -3);
    cout<<h.size()<<endl;

    cout<<"h[3] = "<<h[Integer(3)]<<endl;
    cout<<"h[-3] = "<<h[Integer(-3)]<<endl;
    
    h.remove(Integer(-3));
    cout<<"Now h has "<<h.size()<<" elements"<<endl;
}
