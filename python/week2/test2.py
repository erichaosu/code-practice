#!/usr/bin/env python
'''
 Create a list of five IP addresses.

Use the .append() method to add an IP address onto the end of the list. Use the .extend() method to add two more IP addresses to the end of the list.

Use list concatenation to add two more IP addresses to the end of the list.

Print out the entire list of ip addresses. Print out the first IP address in the list. Print out the last IP address in the list.

Using the .pop() method to remove the first IP address in the list and the last IP address in the list.

Update the new first IP address in the list to be '2.2.2.2'. Print out the new first IP address in the list.
'''
ip_addr = []
ip_addr.append("10.10.10.10")
ip_addr.extend(["20.20.20.20","30.30.30.30"])
ip_addr = ip_addr + ["40.40.40.40","50.50.50.50"]
print (ip_addr)
print ("\n")
print (ip_addr[0])
print (ip_addr[-1])
ip_addr.pop()
ip_addr.pop(0)
print ("\n")
print (ip_addr)
ip_addr[0] = "2.2.2.2"
print (ip_addr)