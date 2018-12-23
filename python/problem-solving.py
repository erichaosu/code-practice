#O(n) n is the number of digit
def reverse(num):
    result =0
    negative = False
    if num == 0:
        return num    
    if num < 0:
        negative = True
        num = -num

    while num > 0:
        digit = num % 10
        num = num //10
        result = result * 10 + digit
    if negative == True:
        result = -result
    return result

#find unique num in a list O(n) = nxn
def find_unique(num):
    """ find unique number in a list
    num: a number 
    O(n) is nxn 
    """
    result = []
    if len(num) == 1:
        result.append(num[0])
    for i in range (len(num)):
        unique_num = num[i]
        unique = False
        for j in range (len(num)):
            if j == i:
                continue
            else:
                if (unique_num ^ num[j]== 0):
                    unique = False
                    break
                else:
                    unique = True
        if unique:
            result.append(unique_num)
    return result

if __name__ == '__main__':
    #number = input()
    #print("reverse({0}) = {1}".format(number,reverse(int(number))))
    list = [1,2,2,3,4,5,4,6,6,1]
    print("unique num in list are ", find_unique(list))