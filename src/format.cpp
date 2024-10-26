#include "format.h"

using std::string;
using std::vector;

const int ONE_MINUE = 60;
const int ONE_HOUR = ONE_MINUE * 60;

string Format::ElapsedTime(long seconds) {
  char buffer[16];
  int hour, min;
  int sec = seconds;

  hour = sec / ONE_HOUR;
  sec %= ONE_HOUR;
  min = sec / ONE_MINUE;
  sec %= ONE_MINUE;

  sprintf(buffer, "%.2d:%.2d:%.2d", hour, min, sec);

  return string(buffer);
}

vector<string> Format::split(const string& serialized_str,
                             const string& delimiter) {
  vector<string> tokens;
  size_t pos = 0;
  string s = serialized_str;

  while ((pos = s.find(delimiter)) != string::npos) {
    string token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  tokens.push_back(s);

  return tokens;
}