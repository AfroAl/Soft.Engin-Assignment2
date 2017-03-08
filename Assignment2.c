#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct slot
{
	int stpoint[20];
	time_t t;
};

struct slot slotlist[20];

int main()
{
    printf("Enter the number of slots needed in the array: ");
    int size;
    int i;
    scanf("%d", &size);
   
    struct slot terrain[size]; 
    struct slot y;
    srand(time(NULL));

    for( i = 0; i < size; i++)
    {
	  terrain[i].stpoint[i]=rand() % 3 + 1;
	  if(terrain[i].stpoint[i] == 1)
 	{
 	printf("This slot is level ground terrain.\n");
 	}
 
 	else if(terrain[i].stpoint[i] == 2)
	 {
 	printf("This slot is hill terrain.\n");
	 }
 
 	else if(terrain[i].stpoint[i] == 3)
 	{
 	printf("This slot is city terrain.\n");
 	}  
    }
}

