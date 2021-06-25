#include <bits/stdc++.h>
using namespace std;

int str_to_int(string s){
	int n=0;
	for(int i=0;i<s.size();i++){
		n=n*10+(s[i]-'0');
	}
	return n;
}

bool byr_v(string s){
	if(s.size()==4){
		int n=str_to_int(s);
		if(n>=1920 and n<=2002){
			return 1;
		}
	}
	return 0;
}

bool iyr_v(string s){
	if(s.size()==4){
		int n=str_to_int(s);
		if(n>=2010 and n<=2020){
			return 1;
		}
	}
	return 0;
}

bool eyr_v(string s){
	if(s.size()==4){
		int n=str_to_int(s);
		if(n>=2020 and n<=2030){
			return 1;
		}
	}
	return 0;
}

bool hgt_v(string s){
	if(s.size()==5){
		if(s.substr(3,2)=="cm"){
			int n=str_to_int(s.substr(0,3));
			if(n>=150 and n<=193){
				return 1;
			}
		}
	}
	if(s.size()==4){
		if(s.substr(2,2)=="in"){
			int n=str_to_int(s.substr(0,2));
			if(n>=59 and n<=76){
				return 1;
			}
		}	
	}
	
	return 0;
}

bool hcl_v(string s){	
	if(s.size()==7){
		bool x=1;
		if(s[0]!='#'){
			x=0;
		}
		for(int i=1;i<7;i++){
			if(!((s[i]>='a' and s[i]<='f') or (s[i]>='0' and s[i]<='9'))){
				x=0;
			}
		}
		return x;
	}
	return 0;
}

bool ecl_v(string s){
	return (s=="amb" or s=="blu" or s=="grn" or
			s=="gry" or s=="hzl" or s =="oth" or s=="brn");
}

bool pid_v(string s){
	if(s.size()==9){
		bool x=1;
		for(int i=0;i<9;i++){
			if(!(s[i]>='0' and s[i]<='9')){
				x=0;
			}
		}	
		return x;
	}
	return 0;
}
	

int main(void){
	vector<string> v;
	string s;
	v.push_back("");
	getline(cin,s);
	while(s[0]!='0'){
		if(s==""){
			v.push_back("");
		}else{
			v[v.size()-1]=v[v.size()-1]+" "+s;
		}			
		getline(cin,s);
	}
	//zavrsi input sa 0
	
/*	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
*/	

	struct osoba_s{
		string byr="";
		string iyr="";
		string eyr="";
		string hgt="";
		string hcl="";
		string ecl="";
		string pid="";
		string cid="";
	} o[v.size()];
	
	int poz;
	int x;
	for(int i=0;i<v.size();i++){
	//	cout<<i<<endl;
		x=v[i].find("byr");
		if(x<=v[i].size()){
			o[i].byr=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("iyr");
		if(x<=v[i].size()){
			o[i].iyr=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("eyr");
		if(x<=v[i].size()){
			o[i].eyr=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("hgt");
		if(x<=v[i].size()){
			o[i].hgt=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("hcl");
		if(x<=v[i].size()){
			o[i].hcl=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("ecl");
		if(x<=v[i].size()){
			o[i].ecl=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("pid");
		if(x<=v[i].size()){
			o[i].pid=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
		x=v[i].find("cid");
		if(x<=v[i].size()){
			o[i].cid=v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4);
	//		cout<<v[i].substr(x+4,v[i].find_first_of(' ',x+4)-x-4)<<endl;
		}
	
		//cout<<o[i].byr<<" "<<x<<" "<<v[i].find_first_of(':',x+1)<<endl;
	}
	
	int rj1=0;
	for(int i=0;i<v.size();i++){
		if( o[i].byr!="" &&
			o[i].iyr!="" &&
			o[i].eyr!="" &&
			o[i].hgt!="" &&
			o[i].hcl!="" &&
			o[i].ecl!="" &&
			o[i].pid!=""
			){
				rj1++;
		}
	}
	cout<<"RJ1: "<<rj1<<endl;
	
	int rj2=0;
	for(int i=0;i<v.size();i++){
		if( byr_v(o[i].byr) &&
			iyr_v(o[i].iyr) &&
			eyr_v(o[i].eyr) &&
			hgt_v(o[i].hgt) &&
			hcl_v(o[i].hcl) &&
			ecl_v(o[i].ecl) &&
			pid_v(o[i].pid)){
			rj2++;		
		}
	//	ispis po ljudima	
	//	cout<<i<<":  "<<byr_v(o[i].byr)<<" "<<iyr_v(o[i].iyr)<<" "<<eyr_v(o[i].eyr)<<" "<<hgt_v(o[i].hgt)<<
	//		" "<<hcl_v(o[i].hcl)<<" "<<ecl_v(o[i].ecl)<<" "<<pid_v(o[i].pid)<<endl;
	}
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}
