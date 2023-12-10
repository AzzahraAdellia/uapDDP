#include <iostream>
#include <curses.h>
#include <windows.h>
#include <string.h>
#include <cstdlib> 
using namespace std;

void printPapan(char papan[3][3]);
void makeMove(char (&papan)[3][3], char move);
bool checkWin (char papan[3][3], char player);
void clearPapan(char (&papan)[3][3]);
bool full(char board[3][3]);
void loading();
void jedagjedug();
void enter();
void lanjut();
void terminalclear();

int main (){
  //lanjut();
  loading();
  enter();
  //jedagjedug();
  
  char papan[3][3];
  bool playing = true;
  bool game = true;
  int xwins = 0;
  int owins = 0;
  char ans[2], a;
  
  while(playing){
    clearPapan(papan);
    printPapan(papan);
    while(game){
      makeMove(papan,'X');
      printPapan(papan);
      if(checkWin(papan, 'X')){
	initscr();
		for(int a=1; a<30; a++){
			mvprintw(13,55,"SELAMAT! X MENANG!");
			refresh();
			Sleep(30);
			//terminalclear();	
			refresh();
			Sleep(30);
		}
	endwin();
	enter();
	clear();
	xwins++;
	break;
      }
      if(full(papan)){
	cout << "Seri!" << endl;
	break;
      }
      
      makeMove(papan,'O');
      printPapan(papan);
      if(checkWin(papan, 'O')){
	  initscr();
		for(int a=1; a<30; a++){
			mvprintw(13,55,"SELAMAT! O MENANG!");
			refresh();
			Sleep(30);
			//
			terminalclear();	
			refresh();
			Sleep(30);
		}
	  endwin();
	  enter();
	  clear();
	  owins++;
	  break;
	}
      if(full(papan)){
	cout << "Seri!" << endl;
	break;
      }
      }
    
    cout << "X menang " << xwins << " kali and O menang " << owins << " kali. apakah kamu ingin bermain lagi? ketik ya atau tidak" << endl;
    cin >> ans;
    
    if(ans[0] == 'n' || ans[0] == 'N'){
      playing = false;
    }
  }
  return 0;

}

bool full(char papan[3][3]){
  for(int a = 0; a < 3; a ++){
    for(int b = 0; b < 3; b++){
      if(papan[a][b] == ' '){
	return false;
      }
    }
  }
  return true;
}

void clearPapan(char (&papan)[3][3]){
  papan[0][0] = ' ';
  papan[1][0] = ' ';
  papan[2][0] = ' ';
  papan[0][1] = ' ';
  papan[1][1] = ' ';
  papan[2][1] = ' ';
  papan[0][2] = ' ';
  papan[1][2] = ' ';
  papan[2][2] = ' ';
}

  bool checkWin (char papan[3][3], char player){ 
  int count = 0;
  for(int a = 0; a < 3 ; a++){
    count = 0;
    for(int b = 0; b < 3; b++){
      if(papan[a][b] == player){
	count++;
      }
    }
    if(count==3){
      return true;
    }
  }
  
  for(int a = 0; a < 3 ; a++){
    count = 0;
    for(int b = 0; b < 3; b++){
      if(papan[b][a] == player){
	count++;
      }
    }
    if(count==3){
      return true;
    }
  }
  
  if(papan[0][0] == player){
    if(papan[1][1] == player){
      if(papan[2][2] ==  player){
	return true;
      }
    }
  }
  
  if(papan[2][0] == player){
    if(papan[1][1] == player){
      if(papan[0][2] ==  player){
	return true;
      }
    }
  }
  return false;
}

void makeMove (char (&papan)[3][3], char move){

  char input[2];
  cout << "input angka lalu huruf" << endl;
  cin >> input;
  
  int huruf = input[1]-64;
  int num = input[0]-48;
  int x;
  int y;

  if(huruf == 1 || huruf == 33){
    y = 0;
  }
  else if(huruf == 2 || huruf == 34){
    y = 1;
  }
  else if(huruf == 3 || huruf == 35){
    y = 2;
  }
  else{
    cout << "sorry, anda menginput huruf yang salah " << endl;
    makeMove(papan, move);
    return;
  }
  
  if(num > 3 || num < 1){
    cout << "sorry, anda menginput angka yang salah " << endl;
    makeMove(papan, move);
    return;
  }
  
  x = num-1;
  if(papan[x][y] == ' '){
    papan[x][y] = move;
  }
  else{
    cout << "sorry, ruang penuh" << endl;
    makeMove(papan, move);
    return;
  }
  
}

