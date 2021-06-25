#include <bits/stdc++.h>
using namespace std;




int rec(deque<int> p1, deque<int> p2){
	set<pair<deque<int>,deque<int>>> state;
	int p1_card,p2_card;
	long long expected_size=0;
	while(p1.size()!=0 and p2.size()!=0){
		
		state.insert(make_pair(p1,p2));

		expected_size++;
		if(expected_size!=state.size()){
			cout<<"inf "<<expected_size<<endl;
				return 1;
		}
		
		p1_card=p1.front();
		p2_card=p2.front();
		p1.pop_front();
		p2.pop_front();
		
		if(p1_card<=p1.size() and p2_card<=p2.size()){
			if(rec(p1,p2)==1){
				p1.push_back(p1_card);
				p1.push_back(p2_card);	
			}else{
				p2.push_back(p2_card);
				p2.push_back(p1_card);	
			}		
		}else{
			if(p1_card>p2_card){
				p1.push_back(p1_card);
				p1.push_back(p2_card);
			}else{
				p2.push_back(p2_card);
				p2.push_back(p1_card);
			}	
		}		
	}
	if(p1.size()>p2.size()){
		return 1;
	}else{
		return 2;
	}
}



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
	vector<deque<int>> state_p1,state_p2;
	while(p1.size()!=0 and p2.size()!=0){
		for(int i=0;i<state_p1.size();i++){
			if(p1==state_p1[i] and p2==state_p2[i]){
				return 1;
			}
		}	
		state_p1.push_back(p1);
		state_p2.push_back(p2);
		
		p1_card=p1.front();
		p2_card=p2.front();
		cout<<p1_card<<" "<<p2_card<<endl;
		p1.pop_front();
		p2.pop_front();
		
		if(p1_card<=p1.size() and p2_card<=p2.size()){
			if(rec(p1,p2)==1){
				p1.push_back(p1_card);
				p1.push_back(p2_card);	
			}else{
				p2.push_back(p2_card);
				p2.push_back(p1_card);	
			}		
		}else{
			if(p1_card>p2_card){
				p1.push_back(p1_card);
				p1.push_back(p2_card);
			}else{
				p2.push_back(p2_card);
				p2.push_back(p1_card);
			}	
		}
	}
	
	
	
	
	int rj2=0;
	cout<<"Player 1: ";
	while(p1.size()!=0){
		rj2=rj2+p1.size()*p1.front();
		cout<<p1.front()<<" "<<endl;
		p1.pop_front();
	}
	cout<<endl;

	cout<<"Player 2: ";
	while(p2.size()!=0){
		rj2=rj2+p2.size()*p2.front();
		cout<<p2.front()<<" ";
		p2.pop_front();
	}
	cout<<endl;
	
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}

