#include <bits/stdc++.h>
using namespace std;





int main(void){
	
	string s;	
	deque<int> p1,p2;
	
	getline(cin,s);
	while(getline(cin,s),s!=""){
		p1.push_back(stoi(s));
	}
	
	getline(cin,s);
	while(getline(cin,s),s!=""){
		p2.push_back(stoi(s));
	}
	
	
	int p1_card,p2_card;
	while(p1.size()!=0 and p2.size()!=0){
		p1_card=p1.front();
		p2_card=p2.front();
		p1.pop_front();
		p2.pop_front();
		if(p1_card>p2_card){
			p1.push_back(p1_card);
			p1.push_back(p2_card);
		}else{
			p2.push_back(p2_card);
			p2.push_back(p1_card);
		}
	}
	
	int rj1=0;
	cout<<"Player 1: ";
	while(p1.size()!=0){
		rj1=rj1+p1.size()*p1.front();
		cout<<p1.front()<<" "<<endl;
		p1.pop_front();
	}
	cout<<endl;

	cout<<"Player 2: ";
	while(p2.size()!=0){
		rj1=rj1+p2.size()*p2.front();
		cout<<p2.front()<<" ";
		p2.pop_front();
	}
	cout<<endl;
	
	cout<<"RJ1: "<<rj1<<endl;
	return 0;
}

