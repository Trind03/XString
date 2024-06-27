import os;
import hashlib
import time

pre_build = "cmake -B ./build -S . -G \"Unix Makefiles\""
build = "cmake --build ./build"
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
        os.system(pre_build)

    elif(checksum != new_checksum):
        print("Change Detected!\n")
        os.system(build)
        time.sleep(1)

    else:
        time.sleep(1)
        
    checksum = new_checksum
