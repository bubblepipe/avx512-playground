#!/usr/bin/python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys

filename = sys.argv[1]
size = int(sys.argv[2])

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



fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_xlabel("row")
ax.set_ylabel("col")
ax.set_zlabel("time (ns)")

color_iter = iter(['slateblue', 'crimson', 'lightseagreen', 'darkred'])

for bench_name, bench_vals in d.items():
    color = next(color_iter)
    print(f"{bench_name} {color}")

    rows = []
    cols = []
    z = []
    for (row,col), (cpu_time,count) in bench_vals.items():
        print(f"{row} {col} {cpu_time} {count}")
        rows.append(row)
        cols.append(col)
        z.append(cpu_time)

    if len(d) == 1:
        ax.scatter(xs = rows, ys = cols, zs = z,)
        for i in range(0,size):
            start, end = size*i, size*(i+1)
            line = z[start:end]
            linewidth = 1 if sorted(line) == line else 4
            ax.plot(rows[start:end],cols[start:end],line, linewidth=linewidth)
        for i in range(0,size):
            line = z[i::size]
            linewidth = 1 if sorted(line) == line else 4
            ax.plot(rows[i::size],cols[i::size],line, linewidth=linewidth )

    else: 
        ax.scatter(xs = rows, ys = cols, zs = z, color=color, label=bench_name)
        for i in range(0,size):
            start, end = size*i, size*(i+1)
            line = z[start:end]
            ax.plot(rows[start:end],cols[start:end],line, color=color)
        for i in range(0,size):
            line = z[i::size]
            ax.plot(rows[i::size],cols[i::size],line,  color=color)

ax.legend()
ax.set_title(filename)
plt.show()