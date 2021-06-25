#include <bits/stdc++.h>
#define TURNS 100
using namespace std;



int main(void){
	string s;
	cin>>s;
	
	char current_cup=s[0],destination_cup;
	string selection;
	for(int i=0;i<TURNS;i++){
		selection="";
		for(int j=0;j<3;j++){
			selection=selection+s[(s.find(current_cup)+1)%s.size()];
			s.erase((s.find(current_cup)+1)%s.size(),1);
		}

		if(current_cup=='1'){
			destination_cup='9';
		}else{
			destination_cup=current_cup-1;
		}
		while(s.find(destination_cup)>=s.size()){
			if(destination_cup=='1'){
				destination_cup='9';
			}else{
				destination_cup=destination_cup-1;
			}
		}
		
		s.insert(s.find(destination_cup)+1,selection);
		current_cup=s[(s.find(current_cup)+1)%s.size()];
		
		cout<<"("<<current_cup<<") "<<s<<endl;
	}
	
	cout<<"RJ1: "<<s.substr(s.find('1')+1,s.size()-s.find('1')-1)+s.substr(0,s.find('1'));
}
