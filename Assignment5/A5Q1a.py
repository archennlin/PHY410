from cpt import *
import numpy as np
import matplotlib.pyplot as plt

print " Unbalanced Wheatstone bridge equations"
print " --------------------------------------"

v0 = 1.0
rv = 0.1
r1 = np.arange(0.2, 5.2, 0.2)
R_eff = [0.0]*len(r1)

v = Matrix(6, 1)       # column vector with 6 rows
v[0][0] = v0
print 'v = '
print v 

for j in range(25):

  R = Matrix(6, 6)       # 6x6 resistance matrix
  R[0][0] = r1[j] + rv      # set components using slicing notation
  R[0][1] = rv
  R[0][2] = rv
  R[0][3] = 2.0
  R[0][4] = 1.0
  R[0][5] = 0



  R[1][0] = r1[j] + 1.0
  R[1][1] = 0.0
  R[1][2] = -1.0
  R[1][3] = -1.0
  R[1][4] = 0.0
  R[1][5] = -1.0




  R[2][0] = 0.0      
  R[2][1] = -2.0
  R[2][2] = 2.0
  R[2][3] = 0.0       
  R[2][4] = 1.0
  R[2][5] = -1.0


  R[3][0] = r1[j]     
  R[3][1] = -1.0
  R[3][2] = 0.0
  R[3][3] = 1.0       
  R[3][4] = -1.0
  R[3][5] = 0.0


  R[4][0] = -r1[j] - 1.0   
  R[4][1] = 0.0
  R[4][2] = 0.0
  R[4][3] = 4.0       
  R[4][4] = 1.0
  R[4][5] = -1.0


  R[5][0] = 0.0       # or use subscripting notation
  R[5][1] = -1.0
  R[5][2] = -2.0
  R[5][3] = 1.0       
  R[5][4] = 3.0
  R[5][5] = 2.0

#print 'R = '
#print R

# the solve_Gauss_Jordan replaces R by R^-1 and v by i
# so save the original R and copy v into a vector i
  R_save = Matrix_copy(R)
  i = Matrix_copy(v)

  solve_Gauss_Jordan(R, i)
  

# find the other currents
#print " i_v = i_1 + i_2 + i_3 = " + str(i[0][0] + i[1][0] + i[2][0])

#iv = i[0][0] + i[1][0] + i[2][0]


  R_eff[j] = v0/(i[0][0] + i[1][0] + i[2][0])-rv

print " equivalent resistance using Gauss-Jordan elimination when r1=1(ohms)"
print " equivalent resistance =", R_eff[4] 

plt.plot(r1, R_eff)
plt.show()

# see whether LU decomposition gives the same answer
#i = Vector(v)
#solve_LU_decompose(R_save, i)
#print " Solution using LU Decompositon"
#print " i = "
#print i

