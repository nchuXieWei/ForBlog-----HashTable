#include "HashTable.h"
#include <stdio.h>
extern unsigned int Hash(const char *target, unsigned int tableSize);

int main()
{
	HashTable h = Initialize(1001);
	char str[STRSIZE];
	printf("����EOF��������һ�ַ�����\n");
	while (getchar() != EOF)
	{
		while (getchar() != '\n');
		printf("����Ҫ������ַ���\n");
		scanf_s("%s", str, STRSIZE);
		Insert(h, str);
		while (getchar() != '\n');
		printf("����EOF��������һ�ַ�����\n");
	}
	Print(h);

	return 0;
}