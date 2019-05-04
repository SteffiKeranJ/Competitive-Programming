#include<iostream>
#include<stdio.h>
void xceltoName(int celN) {
	char str[50];
	int i = 0;
	while (celN > 0) {
		int rem = celN % 26;
		if (rem == 0) {
			str[i++] = 'Z';
			celN = (celN / 26) - 1;
		}
		else {
			str[i++] = (rem - 1) + 'A'; // how far the alphabet is from A
			celN = (celN / 26);
		}
	}
	str[i] = '\0';
	int N = i;
	for(int j = N-1; j >= 0; j--) {
		printf("%c", str[j]);
	}
	printf("\n");
}
int main() {
	xceltoName(290);
	xceltoName(2);
	xceltoName(20);
	xceltoName(27);
	xceltoName(25);
	xceltoName(670);
	xceltoName(100);
	xceltoName(26);
	xceltoName(51);
	xceltoName(52);
	xceltoName(80);
	xceltoName(676);
	xceltoName(702);
	xceltoName(705);

	getchar();
}