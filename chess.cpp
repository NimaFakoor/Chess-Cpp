#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>

using namespace std;

string st[100];
string error[5];

struct coor{
	int r,c;
};

class chess{
public:
	chess();
	void board();
	void Admin();
		void read();
		bool check_value();
			bool Check_coordinate();
			char find_color();
			bool ok_move(coor,coor);
				bool knight(coor,coor);
				bool rock(coor,coor);
				bool bishop (coor , coor);
				bool king(coor,coor);
				bool queen(coor ,coor);
				bool pawn(coor , coor);
			bool ischeck(char nb[9][9],char );
			coor find_king(char nb[9][9],char);
			bool no_problem();
			void make_new_board(char nb[9][9]);

	void Swap();
	bool ismate(char );
		bool find_in_board(char);
		bool stop_check(coor ,char );
		void change(char b[9][9],char c[9][9]);
private:
	char b[9][9];
	coor Start,End;
	enum player_statuse
	{
		Black_player,white_player
	};
	player_statuse player;

};

int main()
{
	system("color 0a");
	chess c;
		c.Admin();
		return 0;
}
chess::chess(){
	player=white_player;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;++j)
			b[i][j]=' ';
	b[1][1]=b[1][8]='R';
	b[8][1]=b[8][8]='r';
	b[1][2]=b[1][7]='N';
	b[8][2]=b[8][7]='n';
	b[1][3]=b[1][6]='B';
	b[8][3]=b[8][6]='b';
	b[1][4]='Q';
	b[8][4]='q';
	b[1][5]='K';
	b[8][5]='k';
	b[2][1]=b[2][2]=b[2][3]=b[2][4]=b[2][5]=b[2][6]=b[2][7]=b[2][8]='P';
	b[7][1]=b[7][2]=b[7][3]=b[7][4]=b[7][5]=b[7][6]=b[7][7]=b[7][8]='p';
	}//constructure
