
#ifndef STRING_INCLUDED
#define STRING_INCLUDED 1

#include <iostream>
#include <cstring>

// p is always allocated, and len is the size of the string.
struct string;
std::ostream& operator << ( std::ostream&, const string& );

struct string
{
   size_t len;
   char *p;

   // Default constructor currently switched off.
   // You may switch it on if you want.

   string( )
      : len{0},
        p{nullptr}
   {
      std::cout << "this is the default constructor on a string: " << *this << "\n";
   }

   string( const char* c )
      : len{ strlen(c) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = c[i];
      std::cout << "this is constructor on a string: " << *this << "\n";
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];

      std::cout << "copy constructor on a string: " << *this << "\n";
   }

   string& operator = ( const string& s )
   {
      // Not only for efficiency, but also for assignment:

      if( len != s. len )
      {
         delete[] p;
         p = new char[ s. len ];
         len = s. len;
      }
      for( size_t i = 0; i != len; ++ i )
         p[i] = s.p[i];

      std::cout << "assignment operator on a string: " << *this << "\n";
      return *this;
   }

   ~string( )
   {
      std::cout << "it's the desctructor on a string: " << *this << "\n";

      delete[] p;
   }

   string& operator += ( char c );

   char operator [] ( size_t i ) const;

   char& operator [] ( size_t i );

   size_t size( ) const;

   using iterator = char*;
   using const_iterator = const char*;
   const_iterator begin( ) const { return p; }
   const_iterator end( ) const { return p + len; }
   iterator begin( ) { return p; }
   iterator end( ) { return p + len; }


   string( string&& s ) noexcept
      : len{ s. len },
        p{ s. p }
   {
    s.len = 0;
    s.p = nullptr;
    std::cout << "it's a moving constructor with a string: " << *this << std::endl;
   }

   const string& operator = ( string&& s ) noexcept
   {
       std::swap(p, s. p);
       std::swap(len, s. len);
       std::cout << "it's a moving assignment with a string: " << *this << std::endl;
     return *this;
   }

   void push_back( const string& s);

};

string& operator += ( string& s1, const string& s2 );

std::ostream& operator << ( std::ostream& out, const string& s );

string operator + ( string s1, const string& s2 );
string operator + (const string& s1, const string& s2);

bool operator == ( const string& s1, const string& s2 );
bool operator < ( const string& s1, const string& s2 );
   // add others as inline.

inline bool operator != ( const string& s1, const string& s2 ) {
   if (s1 == s2) return false;
   return true;
}

inline bool operator > ( const string& s1, const string& s2 ) {
   return s2 < s1;
}

inline bool operator <= ( const string& s1, const string& s2 ) {
  if (s1 > s2) return false;
  return true;
}

inline bool operator >= ( const string& s1, const string& s2 ) {
  if (s1 < s2) return false;
  return true;
}

const string& greater( const string& s1, const string& s2 );
#endif
