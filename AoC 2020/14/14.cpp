#include <bits/stdc++.h>
using namespace std;

struct mem_s{
	bool val[36]={0};
};
mem_s mem[100000];


string int_to_b(int x){
	string s;
	s="000000000000000000000000000000000000";
	int i=35;
	while(x>0){
		if(x%2==1){
			s[i]='1';
		}
		i--;
		x=x/2;
	}
	return s;
}

mem_s masking(string mask,string n){
	mem_s temp;
	for(int i=0;i<36;i++){
		switch(mask[i]){
			case '1':
				temp.val[35-i]=1;	
				break;
			case '0':
				temp.val[35-i]=0;
				break;
			case 'X':
				if(n[i]=='0'){
					temp.val[35-i]=0;
				}else{
					temp.val[35-i]=1;
				}	
				break;
			default:
				cout<<"error"<<endl;
				break;
		}
	}	
	return temp;
}



int main(void){
	string s,mask,num;
	char c;
	int numi,maxmem=0;
	while(cin>>s,s[0]!='0'){
		cin>>c;
		if(s[1]=='a'){
			cin>>mask;
		}	
		if(s[1]=='e'){
			cin>>numi;
			num=int_to_b(numi);
			if(stoi(s.substr(4,s.find(']')))>maxmem){
				maxmem=stoi(s.substr(4,s.find(']')));
			}
			mem[stoi(s.substr(4,s.find(']')))]=masking(mask,num);
		}		
	};
	//zavrsi input s 0

	long long rj1=0;
	for(int i=0;i<=maxmem;i++){
		for(int j=35;j>=0;j--){
			if(mem[i].val[j]==1){
				rj1+=pow(2,j);
			}
		}
	}
	cout<<"RJ1: "<<rj1<<endl;
	return 0;
}
