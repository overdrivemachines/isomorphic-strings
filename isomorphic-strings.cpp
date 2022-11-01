#include <iostream>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t);

int main(int argc, char const *argv[]) {
  string s1 = "egg", t1 = "add";      // true
  string s2 = "foo", t2 = "bar";      // false
  string s3 = "paper", t3 = "title";  // true
  string s4 = "badc", t4 = "baba";    // false
  string s5 = "paper", t5 = "title";  // true

  cout << isIsomorphic(s1, t1) << endl;
  cout << isIsomorphic(s2, t2) << endl;
  cout << isIsomorphic(s3, t3) << endl;
  cout << isIsomorphic(s4, t4) << endl;
  cout << isIsomorphic(s5, t5) << endl;  // expected: true

  return 0;
}

// checks if the 2 strings s and t are isomorphic
bool isIsomorphic(string s, string t) {
  // if the 2 strings are of unequal length,
  // they are not isomorphic
  if (s.length() != t.length())
    return false;

  map<char, char> letters;
  map<char, char>::iterator it;

  cout << "length of string: " << s.length() << endl;

  char s_letter, t_letter;

  bool keyFound = false, valueFound = false;

  for (int i = 0; i < s.length(); i++) {
    s_letter = s.at(i);
    t_letter = t.at(i);

    cout << s_letter << ":" << t_letter << endl;

    // Check if s_letter is already a key in the map
    if (letters.count(s_letter)) {
      // verify t_letter is the value. If not the words are not isomorphic
      if (letters[s_letter] != t_letter)
        return false;
    } else {
      // s_letter was not found in the map as a key

      // Check if t_letter is already a value in the map
      // if it is, the word is not isomorphic because
      // two different s_letters cannot map to the same t_letter
      for (it = letters.begin(); it != letters.end(); it++) {
        if (it->second == t_letter) {
          return false;
        }
      }

      // t_letter was not found as a value in the map
      // add s_letter to the map with value t_letter
      letters.insert(std::pair<char, char>(s_letter, t_letter));
    }
  }

  // cout << endl;
  return true;
}
