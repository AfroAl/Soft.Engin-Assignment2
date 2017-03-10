#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_PLAY 6
#define MAX_SLOT 20

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
	int stpoint[MAX_SLOT];
    int playerslot[MAX_SLOT];
};

int main()
{
    int Slotsize, Playsize;
    int i=0;
    int j;

    //Asks for input of Player & Archtype
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

    //Asks for input of Slots
    printf("Enter the number of slots needed in the array: ");
    scanf("%d", &Slotsize);
   
    struct slot terrain[Slotsize]; 
    struct slot y;
    srand(time(NULL));

    //Sets each slot to hold a 0
    for(i=0;i<Slotsize;i++)
    {
        terrain[i].playerslot[i] = 0;
    }

    i=1;
    while(i<=Playsize)
    {
        j = rand()%Slotsize;
        if(terrain[j].playerslot[j] == 0)
        {
            terrain[j].playerslot[j] = i;
            i++;
        }
    }

    for(i=0;i<Slotsize;i++)
    {
        printf("%d ", terrain[i].playerslot[i]);
    }

    //Gives each slot a random terrain type
    for( i = 0; i < Slotsize; i++)
    {
	  terrain[i].stpoint[i]=rand() % 3 + 1;
	 /* if(terrain[i].stpoint[i] == 1)
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
 	} */ 
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
            int total=0;
            while(total<300)
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
            int sum=0;
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

            int currPos;
            for(j=0;j<Slotsize;j++)
            {
                if(terrain[i].playerslot[j] == i)
                {
                    currPos = j;
                }
            }

            int i, j, m, tmp, Nxt, a=j;
            if(terrain[i].stpoint[i] == 1)
            {
                printf("Current position: level ground.\n");
            }
 
            else if(terrain[i].stpoint[i] == 2)
            {
                printf("Current position: hill.\n");
            }
 
            else if(terrain[i].stpoint[i] == 3)
            {
                printf("Current position: city.\n");
            }

            if(currPos==0)
            {
                printf("You can only move forward.\n");

                if(terrain[j+1].playerslot[j+1] == 0)
                {
                    terrain[j].playerslot[j] = tmp;
                    terrain[j].playerslot[j] = terrain[j+1].playerslot[j+1];
                    terrain[j+1].playerslot[j+1] = tmp;
                }
                else{
                    a++;
                    j++;
                }

                Nxt = currPos + a;
            }
            else if(currPos == Slotsize-1)
            {
                printf("You can only move backward.\n");

                if(terrain[j-1].playerslot[j-1] == 0)
                {
                    terrain[j].playerslot[j] = tmp;
                    terrain[j].playerslot[j] = terrain[j-1].playerslot[j-1];
                    terrain[j-1].playerslot[j-1] = tmp;
                }
                else{
                    a--;
                    j--;
                }

                Nxt = currPos - a;
            }     
        else   
        {

            puts("If you want to move forward, Enter '1'.\n");  
            puts("If you want to move backward, Enter '2'.\n");
            scanf("%d", &m);
            if(m == 1)
            {
                if(terrain[j+1].playerslot[j+1] == 0)
                {
                    terrain[j].playerslot[j] = tmp;
                    terrain[j].playerslot[j] = terrain[j+1].playerslot[j+1];
                    terrain[j+1].playerslot[j+1] = tmp;
                }
                else{
                a++;
                j++;
                }

                Nxt = currPos + a;
            }
            if(m == 2)
            {
                if(terrain[j-1].playerslot[j-1] == 0)
                {
                    terrain[j].playerslot[j] = tmp;
                    terrain[j].playerslot[j] = terrain[j-1].playerslot[j-1];
                    terrain[j-1].playerslot[j-1] = tmp;
                }
                else{
                a--;
                j--;
                }

                Nxt = currPos - a;
            }
        } 
        puts("Player moved.\n");        
        if(terrain[Nxt].stpoint[Nxt] == 1)
            {
                printf("Current position: level ground. No status change at this terrain. \n");
            }
 
        else if(terrain[Nxt].stpoint[Nxt] == 2)
            {
                printf("Current position: hill. Now changing status....\n");
                printf("If player's 'Dexterity < 50, loses 10 Strength points.\n");
                printf("If Dexterity >= 60, then the player gains 10 Strength points.\n");
                 if(x[Nxt].Dex[Nxt] < 50)
                {
                    x[Nxt].Strength[Nxt] -= 10;
                }
                else if(x[Nxt].Dex[Nxt] >= 60)
                {
                    x[Nxt].Strength[Nxt] +=10;
                }
            }
 
        else if(terrain[Nxt].stpoint[Nxt] == 3)
            {
                printf("Current position: city. Now changing status....\n");
                printf("If Smartness > 60, then the player gains 10 Magic Skills points. \n");
                printf("If Smartness <=50, then the player loses 10 Dexterity points. \n");
                if(x[Nxt].Smarts[Nxt] > 60)
                {
                    x[Nxt].Magic[Nxt] += 10;
                }
                else if(x[Nxt].Smarts[Nxt] <= 60)
                {
                    x[Nxt].Dex[Nxt] -= 10;
                }
            }
                        
        }
        else if(ans == 'A')
        {
            int defend, defendL=20, defendR=40, attack;
            for(j=0;j<Slotsize;j++)
            {
                if(terrain[j].playerslot[j] == i+1)
                {
                    attack = j;
                    printf("%da\n", attack);
                }
            }

            if(attack==0)
            {
                defendL=20;

                for(j=attack;j<Slotsize;j++)
                {
                    if(terrain[j].playerslot[j] != 0)
                    {
                        defendR = j;
                    }
                }

                defendR = defendR - attack;
                printf("%ddR\n", defendR);
            }
            else if(attack==Slotsize-1)
            {
                defendR = 20;

                for(j=attack;j>-1;j--)
                {
                    if(terrain[j].playerslot[j] != 0)
                    {
                        defendL = j;
                    }
                }

                defendL = attack - (-defendL);
                printf("%ddL\n", defendL);

            }
            else
            {
                for(j=attack;j<Slotsize;j++)
                {
                    if(terrain[j].playerslot[j] != 0)
                    {
                        defendR = j;
                    }
                }

                defendR = defendR - attack;
                printf("%ddR\n", defendR);

                for(j=attack;j>-1;j--)
                {
                    if(terrain[j].playerslot[j] != 0)
                    {
                        defendL = j;
                    }
                }

                defendL = attack - (-defendL);
                printf("%ddL\n", defendL);
            }
            
            
            if(defendL == defendR)
            {
                printf("1\n");
                int choice;
                printf("There are two closest players.\n");
                printf("Will you attack Player %d or Player %d?\n", terrain[defendL].playerslot[defendL], terrain[defendR].playerslot[defendR]);
                printf("Please enter the player number: ");
                scanf("%d", &choice);

                if(choice == terrain[defendL].playerslot[defendL])
                {
                    defend = -(defendL);
                }
                else if(choice == terrain[defendR].playerslot[defendR])
                {
                    defend = defendR;
                }
            }
            else if(defendL>defendR)
            {
                printf("2\n");
                printf("You attack the closest player to your right: Player %d.\n", terrain[defendR+attack].playerslot[defendR+attack]);
                defend = defendR;
                printf("%d\n", defend);
            }
            else if(defendR>defendL)
            {
                printf("3\n");
                printf("You attack the closest player to your left: Player %d.\n", terrain[attack-defendL].playerslot[attack-defendL]);
                defend = -(defendL);
                printf("%d\n", defend);
            } 

            if(x[attack+(defend)].Strength[attack+(defend)] <= 70)
            {
                printf("Your opponent has less than or equal to 70 Strength points.\n");
                printf("You overcame them and they took damage.\n");
                x[attack+(defend)].lifePoints[attack+(defend)] -= 0.5*(x[attack+(defend)].Strength[attack+(defend)]);
            }
            else if(x[attack].Strength[attack] > 70)
            {
                printf("Your opponent has greater than 70 Strength points.\n");
                printf("They fought back and you took damage.\n");
                x[attack].lifePoints[attack] -= 0.3*(x[attack].Strength[attack]);
            }
        }
    }

    //Prints out Player stats
    printf("\n");
    for(i=0;i<Playsize;i++)
    {
        printf("%s (%s, %d)\n", x[i].Name[i], x[i].Archtype[i], x[i].lifePoints[i]);
    }
}
