import os
import re

bo_header = os.getcwd() + "/bo.h"
cs_native = os.getcwd() + "/output/Native.cs"

print bo_header;

sets_array = []
gets_array = []
util_array = []

def parse_bo_lib():
    with open(bo_header, 'r') as content_file:
        for line in content_file:
            if line != "\n":
                if "Add" in line or "Get" in line:
                    gets_array.append(line)
                elif "Clear" in line or "Set" in line:
                    sets_array.append(line)
                    print line
                else:
                    util_array.append(line)
        

            



#def write_cs_native():


#def write_cpp_source():
    

#def write_cpp_header():



parse_bo_lib()
