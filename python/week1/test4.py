#!/usr/bin/env python
'''
 Create a show_version variable that contains the following

 show_version = "*0        CISCO881-SEC-K9       FTX0000038X    "

Remove all leading and trailing whitespace from the string.

Split the string and extract the model and serial_number from it.

Check if 'Cisco' is contained in the model string (ignore capitalization).

Check if '881' is in the model string.

Print out both the serial number and the model.
'''
show_version = "*0        CISCO881-SEC-K9       FTX0000038X    "
version = show_version.strip()
version = version.split()
model = version[1]
serial_num = version[2]

print ("is CISCO contained in model? {}".format("CISCO" in model))
print ("is 881 contained in model? {}".format("881" in model))
print("model = {}".format(model))
print("serial number = {}".format(serial_num))
print (f"My model number is:  {model:>20}")
print (f"My serial number is:  {serial_num:>20}")

