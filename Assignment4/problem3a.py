from root_finding import *
from math import *

def f ( x ) :
    return tan(x)

def fp ( x ) :
    return 1/(cos(x)*cos(x))

def g ( x ) :
    return tanh(x)

def gp ( x ) :
    return 1/(cosh(x)*cosh(x)) 


print(" 1. tan")
x0 = float ( input(" Enter initial guess x_0 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_tangent(f, fp, x0, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" 2. tanh")
x0 = float ( input(" Enter initial guess x_0 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_tangent(g, gp, x0, acc,1000,True)
print  str ( answer ) + "\n\n"



