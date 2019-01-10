from numbers import *

def gcd(n1, n2) :
    if n1 == 0 and n2 == 0: raise ArithmeticError( "gcd(0,0) does not exist" )
    if n2 == 0: return abs(n1)
    return gcd(n2, n1 % n2)

class Rational( Number ) :
    def __init__( self, num, denum = 1 ) :
        self.num = num
        self.denum = denum
        self.normalize( )

    def normalize(self) :
        if self.denum == 0:
            raise ZeroDivisionError( "you cannot divide by 0" )
        if self.denum < 0:
            self.num = -self.num
            self.denum = -self.denum

        factor = gcd(self.num, self.denum)
        self.num = self.num // factor
        self.denum = self.denum // factor

    def __repr__(self) :
        if self.denum == 1:
            return "{}".format(self.num)
        else:
            return "{}/{}".format(self.num, self.denum)

    def __neg__( self ) :
        return Rational( -self.num, self.denum )

    def __add__( self, other ) :
        if not isinstance(other, Rational):
            return Rational( self.num + self.denum * other, self.denum )
        else:
            return Rational( self.num * other.denum + other.num * self.denum, self.denum * other.denum )

    def __radd__( self, other ) :
        return self.__add__( other )

    def __sub__( self, other ) :
        if not isinstance(other, Rational):
            return Rational( self.num - self.denum * other, self.denum )
        else:
            return Rational( self.num * other.denum - other.num * self.denum, self.denum * other.denum )

    def __rsub__( self, other ) :
        if not isinstance(other, Rational):
            return Rational( other * self.denum - self.num, self.denum )
        else:
            return Rational( other.num * self.denum - self.num * other.denum, self.denum * other.denum )

    def __mul__( self, other ) :
        if not isinstance(other, Rational):
            return Rational( self.num * other, self.denum )
        else:
            return Rational( self.num * other.num, self.denum * other.denum )

    def __rmul__( self, other ) :
        return self.__mul__(other)

    def __truediv__( self, other ) :
        if not isinstance(other, Rational):
            return Rational( self.num, self.denum * other )
        else:
            return Rational( self.num * other.denum, self.denum * other.num )

    def __rtruediv__( self, other ) :
        if not isinstance(other, Rational):
            return Rational( other * self.denum, self.num )
        else:
            return Rational( other.num * self.denum, self.num * other.denum )
