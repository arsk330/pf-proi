#include<iostream>
#include<string>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
void setRandomShips(char board[10][10]);
void vsComputer(char playerBoard[10][10],char computerBoard[10][10]);
void computerAttack(char playerBoard[10][10], int &computerScore);
void updateScore(int &score);
void initializeBoard(char board[10][10]);
void clearScreen();
void playerAttack(char opponentBoard[10][10], int &playerScore);
void showGameMenu();
void displayResult(int player1Score, int player2Score);
void clearBoard(char board[10][10]);
void printBoard(char board[10][10], bool hideShips=false);
void setColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}
void initializeBoard(char board[10][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			board[i][j]='~';
		}
	}
	
}
void placeship(char board[10][10],int row,int column,int as)
{
	if(as==15)
	{
		board[row][column]='S';
	}else if(as==40)
	{
		board[row][column]='~';
	}else if(as==3)
	{
		if(board[row][column]=='S')
		{
			board[row][column]='X';
		}else	if(board[row][column]=='~') 
		{
		    board[row][column]='O';	
		}
		
	}
	
}

bool placement(char board[10][10],int size,int ro,int co)
{  
	for(int j=0;j<size;j++)
	{
		if(board[ro][co]=='S')
		{
		return true;
		}
		co++;	
	} 

	return false;
}
bool vertical(char board[10][10], int sizee, int ro, int co)
{
    for (int j=0;j<sizee;j++)
    {
        if (board[ro + j][co] == 'S') 
		{
			return true;	
		}
    }
    return false;
}


