#include <bits/stdc++.h>
using namespace std;

set<pair<deque<int>,deque<int>>> state[100];
deque<int> p1[100],p2[100];


int rec(int depth,int p1_cards_drawn,int p2_cards_drawn){
//	cout<<depth<<endl;
	int p1_card,p2_card;
	long long expected_size=0;
	state[depth].clear();
	if(depth!=0){
		p1[depth]=p1[depth-1];
		p2[depth]=p2[depth-1];
		while(p1[depth].size()!=p1_cards_drawn) p1[depth].pop_back();
		while(p2[depth].size()!=p2_cards_drawn) p2[depth].pop_back();
	}
	
	
	while(p1[depth].size()!=0 and p2[depth].size()!=0){
		
		state[depth].insert(make_pair(p1[depth],p2[depth]));
		expected_size++;
		if(expected_size!=state[depth].size()){
	//		cout<<"inf "<<expected_size<<endl;
				return 1;
		}
		
		p1_card=p1[depth].front();
		p2_card=p2[depth].front();
		p1[depth].pop_front();
		p2[depth].pop_front();
	//	cout<<"DEPTH: "<<depth<<": "<<p1_card<<" "<<p2_card<<endl;
		if(p1_card<=p1[depth].size() and p2_card<=p2[depth].size()){
			if(rec(depth+1,p1_card,p2_card)==1){
				p1[depth].push_back(p1_card);
				p1[depth].push_back(p2_card);	
			}else{
				p2[depth].push_back(p2_card);
				p2[depth].push_back(p1_card);	
			}		
		}else{
			if(p1_card>p2_card){
				p1[depth].push_back(p1_card);
				p1[depth].push_back(p2_card);
			}else{
				p2[depth].push_back(p2_card);
				p2[depth].push_back(p1_card);
			}	
		}		
	}
	if(p1[depth].size()>p2[depth].size()){
		return 1;
	}else{
		return 2;
	}
}



int main(void){
	
	string s;	
	
	getline(cin,s);
	while(getline(cin,s),s!=""){
		p1[0].push_back(stoi(s));
	}
	
	getline(cin,s);
	while(getline(cin,s),s!=""){
		p2[0].push_back(stoi(s));
	}
	
	rec(0,0,0);
	
	
	
	long long rj2=0;
	cout<<"Player 1: ";
	while(p1[0].size()!=0){
		rj2=rj2+p1[0].size()*p1[0].front();
		cout<<p1[0].front()<<" ";
		p1[0].pop_front();
	}
	cout<<endl;

	cout<<"Player 2: ";
	while(p2[0].size()!=0){
		rj2=rj2+p2[0].size()*p2[0].front();
		cout<<p2[0].front()<<" ";
		p2[0].pop_front();
	}
	cout<<endl;
	
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}

