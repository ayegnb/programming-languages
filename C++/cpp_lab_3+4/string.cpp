#include "string.h"

// as usual: Take the functions out one by one when you write them.
char string::operator [] ( size_t i ) const {
  return p[i];
}

char& string::operator [] ( size_t i ) {
  return p[i];
}

size_t string::size( ) const {
    return len;
}

string& string::operator += ( char c ) {

  char *new_string = new char[len+1];
  for ( size_t i = 0; i < len; ++ i)
      new_string[i] = p[i];

  new_string[len] = c;
  len += 1;
  delete[] p;
  p = new_string;

  return *this;
}

string& operator += ( string& s1, const string& s2 ) {
  size_t j = s2.len;
  for ( size_t i = 0; i < j; ++ i)
    s1 += s2[i];

  return s1;
}

string operator + ( string s1, const string& s2 ) {
  s1 += s2;
  return s1;
}

std::ostream& operator << ( std::ostream& out, const string& s )
{
  for( char c : s )
      out << c;

  return out;
}

bool operator == ( const string& s1, const string& s2 ) {
  size_t size;
  if( s1. len != s2. len ) return false;
  if (s1.len < s2.len) {
    size = s1.len;
  } else {
    size = s2.len;
  }

  for ( size_t i = 0; i < size; ++i)
      if (s1[i] != s2[i]) {
        return false;
      }

  return true;
}

bool operator < ( const string& s1, const string& s2 ) {

  for ( size_t i = 0; i < s1. len && i < s2. len; ++i)
      if( s1[i] != s2[i] ) return s1[i] < s2[i];

  return s1. len < s2. len;
}

const string& greater( const string& s1, const string& s2 ) {

  if (s2 > s1) return s2;
  return s1;
}

void string::push_back( const string& s) {

  for (size_t i = 0; i < s.len; ++i){
    *this += s[i];
  }
}

string operator + (const string& s1, const string& s2) {
  string temp = s1;
  temp.push_back(s2);
  return temp;
}