void printPapan(char papan[3][3]){

  cout << "  1 2 3" << endl;
  cout << "a "<<papan[0][0]<<" "<<papan[1][0]<<" "<<papan[2][0] << endl;
  cout << "b "<<papan[0][1]<<" "<<papan[1][1]<<" "<<papan[2][1] << endl;
  cout << "c "<<papan[0][2]<<" "<<papan[1][2]<<" "<<papan[2][2] << endl;
}

void loading(){
	system("color B");
	initscr();
		for(int y=0; y<3; y++){
		mvprintw(2,55, "WELCOME BACK");
		mvprintw(15,55, "Loading...");
		mvprintw(17,50, "--------------------");
		mvprintw(18,50, "|                  |");
		mvprintw(19,50, "--------------------");
		for(int f=1; f<17; f++){
			mvprintw(18, 50+f,"<3");
			refresh();
			Sleep(30);
			
		} for(int a=1; a<2; a++){
			mvprintw(21,55+a,"HAVE FUN!");
			refresh();
			Sleep(50);
		}
	}
	endwin();
}
	
void jedagjedug(){
	initscr();
		for(int a=1; a<100; a++){
			mvprintw(13,55,"SELAMAT! X MENANG!");
			//mvprintw(13,1,"¦¦¦¦¦¦¦+¦¦¦¦¦¦¦+¦¦+      ¦¦¦¦¦+ ¦¦¦+   ¦¦¦+ ¦¦¦¦¦+ ¦¦¦¦¦¦¦¦+    ¦¦+  ¦¦+    ¦¦¦+   ¦¦¦+¦¦¦¦¦¦¦+¦¦¦+   ¦¦+ ¦¦¦¦¦+ ¦¦¦+   ¦¦+ ¦¦¦¦¦¦+ ¦¦+");
			//mvprintw(13,1,"¦¦+----+¦¦+----+¦¦¦     ¦¦+--¦¦+¦¦¦¦+ ¦¦¦¦¦¦¦+--¦¦++--¦¦+--+    +¦¦+¦¦++    ¦¦¦¦+ ¦¦¦¦¦¦¦+----+¦¦¦¦+  ¦¦¦¦¦+--¦¦+¦¦¦¦+  ¦¦¦¦¦+----+ ¦¦¦");
			//mvprintw(13,1,"¦¦¦¦¦¦¦+¦¦¦¦¦+  ¦¦¦     ¦¦¦¦¦¦¦¦¦¦+¦¦¦¦+¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦        +¦¦¦++     ¦¦+¦¦¦¦+¦¦¦¦¦¦¦¦+  ¦¦+¦¦+ ¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦+ ¦¦¦¦¦¦  ¦¦¦+¦¦¦");
			//mvprintw(13,1,"+----¦¦¦¦¦+--+  ¦¦¦     ¦¦+--¦¦¦¦¦¦+¦¦++¦¦¦¦¦+--¦¦¦   ¦¦¦        ¦¦+¦¦+     ¦¦¦+¦¦++¦¦¦¦¦+--+  ¦¦¦+¦¦+¦¦¦¦¦+--¦¦¦¦¦¦+¦¦+¦¦¦¦¦¦   ¦¦¦+-+");
			//mvprintw(13,1,"¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦¦¦¦¦¦+¦¦¦  ¦¦¦¦¦¦ +-+ ¦¦¦¦¦¦  ¦¦¦   ¦¦¦       ¦¦++ ¦¦+    ¦¦¦ +-+ ¦¦¦¦¦¦¦¦¦¦+¦¦¦ +¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦ +¦¦¦¦¦+¦¦¦¦¦¦++¦¦+");
			//mvprintw(13,1,"+------++------++------++-+  +-++-+     +-++-+  +-+   +-+       +-+  +-+    +-+     +-++------++-+  +---++-+  +-++-+  +---+ +-----+ +-+");                                                                                                                       
			refresh();
			Sleep(30);
			clear();	
			refresh();
			Sleep(30);
		}
	endwin();
}

void enter(){
	initscr();
	clear();
	mvprintw(13,48,"PRESS ANY KEY TO CONTINUE");
	getch();
	endwin();
}

void lanjut(){
	initscr();
	clear();
	mvprintw(13,50,"test");
	int ans = 0;
	while(ans!=1||ans!=2){
		ans = getch();
		if(ans==1){
			break;
		}
	}
	endwin();
}

void terminalclear(){
	system("clear");
}
