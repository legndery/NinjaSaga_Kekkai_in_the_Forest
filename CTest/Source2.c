
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int build_max_heap(int *arr, int size);
void max_heapify(int *arr, int index);
int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}

int main(){
	int arr[11] = {0,53,22,25,62,53,63,12,66,94,53};
	int i;//,j;
	int n=10;
	//selection
	build_max_heap(arr, n);
	for(i=1;i<=10;i++){
		printf("%d ", arr[i]);
	}

	return 0;
}
int build_max_heap(int *arr, int size){
	int i;
	for(i=size/2;i>0;i--){
		max_heapify(arr, i);
	}
	return 0;
}
void max_heapify(int *arr, int index){
	int l=left(index);
	int r = right(index);
	int largest,temp;
	if(l<=MAX && arr[l]>arr[index]){
		largest = l;
	}else{
		largest = index;
	}
	if(r<=MAX && arr[r] >arr[largest]){
		largest = r;
	}
	//swap
	if(largest != index){
	temp = arr[largest];
	arr[largest] =arr[index];
	arr[index] = temp;
	}

	max_heapify(arr, largest);

}
