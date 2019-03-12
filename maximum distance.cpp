#include<stdio.h>
#define MAX 200
int max(int a, int b) {
	return a >= b ? a : b;
}
int main() {
	int arr[] = { 3, 2, 4, 2, 1, 4, 5, 8, 6, 7, 4, 90 };
	const int size = 12;
	int m[MAX];
	int max_dist = 0;
	for (int i = 0; i < 12; i++) {
		if (m[arr[i]] == m[MAX]) {
			m[arr[i]] = i;
		}
		else {
			max_dist = max(max_dist, i - m[arr[i]]);
		}
	}
	printf("The distance is %d", max_dist);
	getchar();
	return 0;
}