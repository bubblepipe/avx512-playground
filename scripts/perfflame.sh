./scripts/run-benchmark.sh src/bench_mat/bench_flat_mat.cpp -DFMAM
sudo rm /dev/shm/1145141919810  
sudo perf record -F 99 -g -- /tmp/bench --benchmark_filter=bench_matrix_flatvector/fma_manual/128/128
sudo perf script > out.perf
sudo chown aoiduo:aoiduo out.perf
~/FlameGraph/stackcollapse-perf.pl ./out.perf > out.flame
~/FlameGraph/flamegraph.pl --width 4800 ./out.flame > flat128.svg 

./scripts/run-benchmark.sh src/bench_mat/bench_matrix_vectorvector.cpp -DFMAM
sudo rm /dev/shm/1145141919810  
sudo perf record -F 99 -g -- /tmp/bench --benchmark_filter=bench_matrix_vectorvector/fma_manual/128/128
sudo perf script > out.perf
sudo chown aoiduo:aoiduo out.perf
~/FlameGraph/stackcollapse-perf.pl ./out.perf > out.flame
~/FlameGraph/flamegraph.pl  --width 2400 ./out.flame > vv128.svg 


./scripts/run-benchmark.sh src/bench_mat/bench_matrix_vectorvector.cpp -DFMAM
sudo perf record --call-graph dwarf -o vv_128.perf  /tmp/bench --benchmark_filter=bench_matrix_vectorvector/fma_manual/128/128 
sudo perf report --call-graph -i vv_128.perf


./scripts/run-benchmark.sh src/bench_mat/bench_flat_mat.cpp -DFMAM
sudo perf record --call-graph dwarf -o flat128.perf  /tmp/bench --benchmark_filter=bench_matrix_flatvector/fma_manual/128/128
sudo perf report --call-graph -i flat128.perf

./scripts/run-benchmark.sh src/bench_mat/bench_matrix_vectorvector.cpp -DFMAM
sudo perf record --call-graph fp -o vv_128.perf  /tmp/bench --benchmark_filter=bench_matrix_vectorvector/fma_manual/128/128 
sudo perf report --call-graph -i vv_128.perf -G

./scripts/run-benchmark.sh src/bench_mat/bench_flat_mat.cpp -DFMAM
sudo perf record --call-graph fp -o flat128.perf  /tmp/bench --benchmark_filter=bench_matrix_flatvector/fma_manual/128/128
sudo perf report --call-graph -i flat128.perf -G

