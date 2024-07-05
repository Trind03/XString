import os;
import hashlib
import 
PRE_BUILD = "cmake -B ./build -S . -G \"Unix Makefiles\""
BUILD = "cmake --build ./build"
checksum = ""
new_checksum = ""

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
    value = input("Press enter to compile.")
    new_checksum = gethash("./src")
    if(value == ""):
        if(checksum == ""):
            os.system(PRE_BUILD)
            checksum = new_checksum
            
        elif(checksum != new_checksum):
            print("Change Detected!\n")
            os.system(BUILD)

        elif(checksum == new_checksum): print("Source code hasn't changed.")

    elif(value == "Exit" or value == "exit"): exit(0)

    else: continue
    
    os.system("clear")
    checksum = new_checksum
