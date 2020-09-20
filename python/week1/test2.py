#!/usr/bin/env python
'''
Prompt a user to enter in an IP address from standard input. Read the IP address in and break it up into its octets. Print out the octets in decimal, binary, and hex.

Your program output should look like the following:

​ $ python exercise2.py
Please enter an IP address: 80.98.100.240

    Octet1         Octet2         Octet3         Octet4
------------------------------------------------------------
      80             98             100            240
   0b1010000      0b1100010      0b1100100     0b11110000
     0x50           0x62           0x64           0xf0
------------------------------------------------------------
'''
from __future__ import print_function
try:
    ip_addr1 = raw_input("please enter an IP address:")
except NameError:
    ip_addr1 = input("please enter an IP address:")
ip_addr = ip_addr1.split(".")
print("\n")
print ("{:^16}{:^16}{:^16}{:^16}".format("Octet1","Octet2","Octet3","Octet4"))
print ("-"*80)

print ("{:^16}{:^16}{:^16}{:^16}".format(*ip_addr))
print ("{:^16}{:^16}{:^16}{:^16}".format(bin(int(ip_addr[0])),bin(int(ip_addr[1])),bin(int(ip_addr[2])),bin(int(ip_addr[3]))))
print ("{:^16}{:^16}{:^16}{:^16}".format(hex(int(ip_addr[0])),hex(int(ip_addr[1])),hex(int(ip_addr[2])),hex(int(ip_addr[3]))))
print ("-"*80)



