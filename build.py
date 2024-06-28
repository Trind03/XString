import os;
import hashlib
import time

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

    new_checksum = gethash("./src")
    if(checksum == ""):
        os.system(PRE_BUILD)

    elif(checksum != new_checksum):
        print("Change Detected!\n")
        os.system(BUILD)
        time.sleep(0.3)

    else:
        time.sleep(0.3)
        
    checksum = new_checksum
