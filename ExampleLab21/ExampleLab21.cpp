#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Size 10
void random(int arr[], int size) {
	srand(time(nullptr));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (-size - size) + -size;
	}
}

int main()
{
	//task1 базируеться на теории поэтому в пример я его не даю
	//task2 
	int arr[Size];
	random(arr, Size);
	long byteSizeArray = sizeof(arr); // размер масива в байтах
	int countArrayElement = sizeof(arr) / (sizeof(arr[0]));//кол-во елементов масива 
	//размер масива поделённый на размер первого елемента масива = количество елементов в масиве
	//адресс в принтефе выводииться через %p, адресация елемента масива через &
	
	printf("arr[0]=%p, arr[%d]=%p\n", &arr[0], countArrayElement - 1, &arr[countArrayElement - 1]);
	//выведем масив в обратном порядке используя указатель;
	for (int* ptr = arr + countArrayElement-1; ptr >= arr; --ptr)
		printf("%4d",*ptr);
}
