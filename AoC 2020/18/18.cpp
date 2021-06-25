#include <bits/stdc++.h>
using namespace std;




long long ex(void){
	char op=0;
	long long rez=0;
	char c=0;
	cin.get(c);
	while(c!=')'){
		if(!isspace(c)){
			switch(c){
				case '+':
					op=c;
					break;
				case '*':
					op=c;
					break;
				case '(':
					switch(op){
						case '+':
							rez=rez+ex();
							break;
						case '*':
							rez=rez*ex();
							break;
						default:
							rez=ex();
							break;
					}
					break;
				case ')':
					break;
				default:
					switch(op){
						case '+':
							rez=rez+c-'0';
							break;
						case '*':
							rez=rez*(c-'0');
							break;
						default:
							rez=c-'0';
							break;
					}
					break;
			}		
		}
				
		cin.get(c);
	//	cout<<rez<<endl;
	}
	return rez;
}




int main(void){
	
	char c;
	long long rez=0,rj1=0;
	char op=0; //op=0 +, op=1 *
	while(cin.get(c),c!='E'){
		rez=0;
		op=0;
		while(c!='\n'){
			if(!isspace(c)){
				switch(c){
					case '+':
						op=c;
						break;
					case '*':
						op=c;
						break;
					case '(':
						switch(op){
							case '+':
								rez=rez+ex();
								break;
							case '*':
								rez=rez*ex();
								break;
							default:
								rez=ex();
								break;
						}
						break;
					default:
						switch(op){
							case '+':
								rez=rez+c-'0';
								break;
							case '*':
								rez=rez*(c-'0');
								break;
							default:
								rez=c-'0';
								break;
						}
						break;
				}		
			}
					
			cin.get(c);
		
		}
		cout<<rez<<endl;		
		rj1+=rez;
	}	
	//zavrsi sa E
	
	
	cout<<"RJ1: "<<rj1<<endl;
	return 0;
}
