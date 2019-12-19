#include <stdio.h>
#include "sort.h"
#define ArraySize 50
int arr[ArraySize];

void print_array(int *data, int n) {
	int i;
	for(i = 0; i<n; i++) {

		if(i<n-1){printf("%d,", *data);}
		else{printf("%d", *data);}
		data++;
	}
}

void shift_element(int* arr, int i) {
	for (int j = i; j > 0; j--)
	{
		*(arr+j)=*(arr+j-1);
	}
}

void shift_elementForSort(int* arr, int *i){
	int iValue;
	for(iValue = *i; i > arr  && *(i-1) > iValue; i--) {
		*i = *(i-1);
	}
	*i = iValue;
}
void insertion_sort(int *arr, int len) {
	int *i, *last = arr + len;
	for(i = arr + 1; i < last; i++)
		if(*i < *(i-1))
			shift_elementForSort(arr, i);
}
int main() {
	for (size_t i = 0; i < 50; i++){scanf("%d",&arr[i]);}
	insertion_sort(arr, ArraySize);
	print_array(arr, ArraySize);
}