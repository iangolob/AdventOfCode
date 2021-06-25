#include <bits/stdc++.h>
#define GRID_SIZE 1000
using namespace std;

struct hex_s{
	char color='W';
	bool been_here=0;
}hex_grid[GRID_SIZE][GRID_SIZE],hex_grid_next[GRID_SIZE][GRID_SIZE];
int m=GRID_SIZE/2,n=GRID_SIZE/2;


void reset_move(void){
	m=GRID_SIZE/2;
	n=GRID_SIZE/2;
	return;
}

int num_of_black(void){
	int rez=0;
	for(int i=0;i<GRID_SIZE;i++){
		for(int j=0;j<GRID_SIZE;j++){
			if(hex_grid[i][j].color=='B'){
				rez++;
			}
		}
	}
	return rez;
}


void move(int dir){
	switch (dir){
		case 0:		//NW
			m--;
			n--;
			break;
		case 1:		//NE
			m--;
			break;
		case 2:		//E
			n++;
			break;
		case 3:		//SE
			m++;
			n++;
			break;
		case 4:		//SW
			m++;
			break;
		case 5:		//W
			n--;
			break;
	}
	return;
}


void turn(void){
	int adjacent=0;
	for(int i=1;i<GRID_SIZE-1;i++){
		for(int j=1;j<GRID_SIZE-1;j++){
			adjacent=0;
			if(hex_grid[i-1][j-1].color=='B') adjacent++;
			if(hex_grid[i-1][j].color=='B') adjacent++;
			if(hex_grid[i][j+1].color=='B') adjacent++;
			if(hex_grid[i+1][j+1].color=='B') adjacent++;
			if(hex_grid[i+1][j].color=='B') adjacent++;
			if(hex_grid[i][j-1].color=='B') adjacent++;
			if(hex_grid[i][j].color=='W'){
				if(adjacent==2){
					hex_grid_next[i][j].color='B';
				}else{
					hex_grid_next[i][j].color='W';
				}
			}else{
				if(adjacent==0 or adjacent>2){
					hex_grid_next[i][j].color='W';
				}else{
					hex_grid_next[i][j].color='B';
				}
			}
		}
	}
	for(int i=1;i<GRID_SIZE-1;i++){
		for(int j=1;j<GRID_SIZE-1;j++){
			hex_grid[i][j].color=hex_grid_next[i][j].color;
		}
	}
	return;
}



void flip_current(void){
	if(hex_grid[m][n].color=='W'){
		hex_grid[m][n].color='B';
	}else{
		hex_grid[m][n].color='W';
	}
	hex_grid[m][n].been_here=1;
	return;
}


int main(void){
	string s;
	hex_grid[GRID_SIZE/2][GRID_SIZE/2].color='W';
	hex_grid[GRID_SIZE/2][GRID_SIZE/2].been_here=1;
	
	while(getline(cin,s),s!=""){
		int poz=0;
		int direction;
		reset_move();
		while(poz<s.size()){
			switch (s[poz]){
				case 'n':
					if(s[poz+1]=='w'){
						direction=0;
					}else{
						direction=1;
					}
					poz+=2;
					break;
				case 's':
					if(s[poz+1]=='e'){
						direction=3;
					}else{
						direction=4;
					}
					poz+=2;
					break;
				case 'w':
					direction=5;
					poz++;
					break;
				case 'e':
					direction=2;
					poz++;
					break;	
			}
			move(direction);	
		}
		flip_current();
	}
	
	cout<<"RJ1: "<<num_of_black()<<endl;
	
	
	for(int i=0;i<100;i++){
		turn();
	}
	
	cout<<"RJ2: "<<num_of_black()<<endl;	
	
	
	return 0;
}
