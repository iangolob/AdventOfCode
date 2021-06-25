#include <bits/stdc++.h>
using namespace std;

string s;

struct rule_s{
	bool is_char=0;
	char c;
	vector<int> r1;
	bool has_two=0;
	vector<int> r2;
};

map<int,rule_s> rule;
int poz=0;

bool check(int rule_num){
	int cur_poz=poz;
	bool correct;
	if(rule[rule_num].is_char){
		if(s[poz]==rule[rule_num].c){
			poz++;
			return 1;
		}
	}else{
		if(rule[rule_num].has_two){
			correct=0;
			for(int i=0;i<rule[rule_num].r1.size();i++){
				if(i==0){
					correct=check(rule[rule_num].r1[i]);
				}else{
					correct= correct and check(rule[rule_num].r1[i]);
				}
			}
			if(correct){
				return 1;
			}	
			poz=cur_poz;
			correct=0;
			for(int i=0;i<rule[rule_num].r2.size();i++){
				if(i==0){
					correct=check(rule[rule_num].r2[i]);
				}else{
					correct= correct and check(rule[rule_num].r2[i]);
				}
			}
			if(correct){
				return 1;
			}
		}else{
			correct=0;
			for(int i=0;i<rule[rule_num].r1.size();i++){
				if(i==0){
					correct=check(rule[rule_num].r1[i]);
				}else{
					correct= correct and check(rule[rule_num].r1[i]);
				}
			}
			if(correct){
				return 1;
			}
		}
	}
	return 0;
}





int main(void){
	
	poz=0;
	int poz_e;
	string s2;
	while(getline(cin,s),s!=""){
		poz=stoi(s.substr(0,s.find(":")));
		s.erase(0,s.find(":")+2);
		if(s.find("\"")<s.size()){
			rule[poz].is_char=1;
			rule[poz].c=s[s.find("\"",s.find_first_of("\"")+1)-1];
			cout<<rule[poz].c<<endl;
		}else{
			if(s.find("|")<s.size()){
				s2=s.substr(s.find("|")+2,s.size()-s.find("|")-2);
				s=s.substr(0,s.find("|")-1);
				
				rule[poz].has_two=1;
				while(s.find(" ")<s.size()){
					rule[poz].r1.push_back(stoi(s.substr(0,s.find(" "))));
					s.erase(0,s.find(" ")+1);
				}
				rule[poz].r1.push_back(stoi(s.substr(0,s.size())));
				
				while(s2.find(" ")<s2.size()){
					rule[poz].r2.push_back(stoi(s2.substr(0,s2.find(" "))));
					s2.erase(0,s2.find(" ")+1);
				}
				rule[poz].r2.push_back(stoi(s2.substr(0,s2.size())));	
						
			}else{
				while(s.find(" ")<s.size()){
					rule[poz].r1.push_back(stoi(s.substr(0,s.find(" "))));
					s.erase(0,s.find(" ")+1);
				}
				rule[poz].r1.push_back(stoi(s.substr(0,s.size())));
			}
			for(int i=0;i<rule[poz].r1.size();i++){
				cout<<rule[poz].r1[i]<<" ";
			}	
			cout<<endl;
			for(int i=0;i<rule[poz].r2.size();i++){
				cout<<rule[poz].r2[i]<<" ";
			}	
			cout<<endl;
		}	
	}
	
	
	
	int rj1=0;
	while(getline(cin,s),s!=""){
		poz=0;
		if(check(0)){
			cout<<poz<<" "<<s.size()<<endl;	
			if(poz==s.size()){
				rj1++;
			}
		}
	}
	cout<<"RJ1: "<<rj1<<endl;
	
	return 0;
}
