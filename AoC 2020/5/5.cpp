#include <bits/stdc++.h>
using namespace std;

int pti(string s){
	int o=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='F' or s[i]=='L'){
			o=2*o;
		}else{
			o=2*o+1;
		}
	}
	return o;
}


int main(void){
	string s;
	
	struct pass_s{
		int row=0;
		int col=0;
		int id=0;
	} temp;
	
	vector<pass_s> p;
	
	while(cin>>s,s[0]!='0'){
		p.push_back(temp);
		p[p.size()-1].row=pti(s.substr(0,7));
		p[p.size()-1].col=pti(s.substr(7,3));
		p[p.size()-1].id=p[p.size()-1].row*8+p[p.size()-1].col;
	}
	//zavrsi input s 0
	
	
	int rj1=0;
	for(int i=0;i<p.size();i++){
		if(p[i].id>rj1){
			rj1=p[i].id;
		}	
	}
	cout<<"RJ1: "<<rj1<<endl;
	
	bool m[900]={0};
	
	for(int i=0;i<p.size();i++){
		m[p[i].id]=true;
	}
	
	for(int i=0;i<900;i++){
		if(m[i-1] && m[i+1] && !m[i]){
			cout<<"RJ2: "<<i<<endl;
		}
	}
	return 0;
}
