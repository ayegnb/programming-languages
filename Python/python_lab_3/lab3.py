from matrix import *
from vector import *
from rational import *

def tests():

    m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
    m2 = Matrix(Rational(-1, 3), Rational(2, 7), Rational(2, 5), Rational(-1, 7))
    m3 = Matrix(Rational(2, 3), Rational(3, 4), Rational(-2, 3), Rational(1, 2))
    v = Vector(5, 6)
    
    print( "The product of two matrices:")
    print( m1 @ m2 )

    print( "----------------------------" )
    print( "The inverse of m1 is:")
    print( m1.inverse() )

    print( "----------------------------" )
    print( "The expression (m1 x m2) x m3 is equal to:" )
    print( (m1 @ m2) @ m3 )
    print( "The expression m1 x (m2 x m3) is equal to:")
    print( m1 @ (m2 @ m3) )
    print( "Matrix multiplication is indeed associative:")
    print( ((m1 @ m2) @ m3) - (m1 @ (m2 @ m3)) )

    print( "----------------------------" )
    print( "The expression m1 x (m2 + m3) is equal to:" )
    print( m1 @ (m2 + m3) )
    print( "The expression m1 x m2 + m1 x m3 is equal to:")
    print( (m1 @ m2) + (m1 @ m3) )
    print( "Matrix multiplication with the addition is indeed distributive:")
    print( (m1 @ (m2 + m3)) - (m1 @ m2 + m1 @ m3) )

    print( "----------------------------" )
    print( "The expression (m1 + m2) x m3 is equal to:")
    print( (m1 + m2) @ m3 )
    print( "The expression m1 x m3 + m2 x m3 is equal to:")
    print( m1 @ m3 + m2 @ m3 )
    print( "Matrix multiplication with the addition is indeed distributive:")
    print( ((m1 + m2) @ m3) - (m1 @ m3 + m2 @ m3) )

    print( "----------------------------" )
    print( "The expression m1(m2(v)) is equal to:")
    print( m1(m2(v)) )
    print( "The expression (m1 x m2)(v) is equal to:")
    print( (m1 @ m2)(v) )
    print( "Matrix multiplication indeed corresponds to composition of application:")
    print( (m1(m2(v))) - ((m1 @ m2)(v)) )

    print( "----------------------------" )
    print( "The expression det(m1) x det(m2) is equal to:")
    print( m1.determinant() * m2.determinant() )
    print( "The expression det(m1 x m2) is equal to:")
    print( (m1 @ m2).determinant() )
    print( "The determinant indeed commutes over multiplication:")
    print( (m1.determinant() * m2.determinant()) - ((m1 @ m2).determinant()) )

    print( "----------------------------" )
    print( "The expression m1 x inv(m1) is equal to identity matrix:")
    print( m1 @ m1.inverse() )
    print( "The expression inv(m1) x m1 is equal to idemtity matrix:")
    print( m1.inverse() @ m1 )
    print( "The inverse of matrix is indeed inverse.")
