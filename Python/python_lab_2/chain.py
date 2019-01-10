
from scipy import *
from scipy.linalg import *

# runge_kutta1 is Euler's method:

def runge_kutta1( F, x, h ) : 
   k1 = F( x ) 

   return x + h * k1 


def approx( h = 1.0E-3 ) :
   print( "testing Runge-Kutta methods on the catenary" )

   x0 = 0.0
   x1 = 1.0

   mu = 2.0

   s0 = array( [ 1.0 / mu, 0.0 ] )

   p = s0
   x = x0

   def cat( p ) :
      return array( [ p[1], mu * sqrt( 1.0 + p[1] * p[1] ) ] )

   while x + h < x1 :
      p = runge_kutta1( cat, p, h )
      x += h

   p = runge_kutta1( cat, p, x1 - x )
   x = x1

   print( "h = ", h )
   print( "final value = ", p )

   expected = array( [ cosh( mu * x1 ) / mu, sinh( mu * x1 ) ] )
   error = p - expected

   print( "error = ", error )


