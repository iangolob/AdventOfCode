#include <bits/stdc++.h>
using namespace std;

struct rules_s {
   int l1;
   int u1;
   int l2;
   int u2;
};

vector<rules_s> rules;
vector<string> rule_names;

vector<int> your_ticket;
vector<vector<int>> tickets;
vector<vector<int>> valid_tickets;

bool valid_check(int x) {
   bool valid = false;
   for (int i = 0; i < rules.size(); i++) {
      if ((x >= rules[i].l1 and x <= rules[i].u1) or
          (x >= rules[i].l2 and x <= rules[i].u2)) {
         valid = true;
      }
   }
   return valid;
}

bool valid_check_by_rule(int x, int rule_num) {
   return ((x >= rules[rule_num].l1 and x <= rules[rule_num].u1) or
           (x >= rules[rule_num].l2 and x <= rules[rule_num].u2));
}

int main(void) {

   struct rules_s temp;
   string s;
   while (getline(cin, s), s != "") {
      rule_names.push_back(s.substr(0, s.find(':')));
      temp.l1 = stoi(s.substr(s.find(':') + 2, s.find('-') - s.find(':') - 2));
      temp.u1 = stoi(s.substr(
          s.find_first_of('-') + 1,
          s.find(' ', s.find_first_of('-') - s.find_first_of('-') - 1)));
      temp.l2 = stoi(s.substr(s.find_last_of("or") + 2,
                              s.find_last_of("-") - s.find_last_of("or") - 2));
      temp.u2 = stoi(s.substr(s.find_last_of("-") + 1,
                              s.size() - s.find_last_of("-") - 1));
      rules.push_back(temp);
   }

   getline(cin, s);

   char c;
   int inp;
   for (int i = 0; i < rules.size(); i++) {
      cin >> inp;
      your_ticket.push_back(inp);
      if (i != rules.size() - 1) {
         cin >> c;
      }
   }

   getline(cin, s);
   getline(cin, s);
   getline(cin, s);

   vector<int> temp_v;
   while (cin >> inp, inp != 0) {
      for (int i = 1; i < rules.size(); i++) {
         cin >> c;
         temp_v.push_back(inp);
         cin >> inp;
      }
      temp_v.push_back(inp);
      tickets.push_back(temp_v);
      temp_v.clear();
   }
   // zavrsi input s 0

   long long rj1 = 0;
   bool valid;
   for (int i = 0; i < tickets.size(); i++) {
      valid = true;
      for (int j = 0; j < rules.size(); j++) {
         if (!valid_check(tickets[i][j])) {
            rj1 += tickets[i][j];
            valid = false;
         }
      }
      if (valid) {
         valid_tickets.push_back(tickets[i]);
      }
   }

   valid_tickets.push_back(your_ticket);

   long long rj2 = 1;
   bool correct_rule;
   int poz = 0, rule_size = rules.size(), num_of_correct = 0, last_correct = 0;

   int i = 0;
   while (i < rule_size) {
      num_of_correct = 0;
      for (int j = 0; j < rules.size(); j++) {
         correct_rule = true;
         poz = 0;
         do {
            if (!(valid_check_by_rule(valid_tickets[poz][i], j))) {
               correct_rule = false;
            }
            poz++;
         } while (correct_rule and poz < valid_tickets.size());
         if (correct_rule) {
            num_of_correct++;
            last_correct = j;
         }
      }
      if (num_of_correct == 1) {
         if (rule_names[last_correct].find("departure") == 0) {
            rj2 = rj2 * (your_ticket[i]);
         }
         rule_names.erase(rule_names.begin() + last_correct);
         rules.erase(rules.begin() + last_correct);
         i = 0;
      } else {
         i++;
      }
   }

   cout << "RJ1: " << rj1 << endl;
   cout << "RJ2: " << rj2 << endl;

   return 0;
}
