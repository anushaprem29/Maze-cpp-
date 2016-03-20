/*
	Programmer       - C P ANUSHA
	Name             - MINESWEEPER
	Language         - C++
	ON  -november of 2014

*/
#include<iostream.h>
#include<conio.h>
int a[9][9],b[9][9];
//instruction to the game
void instruction(){
	cout<<"\n\n\n\t\t\t\tMAZE!!\n\n\n\t\t\t\t\t\t\tBY ANUSHA PREM";
	cout<<"\n\n\n  \t\t MAKE snake OOOOOjO  reach its /\\/\\/\\ house\n";
	cout<<"\n\t_________________________\n\t|\tPress\t\t|\n\t|\tUP:\tw\t|\n\t|\tDOWN:\ts\t|\n\t|\tLEFT:\td\t|\n\t|\tRIGHT:\ta\t|\n\t|_______________________|";
	cout<<endl;
	getch();
}
void display(int x){
	clrscr();
	int c=x/10,d=x%10,t;
	for(int i=0;i<18;i++){
		for(int j=0;j<9;j++){ 	t=a[i/2][j];
			if(i%2==0){
				if(t==3||t==4||t==7||t==9||t==11||t==13||t==5)
					cout<<"       ";
				else
					cout<<"=======";
			}
			else{
				if((i/2)==c&&j==d)	cout<<"OOOOOOO";
				else if((i/2)==8&&j==8) cout<<"/\\/\\/\\/";
				else if(a[i/2][j]==1)	cout<<"|______";
				else if(a[i/2][j]==2)	cout<<"      |";
				else if(a[i/2][j]==3)     cout<<"|      ";
				else if(a[i/2][j]==4)     cout<<"______|";
				else if(a[i/2][j]==5)     cout<<"|_____|";
				else if(a[i/2][j]==6) 	cout<<"|      ";
				else if(a[i/2][j]==7) 	cout<<"|     |";
				else if(a[i/2][j]==8)  	cout<<"_______";
				else if(a[i/2][j]==9)  	cout<<"_______";
				else if(a[i/2][j]==10) 	cout<<"       ";
				else if(a[i/2][j]==11) 	cout<<"|______";
				else if(a[i/2][j]==12) 	cout<<"______|";
				else if(a[i/2][j]==13) 	cout<<"      |";
				else 			cout<<"|||||||";
			}
		  }  cout<<endl;
       }
}
//Function to Make Maze
void makemaze(){
       a[0][0]=a[4][1]=a[6][0]=1;      //right
       a[0][1]=a[1][6]=a[3][8]=a[2][3]=a[5][7]=a[1][2]=2;    //left-down
       a[1][1]=3;  //up down right
       a[3][4]=a[5][3]=a[8][3]=a[7][5]=4;//left-up
       a[1][4]=a[5][2]=a[2][5]=a[7][3]=a[5][5]=6;//right-down
       a[2][4]=a[3][5]=a[7][2]=a[6][5]=a[6][7]=a[7][7]=a[4][8]=7;  //up-down
       a[1][5]=a[4][2]=a[4][4]=a[6][1]=a[7][4]=a[5][6]=a[4][6]=8; //left-right
       a[2][6]=a[4][5]=9;   //left-right-up
       a[2][7]=a[4][3]=10; //left-right-down
       a[8][2]=a[8][7]=a[2][2]=a[3][3]=a[3][7]=11;//up right
       a[6][2]=13;     //left-up-down
       a[2][1]=a[5][8]=5; //up
       a[4][7]=a[2][8]=12;

}
void initialize(int bx[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
		 bx[i][j]=0;
	}
}
//Checks if the direction that side is possible
void movable(int x){
       int c=x/10;
       int d=x%10;
       initialize(b);
       b[c][d]=100;
       switch(a[c][d]){
		case 1: b[c][d+1]=100; break;
		case 2: b[c][d-1]=b[c+1][d]=100; break;
		case 3: b[c-1][d]=b[c+1][d]=b[c][d+1]=100; break;
		case 4: b[c][d-1]=b[c-1][d]=100; break;
		case 5: b[c-1][d]=100; break;
		case 6: b[c][d+1]=b[c+1][d]=100; break;
		case 7: b[c-1][d]=b[c+1][d]=100; break;
		case 8: b[c][d-1]=b[c][d+1]=100; break;
		case 9: b[c][d-1]=b[c][d+1]=b[c-1][d]=100; break;
		case 10:b[c][d-1]=b[c][d+1]=b[c+1][d]=100; break;
		case 11:b[c][d+1]=b[c-1][d]=100; break;
		case 12:b[c][d-1]=100; break;
		case 13:b[c][d-1]=b[c+1][d]=b[c-1][d]=100;break;
		default: cout<<"INVALID\n";
       }
}
//If the direction is possible then moves the snake toward
int move(char a,int x){
	movable(x);
	int c=x/10;
	int d=x%10;
	switch(a){
		case 'a':
			if((b[c][d]==100)&&(b[c][d-1]==100))
				return (c*10)+(d-1);
			break;
		case 's':
			if((b[c][d]==100)&&(b[c+1][d]==100))
				return ((c+1)*10)+d;
			break;
		case 'w':
			if((b[c][d]==100)&&(b[c-1][d]==100))
				return (((c-1)*10)+d);
			break;
		case 'd':
			if((b[c][d]==100)&&(b[c][d+1]==100))
				return ((c*10)+(d+1));
			break;
      }
      return x;
}

//The Main Function
void main(){
	clrscr();
	int j=0;
	char mov;
	initialize(a);
	instruction();
	makemaze();
	display(0);
	while(j!=88){
		cout<<"\n\t Enter Your Movement and q to quit\n";
		mov=getche();
		if(mov=='q')	break;
		j=move(mov,j);
		display(j);
	}
	if(mov!='q'){
			cout<<"End of the game\n\n You reached :D \n\n press 1 to play again";
			j=getche();
			if(j=='1')	main();
	}
	else 			cout<<"\n\tYou quit the game \n";
	getch();
}