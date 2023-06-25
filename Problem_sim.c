#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check_fail(int a,int b)
{
	if (a==b)
	{
		printf("Player failed");
	}

}




void main()
{
	int wc=0,lc=0;/*counts number of wins and losses for n iterations*/
	int change_c_w=0,no_change_w=0;/*no of wins with change or no change*/
	int change_c_l=0,no_change_l=0;/*no of losses with change or no change*/
	
	int i,c;
	time_t t;

	srand(time(&t));
	/*Assigning random prize door*/
	/*Assigning random contestant choice*/
    int N;
    int try; 
    printf("Enter the number of doors:");
    scanf("%d",&N);
    printf("\nNumber of iterations:");
    scanf("%d",&try);
	for(int j=0;j<try;j++)
	{
		
	int door[N];
	int player_choice=0;
	int true_choice=0;
	int empty_door[N-1];
	int false_door=0;
	int new_choice[N-1];
    for(i=0;i<N;i++)
    {
        door[i]=i;
    }
    for(i=0;i<N-1;i++)
    {
        empty_door[i]=0;
        new_choice[i]=0;
    }

	player_choice=rand()%N;
	true_choice=rand()%N;
	printf("player choice:%d\n",player_choice);
	printf("true choice:%d\n",true_choice);

	c=0;
	for (i=0;i<N;i++)	
	{
		if(c<(N-1)){
		if (door[i]!=true_choice)
		{
			
			empty_door[c]=door[i];
			c++;
		}

		}
	}
	for(i=0;i<(N-1);i++)
	{
		if (empty_door[i]!=player_choice)
		{
			false_door=empty_door[i];
			

		}
		else{continue;}
	}
	c=0;i=0;
	while(c<(N-1))
	{
		if (false_door!=door[i])
		{
			new_choice[c]=door[i];
			c++;
		}
		i++;
	}
	int final_choice=(rand()%10)%(N-1);
	
	printf("final_choice:%d\n",new_choice[final_choice]);
	if (new_choice[final_choice]==true_choice && new_choice[final_choice]==player_choice )
	{
		wc++;
		no_change_w++;
		
		printf("Win\n");
	}
	else if(new_choice[final_choice]==true_choice && new_choice[final_choice]!=player_choice)
	{
		wc++;
		change_c_w++;
		printf("\nWin\n");
		continue;
	}
	else if(new_choice[final_choice]!=true_choice && new_choice[final_choice]==player_choice)
	{
		lc++;
		no_change_l++;
		printf("\nFail\n");
		continue;
	}
	else if(new_choice[final_choice]!=true_choice && new_choice[final_choice]!=player_choice)
	{
		lc++;
		change_c_l++;
		printf("\nFail\n");
		continue;
	}

	}


    printf("Number of wins:%d\n",wc);
	printf("Number of losses:%d\n",lc);
	printf("Number of losses with change:%d\n",change_c_l);
	printf("Number of losses without change:%d\n",no_change_l);
	printf("Number of wins with change:%d\n",change_c_w);
	printf("Number of wins without change:%d\n",no_change_w);
	printf("Percentage wins if changed:%f\n",change_c_w/(wc+0.0));
	printf("Percentage wins if not changed:%f\n",no_change_w/(wc+0.0));
	printf("percentage wins:%f",wc/(wc+lc+0.0));
}
