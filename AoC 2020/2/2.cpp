#include <bits/stdc++.h>
using namespace std;


int numLet(char c, string s){
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==c){
			x++;
		}
	}
	return x;
}

struct l{
		int min;
		int max;
		char slovo;
		string s;
	};
int main(void){
	
	vector<l> v;
	struct l vtemp;
	
	int mint,maxt;
	char c;
	while(cin>>mint>>c>>maxt,mint!=0 or maxt!=0){
		cin>>vtemp.slovo;
		vtemp.min=mint;
		vtemp.max=maxt;
		cin>>c;
		cin>>vtemp.s;	
		v.push_back(vtemp);
	}
	//zavrsava se sa 0-0
	
	int rj1=0;
	for(int i=0;i<v.size();i++){
		if(v[i].min<=numLet(v[i].slovo,v[i].s) and v[i].max>=numLet(v[i].slovo,v[i].s)){
			rj1++;
		}
	}
	cout<<"RJ1: "<<rj1<<endl; 
	
	int rj2=0;
	for(int i=0;i<v.size();i++){
		if((v[i].s[v[i].min-1]==v[i].slovo and not (v[i].s[v[i].max-1]==v[i].slovo)) or
		 (not (v[i].s[v[i].min-1]==v[i].slovo) and v[i].s[v[i].max-1]==v[i].slovo)){
			rj2++;
		}
	}
	cout<<"RJ2: "<<rj2<<endl; 
	
	
	return 0;
}
