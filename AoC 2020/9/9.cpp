#include <bits/stdc++.h>
using namespace std;

vector <long long> inp;





int main(void){
	
	long long inpt;	
	while(cin>>inpt,inpt!=0){
		inp.push_back(inpt);
	}
	//zavrsi input s 0
	
	bool b=0;
	int rj1=0;
	for(int x=25;x<inp.size();x++){
		
		b=0;		
		for(int i=x-25;i<x-1;i++){
			for(int j=i+1;j<x;j++){
				if(inp[x]==inp[i]+inp[j]){
					b=1;
				}			
			}
			if(b){
				break;
			}
		}
		
		if(!b){
			cout<<"RJ1: "<<inp[x]<<endl;
			rj1=inp[x];
			break;
		}
		
	}
	
	
	long long poz=0,len,sum;
	long long minrj2,maxrj2;
	for(poz=0;poz<inp.size()-1;poz++){
		
		len=0;
		sum=0;
		while(sum<rj1){
			sum+=inp[poz+len];
			len++;
		}
		
		if(sum==rj1 and len>=2){
			
			for(int i=poz;i<=poz+len-1;i++){
				if(inp[i]>maxrj2 or i==poz){
					maxrj2=inp[i];
				}
				if(inp[i]<minrj2 or i==poz){
					minrj2=inp[i];
				}
			}
			
			cout<<"RJ2: "<<maxrj2+minrj2<<endl;
		}
	}
	
	return 0;
}
