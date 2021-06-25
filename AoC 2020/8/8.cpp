#include <bits/stdc++.h>
using namespace std;

int accumulator=0,poz=0;
vector<pair<string,int>> op;




int main(void){
	char ct;
	string st;
	int it;
	
	while(cin>>st,st[0]!='0'){
		cin>>ct;
		cin>>it;
		if(ct=='-'){
			it=-it;
		}
		op.push_back(make_pair(st,it));
	}
	//zavrsi input sa 0
	
	
	for(int i=0;i<op.size();i++){
//		cout<<op[i].first<<" "<<op[i].second<<endl;
	}
	

	int count[op.size()]={0};
	do{
		if(op[poz].first=="acc"){
			accumulator+=op[poz].second;
			poz++;
		}else{
			if(op[poz].first=="jmp"){
				poz+=op[poz].second;
			}else{
				if(op[poz].first=="nop"){
					poz++;
				}else{
					cout<<"NE"<<endl;
				}
			}
		}
		count[poz]++;		
	}while(count[poz]<=1);
	
	cout<<"RJ1: "<<accumulator<<endl;
	
	return 0;	
}
