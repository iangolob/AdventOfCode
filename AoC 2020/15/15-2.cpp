#include <bits/stdc++.h>
using namespace std;

map<long long,long long> last;

int first;


int main(void){
	char c;
	long long poz=1,inp;
	cin>>inp;
	while(cin>>c,c==','){
		poz++;
		last[inp]=poz-1;
		cin>>inp;
	}
	long long last_num=inp;
	//zavrsi input s nekim char	
	
	
	
	while(poz!=30000000){
		poz++;
		if(last[last_num]!=0){
			inp=poz-last[last_num]-1;
		}else{
			inp=0;
		}
	//	cout<<poz<<" "<<inp<<endl;
		last[last_num]=poz-1;
		last_num=inp;
	}

	cout<<inp<<endl;
	return 0;
	
}
