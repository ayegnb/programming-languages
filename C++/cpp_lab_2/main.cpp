
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{

   rational r1( 2, 6 );
   rational r2( 4, 3 );
   rational r3( 5, 6 );
   rational r4( 1, 2 );

   matrix m1 = { { {1,2}, {-2,7} }, { {1,3}, {2,8} } };
   std::cout << m1 << "\n";

   matrix m2 = { { {-1,3}, {2,5} }, { { 2,7 }, { -1,7 } } };
   std::cout << m2 << "\n";

   std::cout << m1 * m2 << "\n";
   std::cout << m1. inverse( ) << "\n";

   matrix m3 = { { 4,5}, { -1, 2 }};

   std::cout << m1. determinant( ) << "\n";

   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";

   std::cout << "Matrix multiplication is associative:\n";
   std::cout << "(m1.m2).m3:\n";
   std::cout << m1 * m2 * m3 << "\n";
   std::cout << "(m1.(m2.m3):\n";
   std::cout << m1 * (m2 * m3) << "\n";

   std::cout << "Inverse of matrix is indeed inverse:\n";
   std::cout << "m.inv(m) = I\n";
   std::cout << m1 * m1. inverse() << "\n";
   std::cout << "inv(m).m = I\n";
   std::cout << m1. inverse() * m1 << "\n";
}
