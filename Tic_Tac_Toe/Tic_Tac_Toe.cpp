#include<iostream>
#include<unistd.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#define MAX 3
using namespace std;
/* Matrix */
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
/*Function Prototypes*/
void heading();
void intro();
void displayboard();
int isWin();
int isDraw();
void gameplay();
void marking(int,char);
int isMarked(int);
void reset();
/*-------------------------------*/
int main()
{
    intro();
    gameplay();
    return 0;    
}
void heading()
{
	 //Set Text Color to Yellow
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<endl<<endl;
    cout<<"\t\t\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"\t\t\t    |      WELCOME TO TIC TAC TOE GAME      |"<<endl;
    cout<<"\t\t\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
}
void intro()
{
    //Set Text Color to Yellow
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t TIC  "<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t\t TAC  "<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t\t\t TOE  "<<endl;
    cout<<endl;
    //Set Text Color to White
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    sleep(1);
    cout<<"\t\t\t\t\t Loading  ";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(2);
    //getch();
    system("cls");
    heading();
    //Set Text Color to white
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<"\t\t\t                RULES OF THE GAME"<<endl;
    cout<<"\t\t\t                *****************"<<endl;
    displayboard();
    cout<<endl;
    cout<<"\t\t\t     * Enter position number as shown in the\n\t\t\t       board to mark your desired postion."<<endl<<endl;
    cout<<"\t\t\t           Press any key to continue";
    getch();
}
void displayboard()
{
	int i,j;
    cout<<" \n\t\t\t\t    ._______._______._______.\n";
    for(i=0;i<MAX;i++)
    {
        cout<<"\t\t\t\t    |       |       |       |\n\t\t\t\t    ";
        for(j=0;j<MAX;j++)
            cout<<"|   "<<board[i][j]<<"   ";
        cout<<"|\n\t\t\t\t    |_______|_______|_______|\n";
    }
}
int isWin()
{
	//Checking row wise
	if(board[0][0]==board[0][1] && board[0][1]==board[0][2])
		return 1;
	if(board[1][0]==board[1][1] && board[1][1]==board[1][2])
		return 1;
	if(board[2][0]==board[2][1] && board[2][1]==board[2][2])
		return 1;
	//Checking column wise
	if(board[0][0]==board[1][0] && board[1][0]==board[2][0])
		return 1;
	if(board[0][1]==board[1][1] && board[1][1]==board[2][1])
		return 1;
	if(board[0][2]==board[1][2] && board[1][2]==board[2][2])
		return 1;
	//Checking Diagonally
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
		return 1;
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
		return 1;
	return 0;
}
int isDraw()
{
	int i,j;
	int c=0;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if(board[i][j]=='X' || board[i][j]=='O')
				c++;
		}
	}
	if(c==9 && !isWin())
		return 1;
	else
		return 0;
}
void gameplay()
{
	char ch;
	system("cls");
	char p1[30],p2[30];
	char aP[30],pP[30];//Active Player, Passive Player
	int pos,lastpos=-1;
	char mark='X';
	heading();
	//Set Text Color to white
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<"\t\t\t     Enter name of Player 1 : ";
    cin>>p1;
    cout<<"\t\t\t     Enter name of Player 2 : ";
    cin>>p2;
    strcpy(aP,p1);
    strcpy(pP,p2);
    while(!isWin() && !isDraw())
    {
    	while(1)
    	{
	    	system("cls");
	    	heading();
	    	//Set Text Color to white
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	    	cout<<"\t\t\t     Player 1 (X) : "<<p1<<endl;
	    	cout<<"\t\t\t     Player 2 (O) : "<<p2<<endl;
	    	displayboard();
	    	if(lastpos!=-1)
	    		cout<<endl<<"\t\t\t     "<<pP<<" marked at position "<<lastpos<<endl;
	    	cout<<endl<<"\t\t\t     "<<aP<<"'s turn, Mark -> "<<mark<<endl;
	    	cout<<"\t\t\t     Enter Position : ";
	    	cin>>pos;
	    	if((pos>=1 && pos<=9) && !isMarked(pos))
	    		break;
    	}
    	marking(pos,mark);
    	lastpos=pos;
    	if(mark=='X')
    	{
    		mark='O';
    		strcpy(aP,p2);
    		strcpy(pP,p1);
		}
		else if(mark=='O')
		{
    		mark='X';
    		strcpy(aP,p1);
    		strcpy(pP,p2);
		}
	}
	if(isWin())
	{
		system("cls");
		heading();
		//Set Text Color to white
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	    cout<<"\t\t\t     Player 1 (X) : "<<p1<<endl;
	    cout<<"\t\t\t     Player 2 (O) : "<<p2<<endl;
	    //Set Text Color to Green
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	    cout<<"\t\t\t     Result : "<<pP<<" Wins"<<endl;
	    //Set Text Color to white
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else if(isDraw())
	{
		system("cls");
		heading();
		//Set Text Color to white
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	    cout<<"\t\t\t     Player 1 (X) : "<<p1<<endl;
	    cout<<"\t\t\t     Player 2 (O) : "<<p2<<endl;
	    //Set Text Color to Aqua
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	    cout<<"\t\t\t     Result : Match Draw"<<endl;
	    //Set Text Color to white
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	cout<<"\t\t\t     Do you want to play again ? Y/N ";
	while(1)
	{
		ch=getch();
		if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')
			break;
	}
	if(ch=='Y' || ch=='y')
	{
		reset();
		gameplay();
	}
	else
	{
		cout<<endl<<"\t\t\t     Exiting";
	    sleep(1);
	    cout<<".";
	    sleep(1);
	    cout<<".";
	    sleep(1);
	    cout<<".";
	    sleep(2);
	    system("cls");
	}	
}
void reset()
{
	board[0][0]='1';
	board[0][1]='2';
	board[0][2]='3';
	board[1][0]='4';
	board[1][1]='5';
	board[1][2]='6';
	board[2][0]='7';
	board[2][1]='8';
	board[2][2]='9';
}
void marking(int pos,char mark)
{
	switch(pos)
	{
		case 1:
			board[0][0]=mark;
		break;
		case 2:
			board[0][1]=mark;
		break;
		case 3:
			board[0][2]=mark;
		break;
		case 4:
			board[1][0]=mark;
		break;
		case 5:
			board[1][1]=mark;
		break;
		case 6:
			board[1][2]=mark;
		break;
		case 7:
			board[2][0]=mark;
		break;
		case 8:
			board[2][1]=mark;
		break;
		case 9:
			board[2][2]=mark;
		break;
	}
}
int isMarked(int pos)
{
		switch(pos)
	{
		case 1:
			if(board[0][0]=='X' || board[0][0]=='O')
				return 1;
		break;
		case 2:
			if(board[0][1]=='X' || board[0][1]=='O')
				return 1;
		break;
		case 3:
			if(board[0][2]=='X' || board[0][2]=='O')
				return 1;
		break;
		case 4:
			if(board[1][0]=='X' || board[1][0]=='O')
				return 1;
		break;
		case 5:
			if(board[1][1]=='X' || board[1][1]=='O')
				return 1;
		break;
		case 6:
			if(board[1][2]=='X' || board[1][2]=='O')
				return 1;
		break;
		case 7:
			if(board[2][0]=='X' || board[2][0]=='O')
				return 1;
		break;
		case 8:
			if(board[2][1]=='X' || board[2][1]=='O')
				return 1;
		break;
		case 9:
			if(board[2][2]=='X' || board[2][2]=='O')
				return 1;
		break;
	}
	return 0;
}
