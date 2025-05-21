#include<stdio.h>
#include<stdlib.h>
//#################################################################################################################################################################
//#################################################################################################################################################################
struct scores
{
	float score;
	int xplace;
	int flip;
};
//#################################################################################################################################################################
void place(char input,int (* ptr)[10],int * scoreptr);
int reload(int xplace,char input,int (* ptr)[10]);
float scoref(char input,int (* ptr)[10],int xplace);
float count(char input,int xplace,int yplace,int (* ptr)[10]);
float countf(int xplace,int yplace,int (* ptr)[10]);
int score_and_refresh(int (* ptr)[10],int * score);
int checkinput(char input);
int checkdeath(int (* chart)[10]);
//#################################################################################################################################################################
int main()
{
	char input1;
	char input2;
	int getscore=0;
	int * scoreptr=&getscore;
	int chart[20][10]={0};
	int (* ptr)[10]=chart;
	input1=getchar();
	input2=getchar();
	getchar();
	for(int m=checkinput(input1),n=checkdeath(chart);m!=0&&n!=0;)
	{
		place(input1,ptr,scoreptr);
		printf("%d\n",getscore);
		input1=input2;
		scanf("%c",&input2);
		getchar();
		fflush(stdout);
	}
	return 0;
}







void place(char input,int (* ptr)[10],int * scoreptr)
{
	float score[10]={0.0};
	struct scores best1;
	struct scores best2;
	struct scores best3;
	struct scores best4;
	best1.flip=0;
	best1.score=0.0;
	best1.xplace=0;
	best2.flip=0;
	best2.score=0.0;
	best2.xplace=0;
	best3.flip=0;
	best3.score=0.0;
	best3.xplace=0;
	best4.flip=0;
	best4.score=0.0;
	best4.xplace=0;
	int turn;
	switch(input)
	{
		case 'I':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('I',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('i',ptr,i);
			}
			best2.score=score[0];
			best2.xplace=0; 
			best2.flip=1;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best2.score=score[i];
					best2.xplace=i;
				}
			}
			//
			if(best1.score<=best2.score)
			{
				reload(best1.xplace,'I',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best1.flip,best1.xplace);
			}
			else
			{
				reload(best2.xplace,'i',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best2.flip,best2.xplace);
			}
			break;
		case 'S':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('S',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('s',ptr,i);
			}
			best2.score=score[0];
			best2.xplace=0; 
			best2.flip=1;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best2.score)
				{
					best2.score=score[i];
					best2.xplace=i;
				}
			}
			//
			if(best1.score<=best2.score)
			{
				reload(best1.xplace,'S',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best1.flip,best1.xplace);
			}
			else
			{
				reload(best2.xplace,'s',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best2.flip,best2.xplace);
			}
			break;
		case 'Z':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('Z',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('z',ptr,i);
			}
			best2.score=score[0];
			best2.xplace=0; 
			best2.flip=1;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best2.score)
				{
					best2.score=score[i];
					best2.xplace=i;
				}
			}
			//
			if(best1.score<=best2.score)
			{
				reload(best1.xplace,'Z',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best1.flip,best1.xplace);
			}
			else
			{
				reload(best2.xplace,'z',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best2.flip,best2.xplace);
			}
			break;
		case 'O':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('O',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			reload(best1.xplace,'O',ptr);
			score_and_refresh(ptr,scoreptr);
			printf("%d %d\n",best1.flip,best1.xplace);
			break;
		case 'T':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('T',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('t',ptr,i);
			}
			best2.score=score[0];
			best2.xplace=0; 
			best2.flip=1;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best2.score)
				{
					best2.score=score[i];
					best2.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('Y',ptr,i);
			}
			best3.score=score[0];
			best3.xplace=0; 
			best3.flip=2;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best3.score)
				{
					best3.score=score[i];
					best3.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('y',ptr,i);
			}
			best4.score=score[0];
			best4.xplace=0; 
			best4.flip=3;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best4.score)
				{
					best4.score=score[i];
					best4.xplace=i;
				}
			}
			if(best1.score<=best2.score&&best1.score<=best3.score&&best1.score<=best4.score)
			{
				reload(best1.xplace,'T',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best1.flip,best1.xplace);
			}
			else if(best2.score<best1.score&&best2.score<=best3.score&&best2.score<=best4.score)
			{
				reload(best2.xplace,'t',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best2.flip,best2.xplace);
			}
			else if(best3.score<best1.score&&best3.score<best2.score&&best3.score<=best4.score)
			{
				reload(best3.xplace,'Y',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best3.flip,best3.xplace);
			}
			else if(best4.score<best1.score&&best4.score<best3.score&&best4.score<best2.score)
			{
				reload(best4.xplace,'y',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best4.flip,best4.xplace);
			}
			break;
		case 'J':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('J',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('j',ptr,i);
			}
			best2.score=score[0];
			best2.xplace=0; 
			best2.flip=1;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best2.score)
				{
					best2.score=score[i];
					best2.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('K',ptr,i);
			}
			best3.score=score[0];
			best3.xplace=0; 
			best3.flip=2;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best3.score)
				{
					best3.score=score[i];
					best3.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('k',ptr,i);
			}
			best4.score=score[0];
			best4.xplace=0; 
			best4.flip=3;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best4.score)
				{
					best4.score=score[i];
					best4.xplace=i;
				}
			}
			if(best1.score<=best2.score&&best1.score<=best3.score&&best1.score<=best4.score)
			{
				reload(best1.xplace,'J',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best1.flip,best1.xplace);
			}
			else if(best2.score<best1.score&&best2.score<=best3.score&&best2.score<=best4.score)
			{
				reload(best2.xplace,'j',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best2.flip,best2.xplace);
			}
			else if(best3.score<best1.score&&best3.score<best2.score&&best3.score<=best4.score)
			{
				reload(best3.xplace,'K',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best3.flip,best3.xplace);
			}
			else if(best4.score<best1.score&&best4.score<best3.score&&best4.score<best2.score)
			{
				reload(best4.xplace,'k',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best4.flip,best4.xplace);
			}
			break;
		case 'L':
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('L',ptr,i);
			}
			best1.score=score[0];
			best1.xplace=0; 
			best1.flip=0;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best1.score)
				{
					best1.score=score[i];
					best1.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('l',ptr,i);
			}
			best2.score=score[0];
			best2.xplace=0; 
			best2.flip=1;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best2.score)
				{
					best2.score=score[i];
					best2.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('P',ptr,i);
			}
			best3.score=score[0];
			best3.xplace=0; 
			best3.flip=2;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best3.score)
				{
					best3.score=score[i];
					best3.xplace=i;
				}
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=0;
			}
			//
			for(int i=0;i<10;i++)
			{
				score[i]=scoref('p',ptr,i);
			}
			best4.score=score[0];
			best4.xplace=0; 
			best4.flip=3;
			for(int i=1;i<10;i++)
			{
				if(score[i]<best4.score)
				{
					best4.score=score[i];
					best4.xplace=i;
				}
			}
			if(best1.score<=best2.score&&best1.score<=best3.score&&best1.score<=best4.score)
			{
				reload(best1.xplace,'L',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best1.flip,best1.xplace);
			}
			else if(best2.score<best1.score&&best2.score<=best3.score&&best2.score<=best4.score)
			{
				reload(best2.xplace,'l',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best2.flip,best2.xplace);
			}
			else if(best3.score<best1.score&&best3.score<best2.score&&best3.score<=best4.score)
			{
				reload(best3.xplace,'P',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best3.flip,best3.xplace);
			}
			else if(best4.score<best1.score&&best4.score<best3.score&&best4.score<best2.score)
			{
				reload(best4.xplace,'p',ptr);
				score_and_refresh(ptr,scoreptr);
				printf("%d %d\n",best4.flip,best4.xplace);
			}
			break;
	}
}









