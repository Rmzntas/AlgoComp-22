// @Ramazan Tas
// 28.04.2022


#include <stdio.h>
#include <stdlib.h>



//	Calculating cost of bubble sort

int bubble_sort_cost(int array[],int size){
	
	int cost=0,temp;
	
	for (int i=size-1 ; i>=0 ; i--){
		
		for (int j=0 ; j<i ; j++){
			
			if (array[j] > array[j+1]){
				
				cost += (array[j] - array[j+1]);
				
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;	
				
			}
		}
	}
	
	return cost;
}

int main(){
	
	int number,cost;
	
	printf("Enter the number of integers -> ");
	scanf("%d",&number);
	
	int integers[number];
	
	printf("Enter all integer with space\n");
	
	for (int i=0; i<number ; i++)
		scanf("%d", &integers[i]);
	
	cost = bubble_sort_cost(integers,number);
	
	printf("%d\n",cost);
	
	return 0;
}