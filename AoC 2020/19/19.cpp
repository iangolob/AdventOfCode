#include <bits/stdc++.h>
using namespace std;

string s;

struct rule_s{
	bool is_char=0;
	char c;
	int r11=1,r12=1,r21=1,r22=1;
//	vector<int> r1;
	bool has_two=0;
//	vector<int> r2;
};

map<int,rule_s> rule;
int poz=0;

bool check(int rule_num){
	int cur_poz=poz;
	if(rule[rule_num].is_char){
		if(s[poz]==rule[rule_num].c){
			poz++;
			return 1;
		}
	}else{
		if(rule[rule_num].has_two){
			if(check(rule[rule_num].r11)){
				if(check(rule[rule_num].r12)){
					return 1;
				}
			}
			poz=cur_poz;
			if(check(rule[rule_num].r21)){
				if(check(rule[rule_num].r22)){
					return 1;
				}
			}
		}else{
			if(check(rule[rule_num].r11)){
				if(check(rule[rule_num].r12)){
					return 1;
				}
			}
		}
	}
	return 0;
}





int main(void){
	
	poz=0;
	int poz_e;
	while(getline(cin,s),s!=""){
		poz=stoi(s.substr(0,s.find(":")));
		s.erase(0,s.find(":")+2);
		cout<<s<<endl;
		if(s.find("\"")<s.size()){
			rule[poz].is_char=1;
			rule[poz].c=s[s.find("\"",s.find_first_of("\"")+1)-1];
			cout<<rule[poz].c<<endl;
		}else{
			if(s.find_first_of(" ")<s.size()){
				rule[poz].r11=stoi(s.substr(0,s.find_first_of(" ")));
				s.erase(0,s.find(" ")+1);
		
			}else{
				
			}
			
			if(s.find("|")<s.size()){
				rule[poz].has_two=1;
				rule[poz].r12=stoi(s.substr(0,s.find(" ")));
				s.erase(0,s.find(" ")+3);
				rule[poz].r21=stoi(s.substr(0,s.find(" ")));
				s.erase(0,s.find(" ")+1);
				rule[poz].r22=stoi(s.substr(0,s.size()));
			}else{
				rule[poz].r12=stoi(s.substr(0,s.size()));
			}
			cout<<rule[poz].r11<<" "<<rule[poz].r12<<" "<<rule[poz].r21<<" "<<rule[poz].r22<<endl;	
		}	
	}
	
	
	
	rule[8]=rule[42];
	
	int rj1=0;
	while(getline(cin,s),s!=""){
		poz=0;
		if(check(0)){
			if(poz==s.size()-1){
				rj1++;cout<<"da"<<endl;
			}
		}
	}
	cout<<"RJ1: "<<rj1<<endl;
	
	return 0;
}
