## Least Recently used Cache algorithm

### Problem
Design and implement a data structure for Least Recently Used (LRU) cache. 

- `get(key)` : Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.<br/>
- `put(key, value)` : Set or insert the value if the key is not already present.<br/>
                  When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Expected time complexity : Do both operations in **O(1)**<br/>
https://leetcode.com/problems/lru-cache/description/


### Hint and Approach
- What are the data structures you would need?
  - We need one data structure to map the keys to values : (hashtable)
  - We also need to keep track of the least recently used element.
    - How ? What data structure can allow this?
       - whenever we access an element we need to change its last access time
       - we would need to eliminate the element with the **smallest** access time.
       - A natural way to think about it is a **deck of cards**<br/>
       imagine a deck of cards : ||1 2 3 4 5 <<-- top of the deck<br>
       Suppose you "access" card 2. You pick it from the deck and place it on top of the deck : ||1 3 4 5 **2** <<top<br/>
       This is like shuffling a card.<br/>
       The card at the bottom of the deck is the **least recently used** one. 
       - What data structure can allow this? (i.e easy removal from middle of the list, and easy insertion in O(1) time) ? : 
       **Linked List**
 
### Implementation details
- Linked List : Singly Linked or Doubly Linked? Deleteion is easier in doubly linked list, so it is more convenient to use 
doubly linked list. Otherwise, for deletion, we would require to store the predecessor of the node (if we use a singly linked list)
- C++ STL : map vs unordered map: In this problem, unordered map is more suitable, as it provides **O(1)** expected time as opposed to O(log n) of map.
- I have used my own doubly linked list implementation. However,[list](http://www.cplusplus.com/reference/list/list/) in stl already provides a doubly linked list implementation, and can be used instead.

