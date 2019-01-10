
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>



std::list< std::string > 
listtest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );
      // More narrowing.

   std::list< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );  
      }

      res. push_back( std::move( rand ));
   }
   return res;
}

std::list<std::string> listtest::readfile( std::istream& input ) 
{
	std::list<std::string> result;
	std::string temp;
	while (input.good()) {
		char c; 
		input.get(c);
		if (isalpha(c)) temp+=c;
		else if (temp.size() != 0) 
		{
			result.push_back(temp);
			temp.clear();
		}		
	}
	return result;
}

void listtest::sort_assign( std::list< std::string > & v ) 
{

	for( std::list<std::string>::iterator i = v.begin(); i != v.end(); ++ i)
	for( std::list<std::string>::iterator j = v.begin(); j != i; ++ j )
	{
        if( *i > *j )
        {
            std::string s = *i;
            *i = *j;
            *j = s;
        }
	}
}


void listtest::sort_move( std::list< std::string > & v ) 
{
	for( std::list<std::string>::iterator j = v.begin(); j != v.end(); ++ j )
	{
	for( std::list<std::string>::iterator i = v.begin(); i != j; ++ i )
	{
	if( *i > *j )
	std::swap(*i, *j);
	}
	}
}

std::vector<std::string> listtest::makeVector(std::list<std::string>& arg) {
    std::vector<std::string> res; 
    for (std::string str : arg)
    {
        res.push_back(str);
    }
    return res;
}

std::ostream& operator << ( std::ostream& out, const std::list< std::string > & vect) 
{
	std::list<std::string>::const_iterator iter = vect.begin();
	out << "{ " << "\"" << *iter << "\"";
	++ iter;
	for (; iter != vect.end(); ++ iter)
	{
	out << ", " << "\"" << *iter << "\"";
	}
	out << " }";
	return out;
}



