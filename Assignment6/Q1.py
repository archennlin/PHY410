from cpt import *
from math import *
import numpy as np


def f (p) :
    x = p[0]
    y = p[1]
    return -(x * x + y * y)/2 + pow(x * x + y * y, 2.0)/4

def df(p) :
    x = p[0]
    y = p[1]
    x = -x + x * (x * x + y * y)
    y = -y + y * (x * x + y * y)
    return np.array( [x,y] )


print " Minimization using Broyden-Fletcher-Goldfarb-Shanno Algorithm"
print " Find minimum of f(x,y) given an initial guess for x, y"
p = input(" Enter starting point coordinates x y: ")
gtol = input( " Enter desired accuracy: ")
f_min = 0.0
iterations = 0
res = scipy.optimize.fmin_bfgs(f=f, fprime=df,x0=p, gtol=gtol)
print res
print "the partial derivatives of the potential at this point are: [df_x, df_y]=", df(p)

