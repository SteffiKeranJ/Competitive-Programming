#include<iostream>
#include<stdio.h>
const int HASHSIZE = 1048576;
const int HASH = HASHSIZE - 1;
int hasharr[HASHSIZE];

const int MAXN = 20;
long data[MAXN];

int hashKeyFunction(long num) {
	int p1 = (int)num;
	int p2 = (int)(num >> 32);
	return p1 + p2;
}


void main() {

	srand(time_t(NULL));
	for (int i = 0; i < MAXN; i++)
	{
		data[i] = rand() % MAXN;
	}
	for (int i = 0; i < HASHSIZE; i++) hasharr[i] = HASHSIZE;
	int count = 0;
	for (int i = 0; i < MAXN; i++) {
		int key = hashKeyFunction(data[i]);
		key &= HASH;
		for (;;)
		{
			if (hasharr[key] == HASHSIZE) {
				hasharr[key] = i;
				break;
			}
			else if (data[hasharr[key]] == data[i]) {
				count++;
				break;
			}
			else {
				key = (key + 1) & HASH;
			}
		}
	}
	printf("%d duplicate numbers pulled out", count);
	for (int i = 0; i < HASHSIZE; i++) {
		if (hasharr[i] != HASHSIZE) {
			printf("%d ", data[hasharr[i]]);
		}
	}
	getchar();
}