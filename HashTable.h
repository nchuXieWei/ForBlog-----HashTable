#pragma once
#ifndef XW_HASHTABLE
#define XW_HASHTABLE
#define STRSIZE 20

struct ListNode {
	char str[STRSIZE];
	struct ListNode *next;
};
typedef struct ListNode *List;
typedef List Position;

struct HashTbl {
	unsigned int size;
	List *table;
};
typedef struct HashTbl *HashTable;

HashTable Initialize(unsigned int tableSize);
Position Find(HashTable h, const char *target);
void Insert(HashTable h, const char *source);
void Print(HashTable h);

#endif