float scoref(char input,int (* ptr)[10],int xplace)
{
	int check=0;
	float score=0.0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(ptr[j][i]==1)
			{
			ptr[j][i]=2;		
			}
		}
	}
	switch(input)
	{
		case 'I':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0&&ptr[i][xplace+3]==0)
				{
					score=(float)i-count('I',xplace,i,ptr)+0.01*xplace;
					break;	
				}
			}
			break;
		case 'i':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+3][xplace]==0)
				{
					score=(float)i+3-count('i',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'J':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0)
				{
					score=(float)i+1-count('J',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'j':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+2][xplace+1]==0)
				{
					score=(float)i+2-count('j',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'k':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					score=(float)i+2-count('k',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'T':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace]==0)
				{
					score=(float)i+1-count('T',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 't':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+1][xplace+1]==0)
				{
					score=(float)i+2-count('t',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'O':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0)
				{
					score=(float)i+1-count(input,xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'L':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0&&ptr[i+1][xplace+2]==0)
				{
					score=(float)i+1-count('L',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'l':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i][xplace+1]==0)
				{
					score=(float)i+2-count('l',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'P':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0&&ptr[i][xplace]==0)
				{
					score=(float)i+1-count('P',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'S':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0)
				{
					score=(float)i+1-count('S',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'z':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					score=(float)i+2-count('z',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		//####################################
		case 'K':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0&&ptr[i][xplace+2]==0)
				{
					score=(float)i+1-count('K',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'Y':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace+1]==0&&ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0)
				{
					score=(float)i+1-count('Y',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'y':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					score=(float)i+2-count('y',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'p':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+2][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					score=(float)i+2-count('p',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 's':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i][xplace+1]==0)
				{
					score=(float)i+2-count('s',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
		case 'Z':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0)
				{
					score=(float)i+1-count('Z',xplace,i,ptr)+0.01*xplace;
					break;
				}
			}
			break;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(ptr[j][i]==2)
			{
			ptr[j][i]=1;		
			}
		}
	}
	return score;
}
//#####################################################################################################################################################################
float count(char input,int xplace,int yplace,int (* ptr)[10])
{
	float num=0;
	switch(input)
	{
		case 'I':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+2,yplace,ptr)+countf(xplace+3,yplace,ptr);
			return num;
			break;
		case 'T':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+2,yplace,ptr)+countf(xplace+1,yplace+1,ptr);
			return num;
			break;
		case 'O':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+1,ptr);
			return num;
			break;
		case 'J':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+2,yplace,ptr)+countf(xplace,yplace+1,ptr);
			return num;
			break;
		case 'L':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+2,yplace,ptr)+countf(xplace+2,yplace+1,ptr);
			return num;
			break;
		case 'S':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+2,yplace+1,ptr);
			return num;
			break;
		case 'Z':
			num=num+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+2,yplace,ptr);
			return num;
			break;
		case 'i':
			num=num+countf(xplace,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace,yplace+2,ptr)+countf(xplace,yplace+3,ptr);
			return num;
			break;
		case 't':
			num=num+countf(xplace,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace,yplace+2,ptr);
			return num;
			break;
		case 'Y':
			num=num+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+2,yplace+1,ptr);
			return num;
			break;
		case 'y':
			num=num+countf(xplace+1,yplace,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+2,ptr);
			return num;
			break; 
		case 'j':
			num=num+countf(xplace,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace,yplace+2,ptr)+countf(xplace+1,yplace+2,ptr);
			return num;
			break;
		case 'K':
			num=num+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+2,yplace+1,ptr)+countf(xplace+2,yplace,ptr);
			return num;
			break;
		case 'k':
			num=num+countf(xplace,yplace,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+1,yplace+2,ptr);
			return num;
			break;
		case 'P':
			num=num+countf(xplace,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+2,yplace+1,ptr);
			return num;
			break;
		case 'p':
			num=num+countf(xplace,yplace+2,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+1,yplace+2,ptr);
			return num;
			break;
		case 'l':
			num=num+countf(xplace,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace,yplace+2,ptr)+countf(xplace+1,yplace,ptr);
			return num;
			break;
		case 's':
			num=num+countf(xplace,yplace+1,ptr)+countf(xplace,yplace+2,ptr)+countf(xplace+1,yplace,ptr)+countf(xplace+1,yplace+1,ptr);
			return num;
			break;
		case 'z':
			num=num+countf(xplace,yplace,ptr)+countf(xplace,yplace+1,ptr)+countf(xplace+1,yplace+1,ptr)+countf(xplace+1,yplace+2,ptr);
			return num;
			break;
	}
}
//###################################################################################################################################################################
float countf(int xplace,int yplace,int (* ptr)[10])
{
	float num=0.0;
	if(ptr[yplace+1][xplace]==2)
	{
		num++;
	}
	if(ptr[yplace-1][xplace]==2&&yplace!=0)
	{
		num++;
	}
	if(yplace==0)
	{
		num++;
	}
	if(xplace==0||xplace==9)
	{
		num++;
	}
	if(ptr[yplace][xplace+1]==2&&xplace!=9)
	{
		num++;
	}
	if(ptr[yplace][xplace-1]==2&&xplace!=0)
	{
		num++;
	}
	return num;
}









