
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include "string.h"


int main( int argc, char* argv [ ] )
{

  string str = "have a";
  string str2 = " nice";
  string newstr = string("good ") + string("morning");
  std::cout << newstr << "\n";

  std::cout << "-------------" << std::endl;
  string s1 = "Aiya";
  string s2 = "hallo";
  std::swap( s1, s2 );
  std::cout << ( s1 + ", " + s2 ) << "\n";
  std::cout << string( "this is a string" ) << "\n";
  s2 = ( s1 + "!" );

  std::cout << "-------------" << std::endl;
  string zz = "zz";
  std::cout << "before:\n";
  string max = greater( greater( "aa", string( "b" ) + string( "c" )),
  greater( zz, string( "cc" )));
  std::cout << "after:\n";
  std::cout << "max = " << max << "\n";

  string s1 = "good";
  string s2 = " evening";

  std::cout << "Checking operator []:\n";
  std::cout << s1[0] << std::endl;

  std::cout << "Checking operator += with char:\n";
  s1 += 'c';
  std::cout << s1 << "\n";

  std::cout << "Checking operator += with two strings:\n";
  s1 += s1;
  std::cout << s1 << "\n";

  std::cout << "Checking operator +:\n";
  std::cout << s1 + s2 << "\n";

  s1 = "abdef";
  s2 = "abde";

  std::cout << "Checking operator ==:\n";
  if(s1 == s2) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }

  std::cout << "Checking operator <:\n";
  if(s1 < s2) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }

  std::cout << "Checking operator >=:\n";
  if(s1 >= s2) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }
}
