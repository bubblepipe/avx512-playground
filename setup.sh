git submodule update --init --recursive
cd benchmark
cmake -E make_directory "build"
cmake -E chdir "build" cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release -j$(nproc) ../
cmake --build "build" --config Release -j$(nproc) 
cd ..