import os;
import hashlib
import sys
from time import sleep

PRE_BUILD = "cmake -B ./build -S . -G \"Unix Makefiles\""
BUILD = f"cmake --build ./build --config {sys.argv[1]}"
checksum = ""
new_checksum = ""
init = False

def hash_txt(text,algorithm="sha256"):
    hash = hashlib.new(algorithm)
    byte_block = text.encoding('utf-8')
    hash.update(byte_block)

    return hash.hexdigest()
    

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

os.system(PRE_BUILD)
os.system(BUILD)
checksum = ""

while(True):
    sleep(4)
    total_hash = gethash("./src") + gethash("./testing")
    hash.update(total_hash)
    new_checksum = hash.hexdigest()
    print(new_checksum)


    if(checksum == ""): checksum = new_checksum

        
    elif(checksum != new_checksum):
        print("Change Detected!\n")
        os.system(BUILD)
        checksum = new_checksum

    elif(checksum == new_checksum): continue


    else: checksum = new_checksum
