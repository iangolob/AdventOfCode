#include <bits/stdc++.h>
using namespace std;

int x=0,y=0;
char dir='E';


void rotR(int n){
	for(int i=0;i<n/90;i++){
		switch(dir){
			case 'N':
				dir='E';
				break;
			case 'S':
				dir='W';
				break;
			case 'E':
				dir='S';
				break;
			case 'W':
				dir='N';
				break;
		}
	}
	return;
}
void rotL(int n){
	for(int i=0;i<n/90;i++){
		switch(dir){
			case 'N':
				dir='W';
				break;
			case 'S':
				dir='E';
				break;
			case 'E':
				dir='N';
				break;
			case 'W':
				dir='S';
				break;
		}
	}
	return;
}





void move(char c, int n){
	switch(c){
		case 'N':
			y+=n;
			break;
		case 'S':
			y-=n;
			break;
		case 'E':
			x+=n;
			break;
		case 'W':
			x-=n;
			break;
		case 'F':
			move(dir,n);
			break;
		case 'L':
			rotL(n);
			break;
		case 'R':
			rotR(n);
	}
	return;
}




int main(void){
	char c;
	int inp;
	while(cin>>c,c!='0'){
		cin>>inp;
		move(c,inp);
	}
	
	cout<<"RJ1: "<<abs(x)+abs(y)<<endl;
	
	return 0;
}
