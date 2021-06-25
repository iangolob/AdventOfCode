#include <bits/stdc++.h>
#define TURNS 10000000 //test 100 zad 10000000
#define MAX_CUP 1000000 //test 9 	1000000
using namespace std;


struct node_s{
	int prev;
	int next;
} cup[MAX_CUP+1];

//test 389125467

int main(void){
	int poz=0;
	char c;
	int first=0,previous;
	long long num;
	for(int i=1;i<=MAX_CUP;i++){
		if(i<=9){
			cin>>c;
			num=c-'0';	
		}else{
			num=i;
		}
		if(first==0){
			first=num;
			
		}else{
			cup[previous].next=num;
			cup[num].prev=previous;
		}
		previous=num;
	}
	cup[num].next=first;
	cup[first].prev=num;
			
			
	int current_cup=first,destination_cup;
	int selection[3];
	for(int i=0;i<TURNS;i++){

		//3 cups selection
		for(int j=0;j<3;j++){
			selection[j]=cup[current_cup].next;
			cup[current_cup].next=cup[cup[current_cup].next].next;
		}
		
		//destination cup select
		if(current_cup==1){
			destination_cup=MAX_CUP;
		}else{
			destination_cup=current_cup-1;
		}	
		while(destination_cup==selection[0] or destination_cup==selection[1] or destination_cup==selection[2]){
			if(destination_cup==1){
				destination_cup=MAX_CUP;
			}else{
				destination_cup=destination_cup-1;
			}				
		}	
		
		//cups place
		for(int j=2;j>=0;j--){
			cup[selection[j]].next=cup[destination_cup].next;
			cup[selection[j]].prev=destination_cup;
			
			cup[cup[destination_cup].next].prev=selection[j];
			cup[destination_cup].next=selection[j];
		}
		
		//change current cup
		current_cup=cup[current_cup].next;	
	}


	long long rj2=cup[1].next;
	rj2=rj2*cup[rj2].next;
	cout<<"RJ2: "<<rj2<<endl;
	
	
	return 0;
}