void chess::board()
{
	for(int i=0;i<100;++i)
		st[i].clear();
	st[0]+=char(218);//┌
	for(int i=0;i<7;i++)
	{
		st[0]+=char(196);	st[0]+=char(196);st[0]+=char(196);//─
		st[0]+=char(194);//┬
	}
		st[0]+=char(196);	st[0]+=char(196);st[0]+=char(196);//─
		st[0]+=char(191);//┐
		st[1]+=char(179);//│
		for(int i=1;i<=8;i++)
		{
		st[1]+=' ';st[1]+=b[1][i];st[1]+=' ';//space
		st[1]+=char(179);//│
		}
		st[2]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[2]+=char(196);	st[2]+=char(196);	st[2]+=char(196);//─
		st[2]+=char(197);//┼
		}
			st[2]+=char(196);	st[2]+=char(196);	st[2]+=char(196);//─
		st[2]+=char(180);//┤
		st[3]+=char(179);//│
		for(int j=1;j<=8;j++)
		{
			st[3]+=' ';st[3]+=b[2][j];st[3]+=' ';//space
		st[3]+=char(179);//│

		}
		st[4]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[4]+=char(196);	st[4]+=char(196);	st[4]+=char(196);//─
		st[4]+=char(197);//┼
		}
		st[4]+=char(196);	st[4]+=char(196);	st[4]+=char(196);//─
		st[4]+=char(180);//┤
		st[5]+=char(179);//│;
		for(int j=1;j<=8;j++)
		{
		st[5]+=' ';st[5]+=b[3][j];st[5]+=' ';//space
		st[5]+=char(179);//│
		}
		st[6]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[6]+=char(196);	st[6]+=char(196);	st[6]+=char(196);//─
		st[6]+=char(197);//┼
		}
		st[6]+=char(196);	st[6]+=char(196);	st[6]+=char(196);//─
		st[6]+=char(180);//┤
		st[7]+=char(179);//│;
		for(int j=1;j<=8;j++)
		{
		st[7]+=' ';st[7]+=b[4][j];st[7]+=' ';//space
		st[7]+=char(179);//│
		}
		st[8]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[8]+=char(196);	st[8]+=char(196);	st[8]+=char(196);//─
		st[8]+=char(197);//┼
		}
		st[8]+=char(196);	st[8]+=char(196);	st[8]+=char(196);//─
		st[8]+=char(180);//┤
		st[9]+=char(179);//│;
		for(int j=1;j<=8;j++)
		{
		st[9]+=' ';st[9]+=b[5][j];st[9]+=' ';//space
		st[9]+=char(179);//│
		}
		st[10]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[10]+=char(196);	st[10]+=char(196);	st[10]+=char(196);//─
		st[10]+=char(197);//┼
		}
		st[10]+=char(196);	st[10]+=char(196);	st[10]+=char(196);//─
		st[10]+=char(180);//┤
		st[11]+=char(179);//│;
		for(int j=1;j<=8;j++)
		{
		st[11]+=' ';st[11]+=b[6][j];st[11]+=' ';//space
		st[11]+=char(179);//│
		}
		st[12]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[12]+=char(196);	st[12]+=char(196);	st[12]+=char(196);//─
		st[12]+=char(197);//┼
		}
		st[12]+=char(196);	st[12]+=char(196);	st[12]+=char(196);//─
		st[12]+=char(180);//┤
		st[13]+=char(179);//│;
		for(int j=1;j<=8;j++)
		{
		st[13]+=' ';st[13]+=b[7][j];st[13]+=' ';//space
		st[13]+=char(179);//│
		}
		st[14]+=char(195);//├
		for(int i=0;i<7;i++)
		{
		st[14]+=char(196);	st[14]+=char(196);	st[14]+=char(196);//─
		st[14]+=char(197);//┼
		}
		st[14]+=char(196);	st[14]+=char(196);	st[14]+=char(196);//─
		st[14]+=char(180);//┤
		st[15]+=char(179);//│;
		for(int j=1;j<=8;j++)
		{
		st[15]+=' ';st[15]+=b[8][j];st[15]+=' ';//space
		st[15]+=char(179);//│
		}
		st[16]+=char(192);//└
		for(int i=0;i<7;i++)
		{
		st[16]+=char(196);	st[16]+=char(196);	st[16]+=char(196);//─
		st[16]+=char(193);//┴
		}
		st[16]+=char(196);	st[16]+=char(196);	st[16]+=char(196);//─
		st[16]+=char(217);//┘
		cout<<endl<<endl;
		cout<<"\t"<<"\t"<<"    "<<"    ";
	for(char ch='a';ch<='h';++ch)
		cout<<ch<<"   ";
	cout<<endl;
	int cnt1=1;
	
	for(int i=0;i<17;++i)
	{
		cout<<"\t "<<"\t"<<"    ";
		if(i%2 == 1)
			cout<<cnt1++;
		else
			cout<<" ";
		cout<<" "<<st[i]<<endl;
	}
	cout<<"\t"<<"\t"<<"    "<<"    ";
	for(char ch='a';ch<='h';++ch)
		cout<<ch<<"   ";
	cout<<endl;
}

void chess::read()
{
	if(player==1)
	cout<<"white player->";
	else
		cout<<"black player->";
	char ch;
	cin>>ch;
	if(ch>='a' && ch<='z')
		ch-=32;
	ch-='A'-1;
	Start.c=ch;
	int a;
	cin>>a;
	Start.r=a;
	cin>>ch;
	if(ch>='a' && ch<='z')
		ch-=32;
	ch-='A'-1;
	End.c=ch;
	cin>>a;
	End.r=a;
}//satr o soton ro mikhone

void chess::Swap()
{
	b[End.r][End.c]=b[Start.r][Start.c];
	b[Start.r][Start.c]=' ';
	if(player==white_player)
		player=Black_player;
	else
		player=white_player;//baraye tavize player
}//age ok bood harkat ro anjam bede
void chess ::Admin()
{
	error[1]="try again please";
	error[2]="dude what are you doing?";
	error[3]="sorry invalide move";
	srand(time(0));
	board();
	while(1 )//check mate mal vaghT hask bazi tamome 
	{
		read();
		if( check_value())
		{
			Swap();
		}
		else
		{
			cout<<endl;
			int i;
			i=1+rand()%3;
			cout<<"\t\t\t     "<<error[i]<<endl<<endl;
			continue;
		}
		board();
		string turn=(player==white_player ? "White Player" : "Black Player");
		if( ismate(turn[0]+32 ) )
		{
			system("cls");
			system("color 0a");
			int t=80;
			while(t--)
				cout<<'*';
			Beep(500,500);
			cout<<"\n\t\t\t\t"<<turn<<" Lose.\n";
			Beep(500,200);
			t=80;
			while(t--)
				cout<<'*';
				Beep(500,500);
			break;
			
		}
	}
}

