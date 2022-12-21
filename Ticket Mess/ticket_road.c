// @Ramazan Taş
// 27.04.2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024


void road_maker(char road[][11],char tickets[][2][11],int ticket){
	
	
	
	for (int i =0; i<=ticket ; i++){ // general
		
		
		for (int j=0; j<ticket ;j++){  // checkout
			
				
			if ( !strcmp ( road[i] , tickets [j][0])){
				//int len = strlen(tickets[j][1]);
				
				for (int k=0; k<11 ; k++){
					
					road[i+1][k]= tickets[j][1][k];
					
				}
			}	
		}		
	}
}


int main (){
	
	char citys[N][2][11];  // [number of ticket] [a to b] [name]
	
	int ticket ;
	
	printf("Enter the number of tickets --> ");
	scanf("%d", &ticket);
	
	char road[ticket+1][11];
	
	printf("Enter the road of tickets (like-> 'berlin london')\n");
	for (int i=0 ; i<ticket ; i++){
		scanf("%s %s",citys[i][0],citys[i][1]);
	}
	
	
	for (int i=0; i<ticket ; i++){
		int flag = 0;
		for (int j=0; j< ticket ; j++){
			
			if ( !strcmp( citys[i][0] , citys[j][1])){
				flag=1;
			}	
		}
			if (flag==0){
				int len = strlen(citys[i][0]);
				for(int k=0; k<len ; k++)
					road[0][k]=citys[i][0][k];
				break;
			}
	}
	
	road_maker(road,citys,ticket);
	
	for (int l=0; l<=ticket; l++)
		printf("%s ",road[l]);
	
	
	return 0;
}


