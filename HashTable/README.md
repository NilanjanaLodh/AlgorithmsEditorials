# HashTable : implementation

This is a implementation of HashTable in C++ (using templates).
Collision resolution has been handled via chaining.

**Declaring a HashTable object**:  `HashTable< KeyType , ValType > h;`

KeyType should implement the following functions:
* int hash(int limit)
* bool operator==(KeyType )


