sudo rm /dev/shm/1145141919810  
sudo perf record -F 99 -g -- $1 --benchmark_filter=$2
sudo perf script > out.perf
sudo chown aoiduo:aoiduo out.perf
~/FlameGraph/stackcollapse-perf.pl ./out.perf > out.flame
~/FlameGraph/flamegraph.pl  --width 2400 ./out.flame > flame.svg
sudo rm /dev/shm/1145141919810  
sudo rm ./out.flame 
sudo rm ./out.perf
sudo rm *.old