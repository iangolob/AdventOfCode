#include <bits/stdc++.h>
using namespace std;

int main(void) {

   struct grupa_s {
      bool a['z' - 'a' + 1] = {0};
      bool b['z' - 'a' + 1] = {0};
   } inp;
   vector<grupa_s> grupa;

   char tmp[150];
   int j = 0, i = 0;
   bool prvi;
   bool p['z' - 'a' + 1];

   while (tmp[0] != '0') {
      for (i = 0; i <= 'z' - 'a'; i++) {
         inp.a[i] = 0;
         inp.b[i] = 1;
      }
      while (fgets(tmp, 150, stdin),
             tmp[0] != '\n' and tmp[0] != '0' and tmp[0] != '\0') {
         j = 0;
         for (i = 0; i <= 'z' - 'a'; i++) {
            p[i] = 0;
         }
         while (tmp[j] >= 'a' and tmp[j] <= 'z') {
            inp.a[tmp[j] - 'a'] = 1;
            p[tmp[j] - 'a'] = 1;
            j++;
         }
         if (tmp[0] != '\n' and tmp[0] != '0' and tmp[0] != '\0') {
            for (i = 0; i <= 'z' - 'a'; i++) {
               inp.b[i] = inp.b[i] and p[i];
            }
         }
      }
      grupa.push_back(inp);
   }
   // zavrsi input sa 0

   int rj1 = 0;
   int rj2 = 0;
   for (i = 0; i < grupa.size(); i++) {

      cout << "GRUPA " << i + 1 << ": ";

      for (j = 0; j <= 'z' - 'a'; j++) {
         cout << grupa[i].b[j];
         if (grupa[i].a[j]) {
            rj1++;
         }
         if (grupa[i].b[j]) {
            rj2++;
         }
      }

      cout << endl;
   }
   cout << "RJ1: " << rj1 << endl;
   cout << "RJ2: " << rj2 << endl;
   return 0;
}
