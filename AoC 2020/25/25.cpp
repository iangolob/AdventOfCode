#include <bits/stdc++.h>
using namespace std;



int main(void){
	long long card_loop_size=0,card_key_cur=1,card_key_inp;
	long long door_loop_size=0,door_key_cur=1,door_key_inp;
	cin>>card_key_inp>>door_key_inp;
	
	while(card_key_cur!=card_key_inp){
		card_key_cur*=7;
		card_key_cur=card_key_cur%20201227;
		card_loop_size++;
	}
	cout<<"card: "<<card_loop_size<<endl;
	
	while(door_key_cur!=door_key_inp){
		door_key_cur*=7;
		door_key_cur=door_key_cur%20201227;
		door_loop_size++;
	}
	cout<<"card: "<<door_loop_size<<endl;
	
	long long encryption_key=1;
	for(long long i=0;i<card_loop_size;i++){
		encryption_key*=door_key_inp;
		encryption_key=encryption_key%20201227;
	//	cout<<encryption_key<<endl;
	}

//	encryption_key*=8;
//		encryption_key=encryption_key%20201227;
	
	
	cout<<"RJ1: "<<encryption_key<<endl;
	return 0;
}
