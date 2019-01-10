
#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"


int main( int argc, char* argv [] )
{
#if 0
   std::vector< std::string > vect;
   vect = vectortest::randomstrings( 10, 50 );
   std::cout << vect << "\n";

   auto t1 = std::chrono::high_resolution_clock::now( ); 
   vectortest::sort_std( vect );
   auto t2 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d = ( t2 - t1 );
   std::cout << vect << "\n";

   std::cout << "sorting took " << d. count( ) << " seconds\n";
   return 0;
#endif
   std::list< std::string > vect;
   vect = listtest::randomstrings( 10, 50 );
   std::cout << vect << "\n";


   auto t1 = std::chrono::high_resolution_clock::now( ); 
   listtest::sort_assign( vect );
   auto t2 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d = ( t2 - t1 );

   std::cout << vect << "\n";

   std::cout << "sorting took " << d. count( ) << " seconds\n";

   std::list< std::string > li;
   li = listtest::randomstrings( 10, 50 );
   std::cout << li << "\n";
   
   std::vector<std::string> vectFromLi = listtest::makeVector(li);
   std::cout << vectFromLi << "\n";
   return 0;

}


