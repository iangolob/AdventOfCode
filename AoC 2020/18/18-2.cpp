#include <bits/stdc++.h>
using namespace std;




long long ex(void){
	char c=0;
	vector<char> op; //op=0 +, op=1 *
	vector<long long> num;
	cin.get(c);
	
	while(c!=')'){
		if(!isspace(c)){
			switch(c){
				case '+':
					op.push_back(c);
					break;
				case '*':
					op.push_back(c);
					break;
				case '(':
					num.push_back(ex());
					break;
				default:
					num.push_back(c-'0');
					break;
			}		
		}
		cin.get(c);	
	//	cout<<rez<<endl;
	}
	int poz=0;
	if(!op.empty()){
		while(poz<op.size()){					
			if(op[poz]=='+'){
				num[poz]=num[poz+1]+num[poz];
				num.erase(num.begin()+poz+1);
				op.erase(op.begin()+poz);
			}else{
				poz++;
			}
		}	
	}
	poz=0;
	if(!op.empty()){
		while(poz<op.size()){
			if(op[poz]=='*'){
				num[poz]=num[poz+1]*num[poz];
				num.erase(num.begin()+poz+1);
				op.erase(op.begin()+poz);
			}else{
				poz++;
			}
		}	
	}

	
	
	return num[0];
}




int main(void){
	
	char c;
	long long rez=0,rj2=0;
	vector<char> op; //op=0 +, op=1 *
	vector<long long> num;
	while(cin.get(c),c!='E'){
		num.clear();
		op.clear();
		while(c!='\n'){
			if(!isspace(c)){
				switch(c){
					case '+':
						op.push_back(c);
						break;
					case '*':
						op.push_back(c);
						break;
					case '(':
						num.push_back(ex());
						break;
					default:
						num.push_back(c-'0');
						break;
				}		
			}
			cin.get(c);	
		}
		
		int poz=0;
		if(!op.empty()){
			while(poz<op.size()){					
				if(op[poz]=='+'){
					num[poz]=num[poz+1]+num[poz];
					num.erase(num.begin()+poz+1);
					op.erase(op.begin()+poz);
				}else{
					poz++;
				}
			}	
		}
		poz=0;
		if(!op.empty()){
			while(poz<op.size()){
				if(op[poz]=='*'){
					num[poz]=num[poz+1]*num[poz];
					num.erase(num.begin()+poz+1);
					op.erase(op.begin()+poz);
				}else{
					poz++;
				}
			}	
		}
			
		cout<<num[0]<<endl;		
		rj2+=num[0];
	}	
	//zavrsi sa E
	
	
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}
