#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"
//简单的散列函数，将字符串中字符的ASCII码值相加，然后返回其与tableSize求余后的结果
unsigned int Hash(const char *target,unsigned int tableSize)
{
	unsigned int HashVal = 0;
	while (*target != '\0')
		HashVal += *target++;
	
	return HashVal%tableSize;
}

//根据给定大小创建散列表头
HashTable Initialize(unsigned int tableSize)
{
	//创建散列表头，并根据给定大小tableSize创建头中的散列表
	HashTable h = (HashTable)malloc(sizeof(struct HashTbl));
	h->size = tableSize;
	h->table = (List *)malloc(sizeof(List)*tableSize);

	//将散列表的每个元素（指向链表第一个元素的指针）初始化为NULL
	for (int i = 0;i < tableSize;++i)
		h->table[i] = NULL;

	return h;
}

//返回target在h中散列表的位置
Position Find(HashTable h, const char *target)
{
	//先计算target的散列值，而后根据散列值前往散列表寻找target
	unsigned int HashVal = Hash(target, h->size);
	Position p = h->table[HashVal];
	while (p != NULL && strcmp(p->str, target))
	{
		p = p->next;
	}
	return p;
}

//将字符串source插入到h中的散列表
void Insert(HashTable h, const char *source)
{
	//此处实质为Find()操作，但为了顺便求出source的散列值，我们不直接使用Find()
	//若source已在散列表中，我们直接返回
	unsigned int HashVal = Hash(source, h->size);
	Position p = h->table[HashVal];
	while (p != NULL && strcmp(p->str, source))
	{
		p = p->next;
	}
	if (p != NULL)
		return;
	
	//若source不在散列表中，我们计算source的散列值，并将source插入到散列表的对应位置
	Position newNode = (Position)malloc(sizeof(struct ListNode));
	strcpy_s(newNode->str, STRSIZE, source);
	newNode->next = h->table[HashVal];
	h->table[HashVal] = newNode;
}

//简单的打印散列表
void Print(HashTable h)
{
	Position p;
	for (int i = 0;i < h->size;++i)
	{
		p = h->table[i];
		if(p!=NULL)
			printf("%d\n", i);
		while (p != NULL)
		{
			printf("%s\n", p->str);
			p = p->next;
		}
	}
}