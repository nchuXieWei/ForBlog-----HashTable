#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"
//�򵥵�ɢ�к��������ַ������ַ���ASCII��ֵ��ӣ�Ȼ�󷵻�����tableSize�����Ľ��
unsigned int Hash(const char *target,unsigned int tableSize)
{
	unsigned int HashVal = 0;
	while (*target != '\0')
		HashVal += *target++;
	
	return HashVal%tableSize;
}

//���ݸ�����С����ɢ�б�ͷ
HashTable Initialize(unsigned int tableSize)
{
	//����ɢ�б�ͷ�������ݸ�����СtableSize����ͷ�е�ɢ�б�
	HashTable h = (HashTable)malloc(sizeof(struct HashTbl));
	h->size = tableSize;
	h->table = (List *)malloc(sizeof(List)*tableSize);

	//��ɢ�б��ÿ��Ԫ�أ�ָ�������һ��Ԫ�ص�ָ�룩��ʼ��ΪNULL
	for (int i = 0;i < tableSize;++i)
		h->table[i] = NULL;

	return h;
}

//����target��h��ɢ�б��λ��
Position Find(HashTable h, const char *target)
{
	//�ȼ���target��ɢ��ֵ���������ɢ��ֵǰ��ɢ�б�Ѱ��target
	unsigned int HashVal = Hash(target, h->size);
	Position p = h->table[HashVal];
	while (p != NULL && strcmp(p->str, target))
	{
		p = p->next;
	}
	return p;
}

//���ַ���source���뵽h�е�ɢ�б�
void Insert(HashTable h, const char *source)
{
	//�˴�ʵ��ΪFind()��������Ϊ��˳�����source��ɢ��ֵ�����ǲ�ֱ��ʹ��Find()
	//��source����ɢ�б��У�����ֱ�ӷ���
	unsigned int HashVal = Hash(source, h->size);
	Position p = h->table[HashVal];
	while (p != NULL && strcmp(p->str, source))
	{
		p = p->next;
	}
	if (p != NULL)
		return;
	
	//��source����ɢ�б��У����Ǽ���source��ɢ��ֵ������source���뵽ɢ�б�Ķ�Ӧλ��
	Position newNode = (Position)malloc(sizeof(struct ListNode));
	strcpy_s(newNode->str, STRSIZE, source);
	newNode->next = h->table[HashVal];
	h->table[HashVal] = newNode;
}

//�򵥵Ĵ�ӡɢ�б�
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