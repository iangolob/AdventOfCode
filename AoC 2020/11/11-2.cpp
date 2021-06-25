#include <bits/stdc++.h>
#define A_M 97
#define A_N 98
using namespace std;
//97*98 input 10*10 test

char a[A_M][A_N]={0},b[A_M][A_N];
struct tocka_s{
	int m;
	int n;
};
struct tocka_s around[8]={0,-1,0,1,1,1,1,-1,1,0,-1,0,-1,1,-1,-1};


int aroundNum(int i, int j){
	int rez=0,count=1;
	for(int x=0;x<8;x++){
		count=0;
		do{
			count++;
			if(around[x].m*count+i>=0 and around[x].m*count+i<A_M and around[x].n*count+j>=0 and around[x].n*count+j<A_N){
				if(a[around[x].m*count+i][around[x].n*count+j]=='#'){
					rez++;
					break;
				}else{
					if(a[around[x].m*count+i][around[x].n*count+j]=='L'){
						break;
					}	
				}	
			}
		}while(around[x].m*count+i>=0 and around[x].m*count+i<A_M and around[x].n*count+j>=0 and around[x].n*count+j<A_N);
	}
//	cout<<"r "<<rez<<endl;
	return rez;
}

void gen_b(){
	for(int i=0;i<A_M;i++){
		for(int j=0;j<A_N;j++){
			if(a[i][j]=='#' or a[i][j]=='L'){
				switch(aroundNum(i,j)){
					case 0:
						b[i][j]='#';
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						b[i][j]='L';
						break;
					default:
						b[i][j]=a[i][j];
				}	
			}else{
				b[i][j]='.';
			}		
		}
	}
	return;
}

void b_to_a(){
	for(int i=0;i<A_M;i++){
		for(int j=0;j<A_N;j++){
			a[i][j]=b[i][j];
		}
	}
}



int main(void){
	for(int i=0;i<A_M;i++){
		for(int j=0;j<A_N;j++){
			cin>>a[i][j];
		}
	}
	int rj1=0,prosli;
	do{				
		prosli=rj1;	
		gen_b();
		b_to_a();
		
		rj1=0;
		for(int i=0;i<A_M;i++){
			for(int j=0;j<A_N;j++){
				if(a[i][j]=='#'){
					rj1++;
				}
			}
		}
		for(int i=0;i<A_M;i++){
			for(int j=0;j<A_N;j++){
	//			cout<<a[i][j];
			}
	//		cout<<endl;
		}
	//	cout<<endl;
		cout<<rj1<<endl;
	}while(rj1!=prosli);
	
	
	
	return 0;
}
