// @Ramazan Taş
// 29.04.2022

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int X,Y,stone,D;
	
	scanf("%d %d %d %d",&X,&Y,&stone,&D);
	
	int x[stone][2], y[stone][2] , var[D][2];
	
	for (int i=0; i<stone ; i++){
		
		scanf("%d %d %d %d", &x[i][0],&x[i][1],&y[i][0],&y[i][1]);
	}
	
	for (int i=0 ; i<D ; i++){
		scanf("%d %d", &var[i][0] , &var[i][1]);
	}
	
	int garden[X][Y];
	
	for (int i=0 ; i<X ; i++){
		for (int j=0 ; j<Y ; j++)
			garden[i][j] = 0;
	}
	
	//////		STONE PLACEMENT		//////
	
	
	for (int i=0; i < stone ; i++){
		
		for (int j = x[i][0] ; j < x[i][1]; j++ ){
			
			for (int k = y[i][0] ; k < y[i][1] ; k++){
				
				garden [j][k] = 1 ;	
				
			}
		}			
	}
	
	// 0 empty , 1 stone in garden
	
	int place[D];
	
	
	//////		FINDING		//////
	
	
	for (int i = 0 ; i<D ; i++){
		
		int counter=0;
		
		for (int upper_y = 0 ; upper_y < Y - var[i][1] + 1 ; upper_y++){
			
			for (int upper_x = 0 ; upper_x < X - var[i][0] + 1 ; upper_x++){
				
				int flag = 0;
				
				for (int inner_y = upper_y ; inner_y < upper_y + var [i][1] ; inner_y++){
		
					for (int inner_x = upper_x ; inner_x < upper_x + var [i][0] ; inner_x++){
						
						if ( garden[inner_x][inner_y] == 0)
							flag++;
						
					}

				}
				
				if ( flag == (var[i][0] * var[i][1]))
					counter++;
				
			}
			
		}
		
		place [i] = counter;
		
	} 
	
	printf("\n\n");
	
	for (int i=0 ; i < D ; i++)
		printf("(%d %d) --> %d\n",var[i][0],var[i][1],place[i]);
	
	
	return 0;
}




