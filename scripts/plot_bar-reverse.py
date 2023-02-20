#!/usr/bin/python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys
import numpy as np

filename = sys.argv[1]
# size = int(sys.argv[2])

f = open(filename, "r")
xs = f.readlines()

d = {}

REPEAT_COUNT = 2

for x in xs:
    if '-' in x:
        pass
    elif x.startswith('Benchmark'):
        pass
    elif x == '\n':
        pass
    else:
        cpu_time = float(x.split()[3]) # ['bench_matrix_flatvector/add/16/16', '198', 'ns', '198', 'ns', '3414984']
        xx = x.split()[0].split('/') # ['bench_matrix_flatvector', 'add', '16', '16']
        bench_name = f'{xx[0]}/{xx[1]}'
        row = float(xx[2])
        col = float(xx[3])
        if not (bench_name in d):
            d[bench_name] = {}
        if (row,col) in d[bench_name]:
            prev_avg,prev_count = d[bench_name][row,col]
            new_avg = (prev_avg * prev_count + cpu_time) / (prev_count + 1)
            d[bench_name][row,col] = (new_avg,prev_count + 1)
        else:
            d[bench_name][row,col] = (cpu_time,1)

color_iter = iter(['slateblue', 'crimson', 'lightseagreen', 'darkred'])

fig, ax = plt.subplots(figsize =(16, 9))

barWidth = 0.2
xss = []
xss.append(np.arange(3))
yss = []
xlabel = ['col size 8','col size 16','col size 32']

for bench_name, bench_vals in d.items():
    color = next(color_iter)
    print(f"{bench_name} {color}")

    xss.append([x + barWidth for x in xss[-1]])
    ys = []
    for (row,col), (cpu_time,count) in bench_vals.items():
        ys.append(cpu_time)
    yss.append(ys)

for (xs,ys) in zip(xss,yss):
    ax.bar(xs,ys, width=barWidth)


# exit(0)

print(xlabel)

plt.xticks([ x+0.5*barWidth for x in xss[1]], list(xlabel), fontsize="x-large")
ax.set_ylabel("time (ns), lower is better", fontsize="x-large")
ax.legend(labels=['int16', 'int32', 'float', 'double'], fontsize="x-large")
ax.set_title(filename, fontsize="xx-large")
plt.show()
