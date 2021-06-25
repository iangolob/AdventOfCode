#include <bits/stdc++.h>
using namespace std;

//input 323*31
//test input 11*11
#define IN_I 323
#define IN_J 31
#define POMAK_I 1
#define POMAK_J 3

int main(void){
	char a[IN_I][IN_J];
	
	for(int i=0;i<IN_I;i++){
		for(int j=0;j<IN_J;j++){
			cin>>a[i][j];			
		}
	}
	int rj1=0;
	int poz_i=0,poz_j=0;
	while(poz_i<IN_I){
		poz_i=poz_i+POMAK_I;	
		poz_j=(poz_j+POMAK_J)%IN_J;
		if(a[poz_i][poz_j]=='#'){
			rj1++;
		}
		//cout<<poz_i<<endl;
	}
	cout<<"RJ1: "<<rj1<<endl;
	
	
	long long rj2;
	int pom_i[5]={1,1,1,1,2},pom_j[5]={1,3,5,7,1};
	int br;
	for(int x=0;x<5;x++){
		br=0;
		poz_i=0;
		poz_j=0;
		while(poz_i<IN_I){
			poz_i=poz_i+pom_i[x];	
			poz_j=(poz_j+pom_j[x])%IN_J;
			if(a[poz_i][poz_j]=='#'){
				br++;
			}
			//cout<<poz_i<<endl;
		}
		if(x==0){
			rj2=br;
		}else{
			rj2*=br;
		}
		cout<<br<<endl;
	}	
	cout<<"RJ2: "<<rj2<<endl;
	
	return 0;
	
}
