#include <bits/stdc++.h>
#define X_INPUT 8
#define Y_INPUT 8

using namespace std;


map<tuple<int,int,int>,bool> active;
vector<tuple<int,int,int>> all_active;



int activeAround(int x,int y,int z){
	int rez=0;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			for(int k=-1;k<=1;k++){
				if((i!=0 or j!=0 or k!=0) and active[make_tuple(x+i,y+j,z+k)]){
					rez++;		
				}
					
			}
		}
	}
	return rez;
}


int main(void){
	char c;
	for(int i=0;i<Y_INPUT;i++){
		for(int j=0;j<X_INPUT;j++){
			cin>>c;
			if(c=='#'){
				all_active.push_back(make_tuple(j,i,0));
				active[make_tuple(j,i,0)]=1;
			}	
		}
	}	
	
	queue<tuple<int,int,int>> next_active,next_inactive;
	for(int i=0;i<6;i++){
		cout<<i<<endl;
		for(int j=0;j<all_active.size();j++){
			int tempi=activeAround(get<0>(all_active[j]),get<1>(all_active[j]),get<2>(all_active[j]));
			if(2<=tempi and  tempi<=3){
				//remains active
			}else{
				next_inactive.push(all_active[j]);
			}
			
			//check neighbours if inactive
			for(int x1=-1;x1<=1;x1++){
				for(int y1=-1;y1<=1;y1++){
					for(int z1=-1;z1<=1;z1++){
						if((x1!=0 or y1!=0 or z1!=0) and
							!active[make_tuple(get<0>(all_active[j])+x1,get<1>(all_active[j])+y1,get<2>(all_active[j])+z1)]){
							if(activeAround(get<0>(all_active[j])+x1,get<1>(all_active[j])+y1,get<2>(all_active[j])+z1)==3){
								next_active.push(make_tuple(get<0>(all_active[j])+x1,get<1>(all_active[j])+y1,get<2>(all_active[j])+z1));
							}
						}
					}
				}
			}
			
			
		}
		//push all
			while(!next_inactive.empty()){
				active[next_inactive.front()]=0;	
				next_inactive.pop();
			}
			
			while(!next_active.empty()){
				if(active[next_active.front()]==0){
					active[next_active.front()]=1;
					all_active.push_back(next_active.front());
				}
				next_active.pop();
			}
			sort( all_active.begin(), all_active.end() );
			all_active.erase( unique( all_active.begin(), all_active.end() ), all_active.end() );
	}
	
	int rj1=0;
	for(int i=0;i<all_active.size();i++){
		if(active[all_active[i]]){
			rj1++;
			active[all_active[i]]=0;
		}
	}
	
	cout<<"RJ1: "<<rj1<<endl;
	return 0;
}
