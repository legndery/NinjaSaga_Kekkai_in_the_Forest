#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define MAX 720

int array_intersect(int *a, int *b){
	int i=0,j=0,yellow=0;
	//1 2 3 4 5,, 3 2 4 5 6
	for (i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			if (a[i] ==b[j])
			{
				yellow++;
				break;
			}
		}
	}
	return yellow;
}
int array_intersect_assoc(int *a, int *b){
	int green = 0,i=0;
	for(i=0;i<5;i++){
		if (a[i] == b[i])
		{
			green++;
		}
	}
	return green;
}
int main(){

	char *$map[] = {"Green", "Red","Blue","Black","Yellow", "White"};
	int index=6,x=0;
	int **result, **perspective = NULL;
	int *first = (int *)malloc(5*sizeof(int));

	//counters
	int i,j,k,l,m;
	//
	int green,yellow,length = MAX,temp=0;
	char complete='n';
	//
	printf("Ninja Saga Kekkai In The Forest Solver\nby Legndery\n------------------------");
	first[0] =0;first[1] = 1;first[2] = 2;first[3] = 3;first[4]=4; //first array
	//initialize result
	result = (int **)malloc(MAX*sizeof(int));
	if (result == NULL)
	{
		exit(0);
	}
	for (i = 0; i < index; i++)
	{
		for (j = 0; j < index; j++)
		{
			for ( k = 0; k < index; k++)
			{
				for (l = 0; l < index; l++)
				{
					for ( m = 0; m < index; m++)
					{
						if ((m==l) || (m==k) || (m==j) || (m == i)||
							(l==k) || (l==j) || (l == i) ||
							(k==j) || (k==i) ||
							(j==i)) {
									continue;
							}else{
						result[x]  = (int *)malloc((index-1)*sizeof(int));
						result[x][0] = i;
						result[x][1] = j;
						result[x][2] = k;
						result[x][3] = l;
						result[x][4] = m;
						x++;
						}

					}
				}
			}
		}
	}
	//perspective creation
	perspective = (int **)malloc(MAX*sizeof(int));

	for (i = 0; i < MAX; i++)
	{
		perspective[i] = (int *)malloc(2*sizeof(int));
		perspective[i][0] =array_intersect_assoc(first, result[i]);
		perspective[i][1] = array_intersect(first, result[i])-perspective[i][0];
	}
	//reperspective(first, result, perspective, MAX);
	////////////////////////////////////////////////////////////////////////////
	//change according to input
	do
	{
		printf("\nEnter:-");
		for (i = 0; i < 5; i++)
		{
			printf("%s ", $map[first[i]]);
		}
		
		printf("\n%d Permutations Left", length);
		printf("\r\nEnter Green and Yellow:-");
		scanf_s("%d %d",&green,&yellow);
		//
		temp=0;
		//
		for (i = 0; i < length; i++)
		{
			if (perspective[i][0] == green && perspective[i][1] == yellow)
			{
				temp++;
				continue;
			}else
			{
				result[i] = NULL;
				perspective[i] = NULL;
			}
		}

		for (j=0, i = 0; i < length; i++)
		{
			if (result[i] != NULL)
			{
				result[j] = result[i];
				perspective[j] = perspective[i];
				j++;
			}
		}
		//printf("<<<%d>>>\n", j);
		/*for (;j<length; j++)
		{
			free(result[j]);
			free(perspective[j]);
		}*/
		first = result[0];
		if (j == temp)
		{
			length = temp;
		}else
		{
			exit(0);
		}
		
		//reperspective(first,result,perspective,length);
		for (i = 0; i < length; i++)
		{
			perspective[i][0] = array_intersect_assoc(first,result[i]);
			perspective[i][1] = array_intersect(first, result[i]) - perspective[i][0];
		}
		///////////////
		for (i = 0; i < length; i++)
		{printf("%d)", i);
			for ( j = 0; j <5; j++)
			{
				printf("%d ", result[i][j]);
				//printf("%d ",perspective[i][j]);
			}
			printf("\r\n");
		}
		/////////////
		//printf("%d\n", length);
		if (length == 0)
		{
			printf("\nYou Entered Something Wrong");
			break;
		}
		if(green != 5 && yellow!=0){
			continue;
		}else{
			break;
		}
	} while (1);
	printf("\n");
	system("pause");
	return 0;

}