#include <bits/stdc++.h>
using namespace std;

map<int,int> last;

int first;


int main(void){
	char c;
	int poz=1,inp;
	cin>>inp;
	while(cin>>c,c==','){
		poz++;
		last[inp]=poz-1;
		cin>>inp;
	}
	int last_num=inp;
	//zavrsi input s nekim char	
	
	while(poz!=2020){
		poz++;
		if(last[last_num]!=0){
			inp=poz-last[last_num]-1;
		}else{
			inp=0;
		}
		cout<<poz<<" "<<inp<<endl;
		last[last_num]=poz-1;
		last_num=inp;
	}

	cout<<inp<<endl;
	return 0;
	
}