char chess::find_color()
{
	if('A'<=b[Start.r][Start.c] && b[Start.r][Start.c]<='Z')
		return 'W';
	if('a'<=b[Start.r][Start.c] && b[Start.r][Start.c]<='z')
		return 'B';
	else 
		return 'F';

}//range khone start ro moshakhas mikone
bool chess::Check_coordinate()
{
	int sr=Start.r,sc=Start.c;
	int er=End.r,ec=End.c;
	if( sr>8 || sr<1 || sc>8 || sc<1 || ec>8 || ec<1 || er<1 || er>8 )
		return false;
	return true;
}//barasi mikone mokhtasat az safe biroon nazane

bool chess::check_value()
{
	if(Check_coordinate()==0)
		return false;
	if(player==white_player)
	{
		if(find_color()!='W')
			return false;
		if(b[End.r][End.c]>='A' && b[End.r][End.c]<='Z' )
			return false;
	
	}
	else
	{
		if(find_color()!='B')
			return false;
		if(b[End.r][End.c]>='a' && b[End.r][End.c]<='z' )
			return false;
		
	}
	if(!ok_move(Start,End))
		return false;
	if(!no_problem())
		return false;
	return true;

}//mibine harekat motabare ya na
bool chess::ok_move(coor S,coor E)
{
	char ch;
	ch=b[S.r][S.c];
	if(ch>='a' && ch<='z')
		ch-=32;
	switch (ch)
	{
	case 'N':
		if(!knight(S,E))
			return false;
		return true;
		break;
	case 'R':
		if(!rock(S,E))
			return false;
		return true;
		break;
	case 'B':
		if(!bishop(S,E))
			return false;
		return true;
		break;
	case 'K':
		if(!king(S,E))
			return false;
		return true;
		break;
	case 'Q':
		if(!queen(S,E))
			return false;
		return true;
		break;
	case 'P':
		if(!pawn(S,E))
			return false;
		return true;
		break;
	}
	
}//barasi mikone bbine harekate mohreha doroste ya na

bool chess::knight(coor S,coor E)
{
	int dx[]={-2,-2,-1,-1,1,1,2,2};
	int dy[]={-1,1,2,-2,-2,2,-1,1};
	for(int i=0;i<8;i++)
	{
		if(S.r-E.r==dx[i] && S.c-E.c==dy[i])
			return true;

	}
	return false;
}//harekate asb 

bool chess::rock(coor S,coor E)
{
	if(S.r==E.r)
	{
		int mn=min(S.c,E.c);
		int mx=max(S.c,E.c);
		for(int i=mn+1;i<mx;i++)
			if(b[S.r][i]!=' ')
				return false;
		return true;
	}
	else if(S.c==E.c)
	{
		int mn=min(S.r,E.r);
		int mx=max(S.r,E.r);
		for(int i=mn+1;i<mx;i++)
			if(b[i][E.c]!=' ')
				return false;
		return true;
	
	}
	else
		return false;
}//harekate rock

bool chess::bishop(coor S,coor E)
{
	if(abs(S.r-E.r)==abs(S.c-E.c))
	{
		if(S.r>E.r && S.c<E.c)
		{
			for(int i=S.r-1,j=S.c+1; ;j++,i--)
			{
				if(i==E.r && j==E.c)
					return true;
				if(b[i][j]!=' ')
					return false;
			}
		}
		else if(S.r>E.r &&S.c>E.c )
		{
			for(int i=S.r-1,j=S.c-1; ;j--,i--)
			{
				if(i==E.r && j==E.c)
					return true;
				if(b[i][j]!=' ')
					return false;
			}
		}
		else if(S.r<E.r && S.c>E.c)
		{
			for(int i=S.r+1,j=S.c-1; ;j--,i++)
			{
				if(i==E.r && j==E.c)
					return true;
				if(b[i][j]!=' ')
					return false;
			}
		}
		else 
		{
			for(int i=S.r+1,j=S.c+1; ;++j,++i)
			{
				if(i==E.r && j==E.c)
					return true;
				if(b[i][j]!=' ')
					return false;
			}
		}
		return false;

	}
	return false;
	
}//harekate fil

bool chess::king(coor S,coor E)
{
	int dx[]={-1,0,1,0,-1,-1,1,1};
	int dy[]={0,-1,0,1,-1,1,-1,1};
	for(int i=0;i<8;i++)
	{
		if(S.r-E.r==dx[i] && S.c-E.c==dy[i])
			return true;
	}
	return false;
}//harekate shah

