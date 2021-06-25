#include <bits/stdc++.h>
#define TURNS 100 //test 100 zad 10000000
#define MAX_CUP 9 //test 9 	1000000
using namespace std;

//test 389125467
list<int>::iterator iterator_of[MAX_CUP+2];
int main(void){
	string s;
	cin>>s;
	list<int> v;
	
	auto it=v.begin();
	for(int i=0;i<MAX_CUP;i++){
		
		
		if(i<s.size()){
			v.push_back(s[i]-'0');
			iterator_of[s[i]-'0']=next(it,1);
		}else{v.push_back(i+1);
			iterator_of[i+1]=next(it,1);
			
		}
		advance(it,1);
	}
/*	for(int i=1;i<=MAX_CUP;i++){
		cout<<*iterator_of[i]<<" ";
	}
*/
	cout<<endl<<endl;
	int current_cup=v.front(),destination_cup;
	int selection[3];
	
	auto itc=v.begin();
	
	
	
	for(long long i=0;i<TURNS;i++){
		if(i%100000==0){
			cout<<i<<endl;
			
			
		}
		if(i>20000){
		//	cout<<"current cup: "<<current_cup<<endl;	
			
				
		}
		for(int j=1;j<=MAX_CUP;j++){
		if(j!=*iterator_of[j]){
			cout<<"ERROR ----------------- "<<j<<" "<<*iterator_of[j]<<endl;
		}
	}
	
		for(int j=0;j<3;j++){
			if(*itc==v.back()){
				selection[j]=v.front();	
				v.pop_front();	
			}else{
				if(next(itc,1)==v.end()){
					selection[j]=v.back();
					v.pop_back();		
				}else{
					selection[j]=*(next(itc,1));
					v.erase(next(itc,1));
				}
			}		
		//	cout<<v.back();	
		}
		for(int j=0;j<3;j++){
			iterator_of[selection[j]]=v.end();
		}
		
		if(current_cup==1){
			destination_cup=MAX_CUP;
		}else{
			destination_cup=current_cup-1;
		}	
		
		while(iterator_of[destination_cup]==v.end()){
			if(destination_cup==1){
				destination_cup=MAX_CUP;
			}else{
				destination_cup=destination_cup-1;
			}
		}
		
	
cout<<endl<<"selection: "<<selection[0]<<selection[1]<<selection[2]<<endl;
		cout<<"left: ";
		for(auto itp=v.begin();itp!=v.end();++itp){
			cout<<*itp;
		}
		cout<<endl;
		cout<<"destination: "<<destination_cup<<" - "<<*iterator_of[destination_cup]<<endl;
		cout<<"-----"<<endl;
	
		
		
		
		auto itd=iterator_of[destination_cup];	
		if(!(itd==v.end())){
			advance(itd,1);	
		}
		for(int j=1;j<=3;j++){
			
			if(*itd==v.back()){
				v.push_back(selection[j-1]);
				iterator_of[selection[j-1]]=next(itd,1);
			}else{
			//	cout<<*itd<<" "<<*v.end()<<endl;
			//cout<<selection[j-1]<<endl;
				v.insert(itd,selection[j-1]);
				iterator_of[selection[j-1]]=prev(itd,1);
			}
		}


		if(*itc==v.back()){
			current_cup=v.front();
			itc=v.begin();
		}else{
			current_cup=*(next(itc,1));
			itc=next(itc,1);
		}
		
/*		cout<<"("<<current_cup<<") "<<*itc<<endl;
		for(auto itp=v.begin();itp!=v.end();++itp){
			cout<<*itp;
		}
	//	cout<<endl;
*/
	}
	it=v.begin();
	for(int i=0;i<9;i++){
		cout<<*it<<" ";
		advance(it,1);
	}
	cout<<endl;
	cout<<"a"<<endl;
	long long rj2=*(next(find(v.begin(),v.end(),1),1));
	rj2=rj2*(*(next(find(v.begin(),v.end(),1),2)));
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}
