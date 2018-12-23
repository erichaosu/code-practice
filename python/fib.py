# fibonacci number module


def fib(n):  #output fibonacci number serial up to n
    a, b = 0,1
    count = 0
    while (a < n):
        print (a, end=' ')
        a,b = b, a+b
        count = count +1
    print ("\n it has " + str(count) +" fibonacci numbers ")

def fib2(n):
    result = []
    a,b = 0, 1
    while (a < n):
        result.append(a)
        a,b = b, a+b
    return result

def sum_naturals(n):
    """Return the sum of the first n natural numbers
    >>> sum_naturals(10)
    55
    >>> sum_naturals(100)
    5051
    """
    total, k = 0, 1
    while k <= n:
        total, k = total + k, k + 1
    return total

if __name__ == "__main__":
    import sys
    print ("print something {0} {1}".format(sys.argv[0], sys.argv[1]))
    fib(int(sys.argv[1]))
