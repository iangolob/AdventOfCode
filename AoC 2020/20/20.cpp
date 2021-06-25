#include <bits/stdc++.h>
#define DIM 10
using namespace std;


struct tile_s{
	bool a[8][DIM][DIM];
	int id;
	bool border[8][4][DIM];
}temp_tile;
vector<tile_s> tiles;

struct space_s{
		int id=-1;
		int perm=-1;
		int num=-1;
} a[200][200];

int minm=200,minn=200,maxm=0,maxn=0;

void flip(bool *pin,bool *pout){
	for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			*(pout+(DIM-i-1)*DIM+j)=*(pin+i*DIM+j);
		}
	}
	return;
}

void rotate(bool *pin,bool *pout,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			*(pout+j*n+(n-i-1))=*(pin+i*n+j);
		}
	}
	return;
}

void gen_border(bool *pin,bool *pout){
	int i=0,j=0;
	
	//0
	for(i=0,j=0;j<DIM;j++){
		*(pout+0*DIM+j)=*(pin+i*DIM+j);
	}
	
	//2
	for(i=0,j=DIM-1;i<DIM;i++){
		*(pout+2*DIM+i)=*(pin+i*DIM+j);
	}
	
	//3
	for(i=DIM-1,j=0;j<DIM;j++){
		*(pout+3*DIM+j)=*(pin+i*DIM+j);
	}
	
	//1
	for(i=0,j=0;i<DIM;i++){
		*(pout+1*DIM+i)=*(pin+i*DIM+j);
	}
	
	return;
}

int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

void expand(int m, int n){
	for(int d=0;d<4;d++){
		if(a[m+dir[d][0]][n+dir[d][1]].num==-1){
			//provjeri plocice oko
			for(int p=0;p<tiles.size();p++){
				//permutacije plocice
				for(int i=0;i<8;i++){
					bool valid=1;
					//border
					for(int j=0;j<DIM;j++)	{
						if(!(tiles[p].border[i][3-d][j]==tiles[a[m][n].num].border[a[m][n].perm][d][j])){
							valid=0;
						}
					}
					if(valid and (p!=a[m][n].num)){
						maxm=max(maxm,m+dir[d][0]);
						minm=min(minm,m+dir[d][0]);
						maxn=max(maxn,n+dir[d][1]);
						minn=min(minn,n+dir[d][1]);
						a[m+dir[d][0]][n+dir[d][1]].num=p;
						a[m+dir[d][0]][n+dir[d][1]].perm=i;
						a[m+dir[d][0]][n+dir[d][1]].id=tiles[p].id;
						expand(m+dir[d][0],n+dir[d][1]);
					}
				}
			}					
		}	
		
	}
	return;
}




int main(void){
	
	string s;
	char c;
	while(getline(cin,s),s!=""){
		temp_tile.id=stoi(s.substr(5,4));
		for(int i=0;i<DIM;i++){
			for(int j=0;j<DIM;j++){
				cin>>c;
				if(c=='#'){
					temp_tile.a[0][i][j]=1;
				}else{
					temp_tile.a[0][i][j]=0;	
				}		
			}
		}
		tiles.push_back(temp_tile);
		getline(cin,s);
		getline(cin,s);
	}
	//zavrsi input s praznim


	//gen flip
	for(int i=0;i<tiles.size();i++){
		flip(&tiles[i].a[0][0][0],&tiles[i].a[4][0][0]);
	}
	//gen rotate
	for(int i=0;i<tiles.size();i++){
		for(int j=1;j<8;j++){
			if(j!=4){
				rotate(&tiles[i].a[j-1][0][0],&tiles[i].a[j][0][0],DIM);
			}
		}
	}

	//BORDER: 0=N, 3=S, 2=E, 1=W
	for(int i=0;i<tiles.size();i++){
		for(int j=0;j<8;j++){
			gen_border(&tiles[i].a[j][0][0],&tiles[i].border[j][0][0]);
		}
	}
	


	a[50][50].num=0;
	a[50][50].id=tiles[0].id;
	a[50][50].perm=0;

	expand(50,50);
	
	
	for(int i=minm;i<=maxm;i++){
		for(int j=minn;j<=maxn;j++){
		cout<<a[i][j].id<<" ";
		}
		cout<<endl;	
	}
	
	long long rj1=1;
	rj1=rj1*(a[minm][minn].id);
	rj1=rj1*(a[minm][maxn].id);
	rj1=rj1*(a[maxm][minn].id);
	rj1=rj1*(a[maxm][maxn].id);


	cout<<"RJ1: "<<rj1<<endl;

	int water_dim_m=(maxm-minm+1)*(DIM-2);
	int water_dim_n=(maxm-minm+1)*(DIM-2);
	bool water[4][water_dim_m][water_dim_n]={0};
	for(int i=0;i<=maxm-minm;i++){
		for(int j=0;j<=maxn-minn;j++){
			for(int m=1;m<DIM-1;m++){
				for(int n=1;n<DIM-1;n++){
					water[0][i*(DIM-2)+m-1][j*(DIM-2)+n-1]=tiles[a[i+minm][j+minn].num].a[a[i+minm][j+minn].perm][m][n];
				}
			}
		}
	}
	
/*

	for(int i=0;i<water_dim_m;i++){
		for(int j=0;j<water_dim_n;j++){
			cout<<water[0][i][j];
		}
		cout<<endl;
	}
*/	
	bool monster[4][water_dim_m][water_dim_n]={0};
	for(int x=0;x<4;x++){
		for(int y=0;y<water_dim_m;y++){
			for(int z=0;z<water_dim_n;z++){
				monster[x][y][z]=0;
			}
		}
	}
	
	
	bool monster_s[3][20]={		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
								1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,
								0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0};
			
/*	
	for(int i=0;i<3;i++){
		for(int j=0;j<20;j++){
			if(monster_s[i][j]){
				cout<<"O";
			}else{
				cout<<".";
			}
		}
		cout<<endl;
	}		
*/		
			
	int rj2_perm=-1;
	for(int x=0;x<4;x++){
		if(x!=0){
			rotate(&water[x-1][0][0],&water[x][0][0],water_dim_m);
		}					
		for(int i=0;i<water_dim_m-2;i++){
			for(int j=0;j<water_dim_n-19;j++){
				bool is_monster=1;
				for(int m=i;m<i+3;m++){
					for(int n=j;n<j+20;n++){
						if(monster_s[m-i][n-j]!=water[x][m][n] and monster_s[m-i][n-j]==1){
							is_monster=0;
						}
					}
				}
				if(is_monster){
					rj2_perm=x;
					for(int m=i;m<i+3;m++){
						for(int n=j;n<j+20;n++){
							if(monster_s[m-i][n-j]){
								monster[x][m][n]=1;
							}
						}
					}
				}	
			}		
		}
	}
		
	
	
	int rj2_temp=0,rj2;
	for(int x=0;x<4;x++){
		cout<<endl;
		rj2_temp=0;
		for(int i=0;i<water_dim_m;i++){
			for(int j=0;j<water_dim_n;j++){
				if(rj2_perm==x){
					if(monster[x][i][j]){
							cout<<"O";
						}else{
							cout<<".";
						}	
				}
				if(water[x][i][j] and !monster[x][i][j]){
					rj2_temp++;			
				}
			}
			if(rj2_perm==x)	cout<<endl;
		}
		if(rj2_perm==x){
			rj2=rj2_temp;
		}
		
	}
	cout<<"RJ2: "<<rj2<<endl;
	return 0;
}


