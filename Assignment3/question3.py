import matplotlib.pyplot as plt

from fft import fft
from fft import ifft
from fft import fft_power
from numpy import array, real
import math
import time

# define a function to linear fit x-y data without error bars
def least_squares_fit(x, y):
    """Perform a least-squares fit to data (x,y)

    Args :
       x : x values
       y : y values

    Returns :
       a : intercept
       b : slope
       sigma : total uncertainty (sqrt(variance/(n-2)))
       sigma_a : uncertainty on a
       sigma_b : uncertainty on b

    """
    n = len(x)
    s_x  = sum(x)
    s_y  = sum(y)
    s_xx = sum(x_i**2 for x_i in x)
    s_xy = sum(x[i]*y[i] for i in range(n))
    denom = n * s_xx - s_x**2
    if abs(denom) > 0.00001 : 
        a = (s_xx * s_y - s_x * s_xy) / denom
        b = (n * s_xy - s_x * s_y) / denom
        variance = sum((y[i] - (a + b*x[i]))**2 for i in range(n))
        sigma = math.sqrt(variance/(n-2))
        sigma_a = math.sqrt(sigma**2 * s_xx / denom)
        sigma_b = math.sqrt(sigma**2 * n / denom)
        return [a, b, sigma, sigma_a, sigma_b]
    else :
        print 'error : divided by zero!'
        return None

print ' least_squares fit to data:'
print ' C02 Data from Mauna Loa'

data_file_name = 'co2_mm_mlo.txt'
file = open(data_file_name, 'r')
lines = file.readlines()
file.close()
data = [ str.split(line) for line in lines if line[0] != '#' ]
print ' read', len(lines), 'lines from', data_file_name


x_data = [float(datum[2]) for datum in data]
y_data = [float(datum[4]) for datum in data]


fit = least_squares_fit(x_data, y_data)
print ' slope =', fit[1], ' +- ', fit[4]
print ' intercept =', fit[0], '+-', fit[3]



plotfirst = False 

if plotfirst == True : 
    # make some fake data as a single-frequency sinusoid

    N = 1024      # number of samples
    f = 10.0      # frequency / N
    m = 0.00      # linear slope, if desired

    # For demonstrations : 
    clip = 0      # "clip" so we can pad with zeros
    window = False # window or not? 
    
    
    x = array([ float(i) for i in xrange(N) ] )
    if window : 
        y = array([ math.sin(-2*math.pi*f* xi / float(N)) *(0.5 - 0.5 * math.cos(2*math.pi*xi/float(N-1)))  + m*xi  for xi in x ])
    else :
        y = array([ math.sin(-2*math.pi*f* xi / float(N)) + m*xi  for xi in x ])

    for i in range(N-clip, N) :
        y[i] = 0.0

    start_time = time.time()
    Y = fft(y)
    print time.time() - start_time, " seconds" 

    powery = fft_power(Y)
    powerx = array([ float(i) for i in xrange(len(powery)) ] )


    Yre = [math.sqrt(Y[i].real**2 + Y[i].imag**2) for i in xrange(N)]

    s1 = plt.subplot(2, 1, 1)
    plt.plot( x, y )

    s2 = plt.subplot(2, 1, 2)
    s2.set_autoscalex_on(False)
    p1, = plt.plot( powerx, powery )
    p2, = plt.plot( x, Yre )
    s2.legend( [p1, p2], ["Power", "Magnitude"] )
    plt.xlim([0,N/4])
    plt.yscale('log')
    plt.show()


else : 
    # data downloaded from ftp://ftp.cmdl.noaa.gov/ccg/co2/trends/co2_mm_mlo.txt
    print ' C02 Data from Mauna Loa'
    data_file_name = 'co2_mm_mlo.txt'
    file = open(data_file_name, 'r')
    lines = file.readlines()
    file.close()
    print ' read', len(lines), 'lines from', data_file_name

    window = False

    yinput = []
    xinput = []

    for line in lines :
        if line[0] != '#' :
            try:
                words = line.split()
                xval = float(words[2])
                yval = float( words[4] )
                yinput.append( yval )
                xinput.append( xval )
            except ValueError :
                print 'bad data:',line


    N = len(yinput)
    log2N = math.log(N, 2)
    if log2N - int(log2N) > 0.0 :
        print 'Padding with zeros!'
        pads = [0.0] * (pow(2, int(log2N)+1) - N)
        yinput = yinput + pads
        N = len(yinput)
        print 'Padded : '
        print len(yinput)
        # Apply a window to reduce ringing from the 2^n cutoff
        if window : 
            for iy in xrange(len(yinput)) :
                yinput[iy] = yinput[iy] * (0.5 - 0.5 * math.cos(2*math.pi*iy/float(N-1)))

    y = array( yinput ) 
    x = array([ float(i) for i in xrange(len(y)) ] )
    y_f = y - ( fit[1]*(0.075*x+1958.2) + fit[0] )
    Y = fft(y_f)
    
    

maxfreq = 50
# Now smooth the data
for iY in range(maxfreq, len(Y)-maxfreq ) :
    Y[iY] = complex(0,0)
    #Y[iY] = Y[iY] * (0.5 - 0.5 * math.cos(2*math.pi*iY/float(N-1))) 

    #for iY in range(0,N) : 
    #    Y[iY] = Y[iY] * math.exp(-1.0*iY / 50.0)

powery = fft_power(Y)
powerx = array([ float(i) for i in xrange(len(powery)) ] )

Yre = [math.sqrt(Y[i].real**2+Y[i].imag**2) for i in xrange(len(Y))]

ysmoothed = ifft(Y)
ysmoothedreal = real(ysmoothed) + ( fit[1]*(0.075*x+1958.2) + fit[0] )

ax1 = plt.subplot(2, 1, 1)
p1, = plt.plot( x, y )
p2, = plt.plot( x, ysmoothedreal )
ax1.legend( [p1,p2], ['Original', 'Smoothed'] )

ax2 = plt.subplot(2, 1, 2)
p3, = plt.plot( powerx, powery )
p4, = plt.plot( x, Yre )
ax2.legend( [p3, p4], ["Power", "Magnitude"] )
plt.yscale('log')


plt.show()
