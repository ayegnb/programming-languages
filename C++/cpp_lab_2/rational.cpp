#include "rational.h"
#include <cstdlib>

// Complete these methods:

int rational::gcd( int n1, int n2 )
{
  if (n2 == 0)
      return n1;
  return rational::gcd( n2, n1 % n2 );
}

void rational::normalize( )
{

  if (denum == 0)
      throw "Cannot divide by 0";

  int factor = rational::gcd(num, denum);
  num = num / factor;
  denum = denum / factor;

  if (denum < 0)
  {
      num = -num;
      denum = -denum;
  }
}

rational operator - ( rational r )
{
  return rational( -r.num, r.denum);
}

rational operator + ( const rational& r1, const rational& r2 )
{
  return rational( r1.num * r2.denum + r2.num * r1.denum, r1.denum * r2.denum);
}

rational operator - ( const rational& r1, const rational& r2 )
{
  return rational( r1.num * r2.denum - r2.num * r1.denum, r1.denum * r2.denum);
}

rational operator * ( const rational& r1, const rational& r2 )
{
  return rational( r1.num * r2.num, r1.denum * r2.denum );
}

rational operator / ( const rational& r1, const rational& r2 )
{
  return rational( r1.num * r2.denum, r2.num * r1.denum);
}

bool operator == ( const rational& r1, const rational& r2 )
{
  return r1.num == r2.num && r1.denum == r2.denum;
}

bool operator != ( const rational& r1, const rational& r2 )
{
  return r1.num != r2.num || r1.num != r2.num;
}

std::ostream& operator << ( std::ostream& out, const rational& r )
{
  if (r.denum == 1)
      out << r.num;
  else
      out << r.num << "/" << r.denum;
  return out;
}
