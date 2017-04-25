from root_finding import *
from math import *

def f ( x ) :
    return tan(x)


print(" Algorithms for root of tan(x)")
print(" ------------------------------------------------")

print(" 1. Simple search")
x0 = -1.2
dx = pi/16
acc = .0001
answer = root_simple(f, x0, dx, acc,1000,True)
print  str ( answer ) 

print " "


print(" 2. Bisection search")
x0 = -pi/4
x1 = pi/6
acc = 0.0001
answer = root_bisection(f, x0, x1, acc,1000,True)
print  str ( answer ) 


