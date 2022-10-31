#include <iostream>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t);

int main(int argc, char const *argv[]) {
  string s1 = "egg", t1 = "add";
  string s2 = "foo", t2 = "bar";
  string s3 = "paper", t3 = "title";
  string s4 = "badc", t4 = "baba";

  cout << isIsomorphic(s1, t1) << endl;
  cout << isIsomorphic(s2, t2) << endl;
  cout << isIsomorphic(s3, t3) << endl;
  cout << isIsomorphic(s4, t4) << endl;

  return 0;
}

// checks if the 2 strings s and t are isomorphic
bool isIsomorphic(string s, string t) {
  // if the 2 strings are of unequal length,
  // they are not isomorphic
  if (s.length() != t.length())
    return false;

  map<char, char> letters;

  cout << "length of string: " << s.length() << endl;

  for (int i = 0; i < s.length(); i++) {
    cout << s[i] << ":" << t[i];

    if (s[i] != t[i]) {
      cout << " unequal";
      // check if charecter is in the map
      if (letters.count(s.at(i))) {
        // character was found in map
        cout << " found in map as " << letters[s.at(i)];
        if (letters[s.at(i)] == t.at(i)) {
          cout << " OK";
        } else {
          cout << " ERROR\n";
          return false;
        }
      } else {
        // charecter was not found in the map
        // so we are going to add it to the map
        letters[s.at(i)] = t.at(i);
        cout << " OK";
      }
    } else {
      // add the character to the map
      letters[s.at(i)] = t.at(i);
      cout << " OK";
    }

    cout << endl;
  }

  // cout << endl;
  return true;
}
