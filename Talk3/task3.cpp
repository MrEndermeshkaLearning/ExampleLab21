#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

void Random(int* arr, int size);
void Print(int* arr, int size);
void deleteElementByRewrite(int* arr, int destroyElement, int& size);
int main() {
	// динамические масивы С оглашаються через malloc и calloc, оглашать через new запрещено
	// оглашение new это С++ и это обьектная модель, её нету в Си.
	// оглашаем указатель куда запихнём динамический масив
	int* p = nullptr;
	printf("Insert size array\n=>");
	int size;
	scanf_s("%d", &size);
	//создаём динамический масив
	p = (int*)malloc(sizeof(int) * size);
	Random(p, size);
	Print(p, size);
	printf("Wich element you want to destroy?\=>");
	int destroyElementIndex;
	scanf_s("%d", &destroyElementIndex);
	deleteElementByRewrite(p, destroyElementIndex, size);
	Print(p, size);
}
void Random(int* arr, int size){
	srand(time(nullptr));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (-size - size) + -size;
	}
}
void Print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("arr[%d]=%d\n", i, arr[i]);
	}
}
void deleteElementByRewrite(int* arr, int destroyElement, int& size) {
	
	int* p1 = (int*)malloc((sizeof(int) * size) - 1);
	int counter = 0;
	for (int i = 0; i < size - 1; i++) {
		if (counter != destroyElement) {
			p1[i] = arr[counter];
			counter++;
		}
		else {
			i--;
			counter++;
		}
	}
	//изменение размера масива
	arr = (int*)realloc(arr, size-1);
	for (int i = 0; i < size - 1; i++) {
		arr[i] = p1[i];
	}
	size--;
}