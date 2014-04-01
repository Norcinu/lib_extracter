import os

bo_header = os.getcwd() + "/bo.h"
cs_native = os.getcwd() + "/output/Native.cs"

prefix = "Bo_"
outputs = ['BoLibGetValues', 'BoLibSetValues', 'BoLibGeneral']
extensions = ['.cpp', '.h']

sets_array = []
gets_array = []
util_array = []

def parse_bo_lib():
    with open(bo_header, 'r') as content_file:
        for line in content_file:
            if line != "\n":
                if "Add" in line or "Get" in line:
                    index = get_index("Add", "Get", line) #TODO: handle #defines!
                    if index != -1:
                        gets_array.append(create_final_name(line, prefix, index))
                elif "Clear" in line or "Set" in line:
                    index = get_index("Clear", "Set", line) #TODO: handle defines!
                    if index != -1:
                        sets_array.append(create_final_name(line, prefix, index))
                elif test_other_cases(line) == 1:
                    print line
                    util_array.append(create_final_name(line))
        

# this is absolutely disgusting.
def test_other_cases(line):
    if "#define" not in line and "#ifndef" not in line and "#include" not in line and "#endif" not in line and line.startswith(b'//', 0, 2) == False and line.startswith(b'/*', 0, 2) == False:
        return 1
    else:
        return -1


def get_index(first, second, the_string):
    index = the_string.find(first)
    if index != -1:
        return index
    else:
        return the_string.find(second)


def create_final_name(func_name, lib_prefix="", index=0):
    return func_name[:index] + lib_prefix + func_name[index:]

#def write_cs_native():


#def write_cpp_source():
    

def write_cpp_header(out_index, ext_index, contents):
    header = os.getcwd() + "/output/" + outputs[out_index] + extensions[ext_index] 
    print header
    with open(header, 'w') as header_file:
        header_file.write("#define DllExport __declspec(dllexport)")
        header_file.write("\n\n")
        for s in contents:
            header_file.write("extern \"C\" DllExport\t " + s)
    


def main():
    parse_bo_lib()
    write_cpp_header(0, 1, gets_array)
    write_cpp_header(1, 1, sets_array)
    write_cpp_header(2, 1, util_array)

if __name__ == "__main__":
    main()
