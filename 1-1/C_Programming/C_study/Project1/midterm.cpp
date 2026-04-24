#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int LinearSearch(int arr[], int n, int value) { //선형탐색, 시간복잡도 : O(n)
	int index = 0;
	int position = -1;
	bool found = false;
	while (!found && index < n) {
		if (arr[index] == value) {
			found = true;
			position = index;
			return position;
		}
		index++;
	}
	return position;
}

int BinarySearch(int arr[], int n, int value) {   //이진탐색 (배열이 정렬된 상태에서만 사용할 수 있으나 O(log n)이라 효율이 높음. 
	bool found = false;
	int first = 0, middle, last = n - 1, position = -1;
	
	while (!found && first <= last) {
		middle = (first + last) / 2;
			if (arr[middle] < value) {
				first = middle + 1;
		}
			else if (arr[middle] > value) {
				last = middle - 1;
			}
			else {
				position = middle;
				found = true;
			}
	}
	return position;
}


void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int arr[], int n) {    // Bubble Sort 중첩 for문을 이용함.  O(n^2) 하지만 중간종료가 있다는 점이 장점.

	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;   //바뀌는 값이 없으면 중간종료.
		}
	}
}

void selectionsort(int arr[], int n) {  //선택정렬   O(n^2) 데이터 상태와 상관없이 끝까지 훑어서 비효율적
	int minIndex, minValue;
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		minValue = arr[i];
		for (int j = i+1; j < n; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
				minValue = arr[j];
			}
		}
		arr[minIndex] = arr[i];
		arr[i] = minValue;
	}
}




void arrayin(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("배열의 %d번째 원소를 입력하세요 : ", i + 1);
		scanf_s("%d", &arr[i]);
	}
}

void printarray(int arr[], int n) {
	printf("배열의 원소 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


int main() {
		int n;
		int value;

		printf("배열의 원소 개수를 입력하세요 : ");
		scanf_s("%d", &n);

		int* arr = (int*)malloc(sizeof(int) * n);
		arrayin(arr, n);
		printarray(arr, n);
		printf("\n");
		
		printf("찾고 싶은 원소의 값을 입력하세요 :");
		scanf_s("%d", &value);

		printf("(Linear search)원소 위치 : %d\n", LinearSearch(arr, n, value));
		
		printf("원소를 정렬합니다.\n");
		bubblesort(arr, n);
		printf("(Binary search)원소 위치 : %d\n", BinarySearch(arr, n, value));

		

		free(arr);
		return 0;
}
