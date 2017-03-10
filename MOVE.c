//Moving part//

if(ans == 'M')
        {
        int i, j, m;
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
		
		puts("If you want to move forward, Enter '1'.\n");	
		puts("If you want to move backward, Enter '2'.\n");
		scanf("%d", &m);
		if(m == 1)
		{
			if(terrain[j+1].playerslot[j+1] == 0)
			{
				terrain[j].playerslot[j] = terrain[j + 1].playerslot[j + 1];
			}
			else{
				j++ ;
			}
		
		}
		if(m == 2)
		{
			if(terrain[j-1].playerslot[j-1] == 0)
			{
				terrain[j].playerslot[j] = terrain[j - 1].playerslot[j - 1];
			}
			else{
				j-- ;
			}
		} 
		puts("Player moved.\n");		
		if(terrain[i].stpoint[i] == 1)
 			{
 				printf("Current position: level ground. No status change at this terrain. \n");
 			}
 
 		else if(terrain[i].stpoint[i] == 2)
	 		{
 				printf("Current position: hill. Now changing status....\n");
 				printf("If player's 'Dexterity < 50, loses 10 Strength points.\n");
 				printf("If Dexterity >= 60, then the player gains 10 Strength points.\n");
 				 if(x[i].Dex[i] < 50)
        		{
            		x[i].Strength[i] -= 10;
        		}
        		else if(x[i].Dex[i] >= 60)
        		{
        			x[i].Strength[i] +=10;
				}
	 		}
 
 		else if(terrain[i].stpoint[i] == 3)
 			{
 				printf("Current position: city. Now changing status....\n");
 				printf("If Smartness > 60, then the player gains 10 Magic Skills points. \n");
 				printf("If Smartness <=50, then the player loses 10 Dexterity points. \n");
 				if(x[i].Smarts[i] > 60)
				{
					x[i].Magic[i] += 10;
				}
				else if(x[i].Smarts[i] <= 60)
				{
					x[i].Dex[i] -= 10;
				}
 			}
				
				
				
        }