void p2()
{
	string shipname[5]={" Aircraft Carrier","Battleship","Destroyer","Submarine","Patrol Boat"};
	int shipsize[5]={5,4,3,3,2};
	bool shipsink[5]={false,false,false,false,false};
	char game[10][10];
	char game1[10][10];
	initializeBoard(game);
	initializeBoard(game1);
	srand(time(0));
	int number,place,q=0,k,c,r;
	int num=0;
	int option;
	string name;
	cout<<"Enter your Name :";
	cin>>name;
	printBoard(game);
	q=0;
	do
	{
	if(q>0)
	{
		cout<<"Invalid ";
	}		
		cout<<"Ship placement option : ";
		cout<<"1. Manually   ";
		cout<<"2. Randomly    ";
		cin>>place;
		q++;		
	}while(place>2||place<=0);
	if (place==1)
	{
		for(int i=5;i>=1;i--)
		{
			int c1=0,c2=0,c3=0;
			int r1=0,r22=0;
			q=0;
			int size=shipsize[num];
			cout<<shipname[num]<<" has "<<shipsize[num]<<" size"<<endl;
			do
			{
				if(q>0)
				{
					cout<<"Invalid option Again ";
				}
				k=0;
				do
				{
					if(k>0)
					{
						cout<<"Invalid option Again ";
					}
					cout<<"Enter the number of column (0-9) : ";
					cin>>c;
					k++;
			}while(c>9||c<0);
			cout<<"Enter the number of rows (0-9) : ";
			cin>>r;
			q++;
			}while(r<0||r>9||(c + size -1 >9 )||c>9||c<0 || placement(game,size,r,c));
			 c1=c;
			 c2=c;
			 c3=c;
			 r1=r;
			 r22=r;
			
			for(int j=0;j<shipsize[num];j++)
			{
				placeship(game,r,c,15);
				c++;
			}			
			printBoard(game);
			char ch;
			cout<<"Do you want to rotate the ship (Y or N ) : ";
			cin>>ch;
			int a=0;
			if(ch=='Y'||ch=='y')
			{
				for(int m=1;m<shipsize[num];m++)
				{
					r++;
					if(vertical(game,size,r,c1)==false && (r+size-1)<=9)
					{
						a=10;
					}else 
					{
						a=2;
						cout<<"It cannot rotate vertically"<<endl;
						break ;
					}
				}
				
			}else if (ch=='N'||ch=='n')
			{
				cout<<"OK! you do not want to rotate"<<endl;
				
			}			
			if(a==10)
			{
				for(int j=0;j<shipsize[num];j++)
			    {
			    	a=40;
					placeship(game,r1,c2,a);
					c2++;
				}				
				for(int j=0;j<shipsize[num];j++)
				{
					a=15;
					placeship(game,r22,c3,a);
					r22++;
				}
				printBoard(game);	
			}
			num++;
	    }
	}else if(place==2)
	{
		num=0;
		for(int j=5;j>=1;j--)
		{
			cout<<shipname[num]<<" has "<<shipsize[num]<<" size"<<endl;
			num++;
		}
		num=0;
		for(int i=5;i>=1;i--)
		{
			int size=shipsize[num];
			do
			{
				c=rand()%10;
				r=rand()%10;
			}while(r<0||r>9||(c + size -1 >9 )||c>9||c<0 || placement(game,size,r,c));
			for(int j=0;j<shipsize[num];j++)
			{
				placeship(game,r,c,15);
				c++;
			}
			num++;
		
		}
		printBoard(game);
	}	
}
void showGameMenu()
{
	
	cout<<" ======================================"<<endl;
	cout<<endl<<" \tWELCOME TO BATTLESHIP GAME "<<endl<<endl;
	cout<<" ======================================"<<endl<<endl;
	cout<<" \t       MAIN MENU  "<<endl<<endl;
	cout<<" --------------------------------------"<<endl;
	cout<<" 1. Start New Game "<<endl;
	cout<<" 2. Instructions "<<endl;
	cout<<" 3. View Leaderboard "<<endl;
	cout<<" 4. Exit "<<endl;
	cout<<" --------------------------------------"<<endl<<endl;
	string shipname[5]={" Aircraft Carrier","Battleship","Destroyer","Submarine","Patrol Boat"};
	int shipsize[5]={5,4,3,3,2};
	bool shipsink[5]={false,false,false,false,false};
	char game[10][10];
	char game1[10][10];
	srand(time(0));
	int number,place,q=0,c,r;
	int option;
	string name;
	cin>>number;
	if(number==1)
	{   
		cout<<"Choose the modes "<<endl;        
		cout<<"1. Player Vs Player "<<endl;
		cout<<"2. Player Vs Computer "<<endl;
		cin>>option;
		if(option==2)
		{
			p2();	
		}
	}else if(number==2)
	{
		
	}else if(number==3)
	{
		
	}else if(number==4)
	{
		
	}else 
	{
		cout<<"Invalid number "<<endl;
	}
	
	
	
}
void printBoard(char board[10][10], bool hideShips)
{
	cout<<endl;
    cout << "       0     1     2     3     4     5     6     7     8     9  " << endl;

    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    if(hideShips==false)
    {
    	for(int i=0;i<10;i++)
    	{
    		cout<<" "<<i <<"  ¦";
  	  		for(int j=0;j<10;j++)
    		{
    			if(board[i][j]=='X')
    			{
    				setColor(7, 4); cout << "  X  "; setColor(7,0);cout<<"¦";
				}else if(board[i][j]=='O')
				{
					setColor(7, 13); cout << "  O  "; setColor(7,0);cout<<"¦";
				} else if(board[i][j]=='S')
				{
					setColor(0,15);cout<<"  "<<board[i][j]<<"  " ;setColor(7,0);cout<<"¦";
				}else
				{
					setColor(7, 1); cout <<"  "<<board[i][j]<<"  " ; setColor(7,0);cout<<"¦";
				}
			}
			cout<<endl;
			cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
		}
	}else if(hideShips==true)
    {
    	for(int i=0;i<10;i++)
    	{
    		cout<<" "<<i <<"  ¦";
  	  		for(int j=0;j<10;j++)
    		{
    			if(board[i][j]=='X')
    			{
    				setColor(7, 4); cout << "  X  "; setColor(7,0);cout<<"¦";
				}else if(board[i][j]=='O')
				{
					setColor(7, 13); cout << "  O  "; setColor(7,0);cout<<"¦";
				}else
				{
					setColor(7, 1); cout <<"  "<<board[i][j]<<"  " ; setColor(7,0);cout<<"¦";
				}
			}
			cout<<endl;
			cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
		}
			
	}
}
void clearScreen()
{
	system("CLS");
}
int main()
{
	showGameMenu ();
}