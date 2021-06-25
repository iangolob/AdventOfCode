#include <bits/stdc++.h>
using namespace std;

vector<int> inp;
long long inpv[100]={0};

long long prop(int poz){
	long long rez=0;
	for(int i=1;i<=3;i++){
		if(poz+i<inp.size()){
			if(poz+i==inp.size()-1 and abs(inp[poz]-inp[poz+i])<=3){
				rez++;
			}else{
				if(abs(inp[poz]-inp[poz+i])<=3){
					if(inpv[poz+i]==-1){
						inpv[poz+i]=prop(poz+i);
					}
					rez+=inpv[poz+i];		
				}	
			}			
		}else{
			rez=1;
		}
	}		
	return rez;
}




int main(void){
	
	for(int i=0;i<100;i++){
		inpv[i]=-1;
	}


	int inpt,maxt;
	while(cin>>inpt,inpt!=0){
		if(maxt<inpt){
			maxt=inpt;
		}
		inp.push_back(inpt);
	}
	//zavrsi input sa 0
	inp.push_back(0);
	inp.push_back(maxt+3);
	sort(inp.begin(),inp.end());
	
	
	int dif1=0,dif3=0;
	for(int i=1;i<inp.size();i++){
		if(abs(inp[i]-inp[i-1])==1){
			dif1++;
		}
		if(abs(inp[i]-inp[i-1])==3){
			dif3++;
		}
	}
	
	cout<<"RJ1: "<<dif1*dif3<<endl;
	
	cout<<"RJ2: "<<prop(0)<<endl;
	for(int i=0;i<inp.size();i++){
//		cout<<inpv[i]<<endl;
	}
	return 0;
}
