"""
Following algorithm requires working with strings and numbers
therefore python was used as it makes the process significantly simpler
"""
def ceil(x):
  return int(x) + (x > int(x))

def floor(x):
  return int(x) - (x < int(x))

def karatsuba(x,y):
    #single digit -> base case
    if x < 10 and y < 10: 
        return x*y

    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)   

    # left and right values of x
    x_H  = floor(x / 10**m)
    x_L = x % (10**m)

    # left and right values of y
    y_H = floor(y / 10**m)
    y_L = y % (10**m)

    # intermediate variables
    a = karatsuba(x_H,y_H)
    d = karatsuba(x_L,y_L)
    e = karatsuba(x_H + x_L, y_H + y_L) - a - d

    # base algorithm
    return int(a*(10**(m*2)) + e*(10**m) + d)

print("Apurva Mishra 22BCE2791")
a = int(input())
b = int(input())
print("Product: ", karatsuba(a, b))
