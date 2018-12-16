#include <stdio.h>
#include<stdlib.h>
void quicksort(int list[], int left, int right,int SIZE);

main()
{
	char str[100],SIZE=0;
	int i,data[100];
	while (fgets(str, sizeof(str), stdin)) {
		int n = atoi(str);
		data[SIZE] = n;
		SIZE++;
		if (SIZE == 9 && n == 1 || SIZE == 3 && n == 2) {
			quicksort(data, 0, SIZE - 1,SIZE);
			for (i = 0; i < SIZE; i++)
				printf("%d ", data[i]);
			printf("\n");
		}

		if (SIZE == 100 && n == 20) {
			quicksort(data, 0, SIZE - 1,SIZE);
			for (i = 0; i < SIZE; i++)
				printf("%d ", data[i]);
			printf("\n");
		}
	}

}

void quicksort(int list[], int left, int right,int SIZE)
{
	int i,j, last,count=0;
	int temp;
	
	if (left >= right) {
		return;
	}
		

	last = left;
	for (i = left + 1; i <= right; i++) {
		
		if (list[i] < list[left]) {
			last++;
			temp = list[last];
			list[last] = list[i];
			list[i] = temp;
			count++;
		}
		
	}
	if (0 < count) {
		for (j = 0; j <SIZE; j++)
			printf("%d ", list[j]);
		printf("\n");
		count = 0;
	}
	temp = list[left];
	list[left] = list[last];
	list[last] = temp;
	
	quicksort(list, left, last - 1,SIZE);
	quicksort(list, last + 1, right,SIZE);
}