bool chess::queen(coor S,coor E)
{
	if( bishop(S,E) || rock(S,E) )
		return true;
	return false;
}//harekate vazir
bool chess::pawn(coor S,coor E)
{
	int dr=E.r-S.r;
	int dc=E.c-S.c;
	if( ( dr<0 && player==white_player) || (dr>0 && player==Black_player) ) 
		return false;
	if(dr==2)
	{
		if(S.r==2 && dc==0 && b[E.r][E.c]==' ' && b[E.r-1][E.c]==' ')
			return true;
		return false;
	}
	else if(dr==-2)
	{
		if(S.r==7 && dc==0 && b[E.r][E.c]==' ' && b[E.r+1][E.c]==' ')
	    	return true;
		return false;
	}
	else if(dr==1)
	{
		if(dc==0)
		{
			if(b[E.r][E.c]==' ')
				return true;
			return false;
		}
		else if(abs(dc)==1)
		{
			if(b[E.r][E.c]!=' ')
				return true;
			return false;
		}
		else 
			return false;
		

	}
	else if(dr==-1)
	{
		if(dc==0)
		{
			if(b[E.r][E.c]==' ')
				return true;
			return false;
		}
		else if(abs(dc)==1)
		{
			if(b[E.r][E.c]!=' ')
				return true;
			return false;
		}
		else
			return false;
		
	}
	else
		return false;
}//harekate sarbaaz

bool chess ::no_problem()
{
	char nb[9][9],color='w';
	for(int i=1;i<9;++i)
		for(int j=1;j<9;++j)
			nb[i][j]=b[i][j];
	b[End.r][End.c]=b[Start.r][Start.c];
	b[Start.r][Start.c]=' ';
	if(player==Black_player)
		color='b';
	if(ischeck(b,color))
	{
		make_new_board(nb);
		return false;
	}
	make_new_board(nb);
	return true;
}

bool chess ::ischeck(char nb[9][9],char color)
{
	coor King=find_king(nb,color);
	for(int i=1;i<9;++i)
		for(int j=1;j<9;++j)
		{
			if(nb[i][j]==' ')
				continue;
			if(color=='w')
			{
				if(nb[i][j]>='a'&& nb[i][j]<='z')
				{
					coor Sorce;
					Sorce.r=i;
					Sorce.c=j;
					if(ok_move(Sorce,King))
						return true;
				}
			}

			else
			{
				if(nb[i][j]>='A'&& nb[i][j]<='Z')
				{
					coor Sorce;
					Sorce.r=i;
					Sorce.c=j;
					if(ok_move(Sorce,King))
						return true;
				}				
			}
		}
		return false;
}

coor chess ::find_king(char nb[9][9],char color)
{
	char mark='k';
	if(color=='w')
		mark='K';
	coor King;
	for(int i=1;i<9;++i)
		for(int j=1;j<9;++j)
			if(nb[i][j]==mark)
				King.r=i,King.c=j;
	return King;
}

void chess ::make_new_board(char nb[9][9])
{
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			b[i][j]=nb[i][j];
}

void  chess ::change(char a[9][9],char c[9][9])
{
	for(int i=1;i<9;++i)
		for(int j=1;j<9;++j)
			a[i][j]=c[i][j];
}

bool chess::ismate(char color)
{
	if( !ischeck(b,color) )
		return false;
	char high='a',low='z';
	if(color=='w')
		high-=32,low-=32;
	coor S;
	for(int i=1;i<9;++i)
		for(int j=1;j<9;++j)
		{
			S.r=i;
			S.c=j;
			if(b[i][j]>=low && b[i][j]<=high)
				if(stop_check(S,color))
					return false;
		}
	return true;
	
}

bool chess::stop_check(coor S,char color)
{
	char save_board[9][9],new_board[9][9];
	change(save_board,b);
	for(int i=1;i<9;++i)
	{
		for(int j=1;j<9;++j)
		{
			coor E;
			E.r=i;
			E.c=j;
			if( !ok_move(S,E) )
			 continue;
			change(new_board,b);
			b[i][j]=b[S.r][S.c];
			b[S.r][S.c]=' ';
			if( ischeck(b,color) )
			{
				change(b,new_board);
				continue;
			}
			change(b,new_board);
			return true;
		}
	}
	return false;
}
