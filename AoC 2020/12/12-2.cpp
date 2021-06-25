#include <bits/stdc++.h>
using namespace std;




int x=0,y=0,wx=10,wy=1;
char dir='E';


void rotR(int n){
	int temp;
	for(int i=0;i<n/90;i++){
		temp=wx;
		wx=wy;
		wy=-temp;
	}
	return;
}

void rotL(int n){
	int temp;
	for(int i=0;i<n/90;i++){
		temp=wx;
		wx=-wy;
		wy=temp;
	}
	return;
}





void move(char c, int n){
	switch(c){
		case 'N':
			wy+=n;
			break;
		case 'S':
			wy-=n;
			break;
		case 'E':
			wx+=n;
			break;
		case 'W':
			wx-=n;
			break;
		case 'F':
			x+=wx*n;
			y+=wy*n;
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
