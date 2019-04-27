#include<stdio.h>
#include<iostream>

int n; // length of the array
int a[10001]; //array
int BIT[10001]; 
int x; // lower limit of query range
int y; // upper limit of query range

int v; //the value that needs to be updated

// function to query using BIT
int query(int k) {
	int sum = 0;
	while (k > 0) {
		sum += BIT[k];
		k -= k & -k;
	}
	return sum;
}


// function to update BIT
void update(int index, int value) {
	while (index <=n)
	{
		// adds the value to the Binary indexed tree 
		//while the current index is smaller or equal to n
		BIT[index] += value;
		// then move on to the parent
		// parent can be easily got by incrementing the last set bit of the current index
		index += index & -index;
	}
}
int main() {

	printf("Enter the length of the array ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		// updating the Binary Indexed tree
		update(i, a[i]);
		update(i + 1, -a[i]);
	}
	printf("Enter the value you want to add and range for updating values: \n");
	scanf("%d %d %d", &v, &x, &y);

	// no need to run a loop in this case
	update(x, v);
	update(y + 1, -v);
	for (int i = x; i <= y; i++)
		printf("updated %dth element is %d\n", i, query(i));
	getchar();
	return 0;

}
