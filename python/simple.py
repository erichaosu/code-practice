#!/usr/bin/env python
#coding:utf-8
# function Coins
#    input: centOwed - the amount of change that should be returned - an integer

def tree(layers):
    for i in range(layers+1):
        print(" "*((layers-i))+ "*"*(i+(i-1)))
    return
def trunk(layers):
    for i in range(layers):
        print(" "*(layers-2)+ "*"*3)
        if(i<3):
            continue
        else:
            return
        
tree(5)
trunk(5)
for i in range(10):
    print ("i = %d \n" %i)
"""
def sumOfSquares(num):
    sum = 0
    for i in range(num+1):
        sum = sum + i**2
    print("The sum of Squares is " + str(sum))
    return(sum)
def sumOfCubes(num):
    sum = 0
    for i in range(num+1):
        sum = sum + i**3
    print("The sum of Cubes is " + str(sum))    
    return(sum)
def sumOfSquaresEx(n):
    sum = n*(n+1)*(2*n+1)//6
    print("The explicit sum of Squares is " + str(sum))
    return(sum)
def sumOfCubesEx(num):
    sum = (num**2)*((num+1)**2)//4
    print("The explicit sum of Cubes is " + str(sum))    
    return(sum)
sumOfSquares(5)
sumOfCubes(5)
sumOfSquaresEx(5)
sumOfCubesEx(5)
"""

def listCount(list):
    count = len(list)
    print("list count is " + str(count))
    return(count)


def listAvg(list):
    avg = 0
    for i in range(len(list)):
        avg = avg + list[i]
    return (avg/len(list))


def listStdDev(list):
    #Find the mean of the numbers
    mean = listAvg(list)
    #For each number, find the “squared difference” which is the (number - mean)^2
    for i in range(len(list)):
        list[i] = (list[i]-mean)**2
    avg = listAvg(list)
    print("avg is " + str(avg))

    stdDev = avg**(0.5)
    return(stdDev)

#listStdDev([1, 2, 3, 6, 7, 8])
list = [1,2,3,6,7,8]
listCount(list)
a = listAvg(list)
print ("listAvg = " + str(a))
b = listStdDev(list)

print("listStdDev = " + str(b))

"""
a = input("what's your age?")
after_ten = int(a)+10
print ("you will be "+ str(after_ten) +" years old, after 10 years!")


def Coins(centsOwed):
    #int j = centsOwed;
    quarters = int(centsOwed / 25)
    dimes = int((centsOwed - (quarters * 25) ) / 10)
    nickels = int((centsOwed - (quarters * 25) - (dimes * 10)) /5) 
    pennies = int((centsOwed - (quarters * 25) - (dimes * 10) - (nickels * 5)))
#ode here to calculate quarters, dimes, nickels, pennies based on centsOwed
    # print proper output messages
    # keep all the code indented like these comments
    print("cents =>", centsOwed)
    print("Quarter(s)", quarters)
    print("Dime(s)   ", dimes)
    print("Nickel(s)", nickels)
    print("Penny(s)  ",pennies) 
    return(quarters, dimes, nickels, pennies)
    
Coins(137)
for i in range(1,10):
    print(i)
"""
