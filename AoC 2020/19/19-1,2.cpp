#include <bits/stdc++.h>
#include <time.h>
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
	if(poz==s.size()){
		return 0;
	}else{
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
		}	
	}
	clock_t t;


	vector<string> input;
	int rj2=0,rj1=0;
	int word_size=0;
	while(getline(cin,s),s!=""){
		input.push_back(s);
		poz=0;
		if(check(0)){
			if(poz==s.size()){
				rj1++;
				if(word_size==0){
					word_size=s.size();
				}
			}
		}			
	}
	word_size=word_size/3;
	
	t=clock();
	int num_42,num_31;
	bool stop_42,wrong;
	for(int i=0;i<input.size();i++){
		num_42=0;
		num_31=0;
		stop_42=0;
		wrong=0;
		for(int j=0;j<input[i].size()/word_size;j++){
			poz=0;
			s=input[i].substr(j*word_size,word_size);
			if(!wrong){
				poz=0;
				if(check(42) and !stop_42){
					num_42++;
				}else{
					poz=0;
					if(check(31)){
						num_31++;
						stop_42=1;
					}else{
						wrong=1;
					}
				}
			}
		}
		if(!wrong and (num_42>num_31) and (input[i].size()%word_size==0) and num_31>0){
			rj2++;
		}
	}
	t=clock()-t;
	
	cout<<"RJ1: "<<rj1<<endl;
	cout<<"RJ2: "<<rj2<<endl;
	cout<<t*0.001<<"s"<<endl;

	return 0;
}
