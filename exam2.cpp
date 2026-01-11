#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int menu(){ // s = menu()
	int s;
	cout << "	Menu for Simulation" << endl;
	cout << "1. Game 1" << endl;
	cout << "2. Game 2" << endl;
	cout << "3. Show Result" << endl;
	cout << "0. Exit" << endl;
	cout << "   Please Select one" << endl;
	cin >> s;
	return s;
}

int game1(){ //a_d = game1()
	int a_d;
	int d = rand()%6 + 1;
	int d_c = rand()%6 + 1;
	cout << "玩家點數: " << d << endl;
	cout << "電腦點數: " << d_c << endl;
	if(d > d_c){
		cout << "玩家獲勝!" << endl; 
		a_d = 2;
	} 
	else if(d < d_c){
		cout << "電腦獲勝!" << endl; 
		a_d = 1;
	}
	else{
		cout << "玩家與電腦平手!" << endl; 
		a_d = 0;
	}
	return a_d;
}

int game2(){
	int x;
	int m[52] = {0};
	do{
		x = rand()%52; 
	}while(m[x]);
	m[x] = 1;
	int y = x/13 + 1;
	int z = x% 13 + 1;
	
	switch(y){
		case 4:
			cout << "玩家抽到黑桃" << z << endl;
			break;
		case 3:
			cout << "玩家抽到紅心" << z << endl;
			break;
		case 2:
			cout << "玩家抽到方塊" << z << endl;
			break;
		case 1:
			cout << "玩家抽到梅花" << z << endl;
			break;
	}
	
	do{
		x = rand()%52; 
	}while(m[x]);
	m[x] = 1;
	int y_c = x/13 + 1;
	int z_c = x% 13 + 1;
	
		switch(y_c){
		case 4:
			cout << "電腦抽到黑桃" << z_c << endl;
			break;
		case 3:
			cout << "電腦抽到紅心" << z_c << endl;
			break;
		case 2:
			cout << "電腦抽到方塊" << z_c << endl;
			break;
		case 1:
			cout << "電腦抽到梅花" << z_c << endl;
			break;
	}
	
	int a_c;
	if(z > z_c){
		cout << "玩家獲勝!" << endl;
		a_c = 2; 
	}
	else if(z < z_c){
		cout << "電腦獲勝!" << endl;
		a_c = 1;
	}
	else{
		if(y > y_c){
			cout << "玩家獲勝!" << endl;
			a_c = 2; 
		}
		else{
			cout << "電腦獲勝!" << endl;
			a_c = 1;
		}
	}
	return a_c;
}

void Show(int a, int b, int c){
	
	if(a==0&&b==0&&c==0){
		cout << "電腦贏 " << 0 << " 次，遊戲者贏 " << 0 << " 次，平手 " << 0 << " 次。遊戲者勝率為 " << 0 << "%" << endl; 
	}
	else{
		float p = 100*b/(a+b+c); 
		cout << "電腦贏 " << a << " 次，遊戲者贏 " << b << " 次，平手 " << c << " 次。遊戲者勝率為 " << p << "%" << endl; 	
	}
}
	


int main(){
	int a = 0;
	int b = 0; 
	int c = 0;
	int a_d, a_c;
	srand(time(NULL));
	int q = 0;
	while(q != 1){
		int s;
		s = menu();
		switch(s){
			case 1:
				cout << endl << "Game 1 執行中" << endl << endl;
				a_d = game1();  
				cout << "-------------------------------------" << endl << endl;
				switch(a_d){
					case 1:
						a += 1;
						break;
					case 2:
						b += 1;
						break;
					case 0:
						c += 1;
						break;
				}
				break;
			case 2:
				cout << endl << "Game 2 執行中" << endl << endl;
				a_c = game2();
				cout << "-------------------------------------" << endl << endl;
				switch(a_c){
					case 1:
						a += 1;
						break;
					case 2:
						b += 1;
						break;
				}
				break;
			case 3:
				cout << endl << "Show Result 執行中" << endl << endl; 
				Show(a,b,c);
				cout << "-------------------------------------" << endl << endl;
				break;
			case 0:
				cout << endl << "Exit" << endl;
				q = 1;
				break;
			default:
				cout << endl << "輸入錯誤" << endl;
				cout << "-------------------------------------" << endl << endl;
				break; 
		}
	}
} 
