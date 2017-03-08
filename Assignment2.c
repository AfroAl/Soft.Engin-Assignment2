#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_PLAY 6

struct Players
{
    char Name[MAX_PLAY][10];
    char Archtype[MAX_PLAY][7];
    int lifePoints[MAX_PLAY];
    int Smarts[MAX_PLAY];
    int Strength[MAX_PLAY];
    int Magic[MAX_PLAY];
    int Luck[MAX_PLAY];
    int Dex[MAX_PLAY];
};

struct slot
{
	int stpoint[20];
	time_t t;
};

struct slot slotlist[20];

int main()
{
    int Slotsize, Playsize;
    int i;

    printf("Please enter the number of players (Max 6): ");
    scanf("%d", &Playsize);
    printf("Each player next must choose an archtype.\n");
    printf("Elfs, Human, Ogre, Wizard\n");
    printf("Please enter your archtype as it is written above.\n");

    struct Players x[Playsize];
    char ArchtypeList[4][7] = {"Elf", "Human", "Ogre", "Wizard"};

    while(i<Playsize)
    {
        scanf("%s %s", &(x[i].Name[i]) , &(x[i].Archtype[i]));
        i++;
    }

    printf("Enter the number of slots needed in the array: ");
    scanf("%d", &Slotsize);
   
    struct slot terrain[Slotsize]; 
    struct slot y;
    srand(time(NULL));

    for( i = 0; i < Slotsize; i++)
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

    // Sets all lifepoints to 100
    for(i=0;i<Playsize;i++)
    {
        x[i].lifePoints[i] = 100;
    }

    // Sets Capabilities of each archtype
    for(i=0;i<Playsize;i++)
    {
        if(strcmp(x[i].Archtype[i], ArchtypeList[0]) == 0)
        {
            x[i].Smarts[i] = 70 + rand()%31;
            x[i].Strength[i] = 1 + rand()%50;
            x[i].Magic[i] = 51 + rand()%30;
            x[i].Luck[i] = 60 + rand()%41;
            x[i].Dex[i] = 1 + rand()%100;
        }
        else if(strcmp(x[i].Archtype[i], ArchtypeList[1]) == 0)
        {
            int total;
            while(total>300)
            {
                x[i].Smarts[i] = 1 + rand()%100;
                x[i].Strength[i] = 1 + rand()%100;
                x[i].Magic[i] = 1 + rand()%100;
                x[i].Luck[i] = 1 + rand()%100;
                x[i].Dex[i] = 1 + rand()%100;

                total = x[i].Smarts[i] + x[i].Strength[i] + x[i].Magic[i] + x[i].Luck[i] + x[i].Dex[i];
            }
        }
        else if(strcmp(x[i].Archtype[i], ArchtypeList[2]) == 0)
        {
            int sum;
            while(sum<=50)
            {
                x[i].Smarts[i] = rand()%21;
                x[i].Strength[i] = 80 + rand()%21;
                x[i].Magic[i] = 0;
                x[i].Luck[i] = rand()%101;
                x[i].Dex[i] = 80 + rand()%21;

                sum = x[i].Smarts[i] + x[i].Luck[i];
            }
        }
        else if(strcmp(x[i].Archtype[i], ArchtypeList[3]) == 0)
        {
            x[i].Smarts[i] = 90 + rand()%11;
            x[i].Strength[i] = 1 + rand()%20;
            x[i].Magic[i] = 80 + rand()%21;
            x[i].Luck[i] = 50 + rand()%51;
            x[i].Dex[i] = 1 + rand()%100;
        }
    }


        
    //------------------------------------------------------------

    for(i=0;i<Playsize;i++)
    {
        char ans;
        printf("\n");
        printf("Player %d's Turn:\n", i+1);
        printf("Would you like to move(M) or attack(A) the closest player?\n");
        scanf(" %c", &ans);

        if(ans == 'M')
        {

        }
        else if(ans == 'A')
        {
            int defend, attack;
            if(x[defend].Strength[defend] <= 70)
            {
                printf("Your opponent has less than or equal to 70 Strength points.\n");
                printf("You overcame them and they took damage.\n");
                x[defend].lifePoints[defend] -= 0.5*(x[defend].Strength[defend]);
            }
            else if(x[defend].Strength[defend] > 70)
            {
                printf("Your opponent has greater than 70 Strength points.\n");
                printf("They fought back and you took damage.\n");
                x[attack].lifePoints[attack] -= 0.3*(x[attack].Strength[attack]);
            }
        }
        else
        {
            printf("Please enter a valid choice.\n");
        }
    }

    printf("\n");
    for(i=0;i<Playsize;i++)
    {
        printf("%s (%s, %d)\n", x[i].Name[i], x[i].Archtype[i], x[i].lifePoints[i]);
    }
}