int reload(int xplace,char input,int (* ptr)[10])
{
	switch(input)
	{
		case 'I':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0&&ptr[i][xplace+3]==0)
				{
					ptr[i][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i][xplace+2]=1;
					ptr[i][xplace+3]=1;
					break;	
				}
			}
			break;
		case 'i':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+3][xplace]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i+2][xplace]=1;
					ptr[i+3][xplace]=1;
					break;
				}
			}
			break;
		case 'J':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i][xplace+2]=1;
					break;
				}
			}
			break;
		case 'j':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+2][xplace+1]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i+2][xplace]=1;
					ptr[i+2][xplace+1]=1;
					break;
				}
			}
			break;
		case 'k':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					ptr[i][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+2][xplace+1]=1;
					break;
				}
			}
			break;
		case 'T':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace]==0)
				{
					ptr[i][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+2][xplace]=1;
					break;
				}
			}
			break;
		case 't':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+1][xplace+1]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i+2][xplace]=1;
					ptr[i+1][xplace+1]=1;
					break;
				}
			}
			break;
		case 'O':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace+1]=1;
					break;
				}
			}
			break;
		case 'L':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0&&ptr[i+1][xplace+2]==0)
				{
					ptr[i][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i][xplace+2]=1;
					ptr[i+1][xplace+2]=1;
					break;
				}
			}
			break;
		case 'l':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i][xplace+1]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i+2][xplace]=1;
					ptr[i][xplace+1]=1;
					break;
				}
			}
			break;
		case 'P':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0&&ptr[i][xplace]==0)
				{
					ptr[i+1][xplace]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+1][xplace+2]=1;
					ptr[i][xplace]=1;
					break;
				}
			}
			break;
		case 'S':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0)
				{
					ptr[i][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+1][xplace+2]=1;
					break;
				}
			}
			break;
		case 'z':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace]==0&&ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					ptr[i][xplace]=1;
					ptr[i+1][xplace]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+2][xplace+1]=1;
					break;
				}
			}
			break;
		//####################################
		case 'K':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0&&ptr[i][xplace+2]==0)
				{
					ptr[i+1][xplace]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+1][xplace+2]=1;
					ptr[i][xplace+2]=1;
					break;
				}
			}
			break;
		case 'Y':
			for(int i=0;i<20;i++)
			{
				if(ptr[i][xplace+1]==0&&ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i+1][xplace+2]==0)
				{
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+1][xplace+2]=1;
					break;
				}
			}
			break;
		case 'y':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					ptr[i+1][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+2][xplace+1]=1;
					break;
				}
			}
			break;
		case 'p':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+2][xplace]==0&&ptr[i][xplace+1]==0&&ptr[i+1][xplace+1]==0&&ptr[i+2][xplace+1]==0)
				{
					ptr[i+2][xplace]=1;
					ptr[i][xplace+1]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i+2][xplace+1]=1;
					break;
				}
			}
			break;
		case 's':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+2][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i][xplace+1]==0)
				{
					ptr[i+1][xplace]=1;
					ptr[i+2][xplace]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i][xplace+1]=1;
					break;
				}
			}
			break;
		case 'Z':
			for(int i=0;i<20;i++)
			{
				if(ptr[i+1][xplace]==0&&ptr[i+1][xplace+1]==0&&ptr[i][xplace+1]==0&&ptr[i][xplace+2]==0)
				{
					ptr[i+1][xplace]=1;
					ptr[i+1][xplace+1]=1;
					ptr[i][xplace+1]=1;
					ptr[i][xplace+2]=1;
					break;
				}
			}
			break;
	}
	return 0;
}









int score_and_refresh(int (* chart)[10],int * score)
{
	int check[20]={0};
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(chart[i][j]==0)
			{
				check[i]=1;
			}
		}
	}
	for(int i=0;i<20;)
	{
		if(check[i]==0)
		{
			if(check[i+1]==0)
			{
				if(check[i+2]==0)
				{
					if(check[i+3]==0)
					{
						*score+=800;
						i++;
					}
					else
					{
						*score+=500;
						i++;
					}
				}
				else
				{
					*score+=300;
					i++;
				}
			}
			else
			{
				*score+=100;
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	for(int i=0;i<18;)
	{
		int check=0;
		for(int j=0;j<10;j++)
		{
			if(chart[i][j]==0)
			{
				check=1;
			}
		}
		if(check==0)
		{
			for(int j=0;j<10;j++)
			{
				chart[i][j]=chart[i+1][j];
			}
		}
		else
		{
			i++;
		}
	}
	return 0;
}









int checkinput(char input)
{
	if(input=='E'||input=='X')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//###################################################################################################################################################################

int checkdeath(int (* chart)[10])
{
	int check=1;
	for(int i=0;i<10;i++)
	{
		if(chart[19][i]==1)
		{
			check=0;
		}
	}
	return check;
} 
