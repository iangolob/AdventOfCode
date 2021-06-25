#include <bits/stdc++.h>
using namespace std;

map<string, vector<pair<int, string>>> has;
map<string, vector<pair<bool, string>>> in;
map<string, bool> p;
int rj1 = 0;

void prop1(string s) {
   for (int i = 0; i < in[s].size(); i++) {
      if (!p[in[s][i].second]) {
         rj1++;
         p[in[s][i].second] = 1;
         //	cout<<in[s][i].second<<endl;
         prop1(in[s][i].second);
      }
   }
   return;
}

int prop2(string s) {
   int r = 0;
   for (int i = 0; i < has[s].size(); i++) {
      r += has[s][i].first * (prop2(has[s][i].second) + 1);
   }
   return r;
}

int main(void) {

   string s, si, sh;

   while (getline(cin, s), s[0] != '0') {

      si = s.substr(0, s.find("bag") - 1);
      s = s.substr(s.find("contain") + 8, s.size() - s.find("contain") - 8);

      sh = s.substr(0, s.find("bag") - 1);
      if (sh[0] != 'n') {
         has[si].push_back(make_pair(sh[0] - '0', sh.substr(2, sh.size() - 2)));
         in[sh.substr(2, sh.size() - 2)].push_back(make_pair(0, si));
         //		cout<<sh<<endl;
         s = s.substr(s.find(',') + 2, s.size() - s.find(','));
         sh = s.substr(0, s.find("bag") - 1);
         if (sh[0] >= '0' and sh[0] <= '9') {
            do {
               if (sh[0] >= '0' and sh[0] <= '9') {
                  has[si].push_back(
                      make_pair(sh[0] - '0', sh.substr(2, sh.size() - 2)));
                  in[sh.substr(2, sh.size() - 2)].push_back(make_pair(0, si));
                  //				cout<<sh<<endl;
                  s = s.substr(s.find(',') + 2, s.size() - s.find(','));
                  sh = s.substr(0, s.find("bag") - 1);
               } else {
                  break;
               }
            } while (s.find(',') >= 0 and s.find(',') <= s.size() or
                     s.size() > 4);
         }
      }
   }
   // zavrsi input sa 0

   prop1("shiny gold");
   cout << "RJ1: " << rj1 << endl;

   cout << "RJ2: " << prop2("shiny gold") << endl;

   return 0;
}
