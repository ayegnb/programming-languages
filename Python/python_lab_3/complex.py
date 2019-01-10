
class Complex :

   def __init__( self, re = 0, im = 0 ) :
      self. re = re 
      self. im = im 

   def __str__( self ) : 
      if self.im == 0:
         return str( self.re )
     
      if self.re == 0: 
         return "{}i". format( self.im )

      if self. im == 1 :
         return "{} + i". format( self. re )
      if self. im == -1 :
         return "{} - i". format( self. re )

      if self. im > 0: 
         return "{} + {}i". format( self.re, self.im ) 
      else:
         return "{} - {}i". format( self.re, -self.im )  

   def __repr__( self ) : 
      return "Complex( " + str( self. re ) + ", " + str( self. im )  + " )"

   def __neg__( self ) :
      return Complex( - self. re, - self. im ) 
      
   def __add__( self, other ) :
      if not isinstance( other, Complex ) :
         return Complex( self. re + other, self. im )
      else: 
         return Complex( self. re + other. re, self. im + other. im )

   def __radd__( self, other ) :
      return self. __add__( other )
 
   def __mul__( self, other ) :
      if not isinstance( other, Complex ):
         other = Complex( other, 0 ) 
      return Complex( self. re * other. re - self. im * other. im,
                      self. re * other. im + self. im * other. re )

   def __rmul__( self, other ) :
      return Complex( other * self. re, other * self. im ) 


