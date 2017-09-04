#include "HashTable.h"
#include <stdio.h>
extern unsigned int Hash(const char *target, unsigned int tableSize);

int main()
{
	HashTable h = Initialize(1001);
	char str[STRSIZE];
	printf("输入EOF结束，任一字符继续\n");
	while (getchar() != EOF)
	{
		while (getchar() != '\n');
		printf("输入要插入的字符串\n");
		scanf_s("%s", str, STRSIZE);
		Insert(h, str);
		while (getchar() != '\n');
		printf("输入EOF结束，任一字符继续\n");
	}
	Print(h);

	return 0;
}