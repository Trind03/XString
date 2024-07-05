import os;
import hashlib
import sys

PRE_BUILD = "cmake -B ./build -S . -G \"Unix Makefiles\""
BUILD = f"cmake --build ./build --config {sys.argv[1]}"
checksum = ""
new_checksum = ""
init = False

def gethash(path):
    hash = hashlib.md5()
    for root,dist,files in os.walk(path):
        for file in sorted(files):
            file_path = os.path.join(root,file)
            try:
                with open(file_path,'rb') as f:
                    while block := f.read(4):
                        hash.update(block)
            except Exception as e:
                print(f"Error cannot read {file_path}")
    return hash.hexdigest()

while(True):
    value = input("> ")
    new_checksum = gethash("./src")
    if(value == ""):
        if(checksum != new_checksum or init):
            print("Change Detected!\n")
            os.system(BUILD)
            checksum = new_checksum
            
        elif(checksum != new_checksum or init):
            os.system(PRE_BUILD)
            init = True

        elif(checksum == new_checksum):
            os.system("clear")
            print("Source code hasn't changed.")

    elif(value == "Exit" or value == "exit"): exit(0)

    else: checksum = new_checksum
