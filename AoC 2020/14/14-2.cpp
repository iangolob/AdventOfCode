#include <bits/stdc++.h>
using namespace std;

struct mem_s{
	bool val[36]={0};
};

map<long long, mem_s> mem;
vector<long long> all_ads;

string int_to_b(long long x){
	string s;
	s="000000000000000000000000000000000000";
	int i=35;
	while(x>0){
		if(x%2==1){
			s[i]='1';
		}
		i--;
		x=x/2;
	}
	return s;
}

mem_s masking(string mask,string n){
	mem_s temp;
	for(int i=0;i<36;i++){
		switch(mask[i]){
			case '1':
				temp.val[35-i]=1;	
				break;
			case '0':
				temp.val[35-i]=0;
				break;
			case 'X':
				if(n[i]=='0'){
					temp.val[35-i]=0;
				}else{
					temp.val[35-i]=1;
				}	
				break;
			default:
				cout<<"error"<<endl;
				break;
		}
	}	
	return temp;
}


void write(long long ad,string mask,string num){
	mem_s temp=masking(mask,num);
	string ads=int_to_b(ad);
	
	vector<string> ad_v;
	
	for(int i=0;i<=35;i++){
		if(mask[i]=='1'){
			ads[i]='1';
		}
	}
	ad_v.push_back(ads);
	string st;
	long long sz;
	for(int i=0;i<=35;i++){
		if(mask[i]=='X'){
			sz=ad_v.size();
			for(int j=0;j<sz;j++){
				st=ad_v[j];
				st[i]='0';
				ad_v.push_back(st);
				st[i]='1';
				ad_v.push_back(st);	
			}
			ad_v.erase(ad_v.begin(),ad_v.begin()+sz);
		}
		
	}

	long long adi;
	for(int i=0;i<ad_v.size();i++){
		adi=0;
		for(int j=0;j<=35;j++){
			if(ad_v[i][j]=='1'){
				adi+=pow(2,35-j);
			}
		}
		all_ads.push_back(adi);
		for(int j=0;j<=35;j++){
			if(num[j]=='1'){
				mem[adi].val[35-j]=1;
			}else{
				mem[adi].val[35-j]=0;
			}		
		}
	}	
}


int main(void){
	string s,mask,num;
	char c;
	long long numi;
	long long ad;
	while(cin>>s,s[0]!='0'){
		cin>>c;
		if(s[1]=='a'){
			cin>>mask;
		}	
		if(s[1]=='e'){
			cin>>numi;
			num=int_to_b(numi);
			ad=stoi(s.substr(4,s.find(']')));
			write(ad,mask,num);
		}		
	};
	//zavrsi input s 0
	
	sort( all_ads.begin(), all_ads.end() );
	all_ads.erase( unique( all_ads.begin(), all_ads.end() ), all_ads.end() );

	long long rj2=0;
	for(int i=0;i<all_ads.size();i++){
		for(int j=35;j>=0;j--){
			if(mem[all_ads[i]].val[j]==1){
				rj2+=pow(2,j);
			}
		}
	}
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}
