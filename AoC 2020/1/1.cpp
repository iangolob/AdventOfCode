#include <bits/stdc++.h>
using namespace std;

int main(void) {
   vector <long long> v;
   long long x;

   while (cin >> x, x != 0) {
      v.push_back(x);
   }
   // upisuje do 0

   for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
         if (v[i] + v[j] == 2020) {
            cout << "RJ1: " << v[i] * v[j] << endl;
         }
      }
   }
	for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
      	for(int k=j+1;k<v.size();k++){
      		if (v[i] + v[j] + v[k] == 2020) {
            cout << "RJ2: " << v[i] * v[j] * v[k] << endl;
         	}
		  } 
      }
   }
   return 0;
}
