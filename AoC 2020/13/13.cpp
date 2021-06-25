#include <bits/stdc++.h>
using namespace std;

vector<long long> id;
long long lcm;

long long lcm_calc(long long n1, long long n2) {
   long long i = 2;
   while (i <= n1 and i <= n2) {
      if (n1 % i == 0 and n2 % i == 0) {
         n1 /= i;
         n2 /= i;
         i = 1;
      }
      i++;
   }
   return n1 * n2;
}

long long next(long long n1, long long n2, int t) {
   long long x = 1;

   while ((n1 + lcm * x + t) % n2 != 0) {
      x++;
   }

   return n1 + lcm * x;
}

int main(void) {
   string s;
   long long time;
   cin >> time;
   getline(cin, s);
   getline(cin, s);

   string temp;
   while (s.find(',') > 0 and s.find(',') <= s.size()) {

      temp = s.substr(0, s.find(","));

      if (temp[0] == 'x') {
         id.push_back(0);
      } else {
         id.push_back(stoi(temp));
      }

      s.erase(0, s.find(",") + 1);
   }
   if (s[0] == 'x') {
      id.push_back(0);
   } else {
      id.push_back(stoi(s));
   }

   long long rj1t = time - 1, rj1ID;
   bool fin = 0;
   do {
      rj1t++;
      for (int i = 0; i < id.size(); i++) {
         if (id[i] != 0) {
            if (rj1t % id[i] == 0) {
               rj1ID = id[i];
               fin = 1;
            }
         }
      }
   } while (!fin);

   cout << "RJ1: " << rj1ID * (rj1t - time) << endl;

   long long rj2 = 0;
   for (int i = 0; i < id.size(); i++) {
      if (i == 0) {

         rj2 = id[0];
         lcm = id[0];

      } else {

         if (id[i] != 0) {
            rj2 = next(rj2, id[i], i);
            lcm = lcm_calc(lcm, id[i]);
         }
      }
   }

   cout << "RJ2: " << rj2 << endl;

   return 0;
}
