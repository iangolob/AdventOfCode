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
	
	for(int i=0;i<op.size();i++){
		
		if(op[i].first=="nop" or op[i].first=="jmp"){
			
			poz=0;
			accumulator=0;
			for(int r=0;r<op.size();r++){
				count[r]=0;
			}			
			
			do{
				if(op[poz].first=="acc"){
					accumulator+=op[poz].second;
					poz++;
				}else{
					if((op[poz].first=="jmp" and poz!=i) or (op[poz].first=="nop" and poz==i)){
						poz+=op[poz].second;
					}else{
						if((op[poz].first=="nop" and poz!=i) or (op[poz].first=="jmp" and poz==i)){
							poz++;
						}else{
							cout<<"NE"<<endl;
						}
					}
				}
				if(poz<op.size()){
					count[poz]++;		
				}
				
			}while(count[poz]<=1 and poz<op.size());
			
			if(poz>=op.size()){
				cout<<"RJ2: "<<accumulator<<endl;
				break;
			}
		}
	}
 
	return 0;	
}
