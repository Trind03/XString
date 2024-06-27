dist="./"
project_name="XString"
pre_build="cmake -B ../build/$project_name -S ."
build="cmake --build ./build"

checksum=""


while true; do
    new_checksum=$(find "$dist" -type f -exec md5sum {} + | md5sum)

    if [ "$new_checksum" != "$checksum" ]; then
        checksum=$new_checksum
        $pre_build
        $build
    else
        
        sleep 5
    fi
done