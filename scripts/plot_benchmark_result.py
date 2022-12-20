#!/usr/bin/python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys

filename,size = sys.argv[1],15

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
        bench_names = x.split()[0].split('/') # ['bench_matrix_flatvector', 'add', '16', '16']
        row = float(bench_names[2])
        col = float(bench_names[3])
        if (row,col) in d:
            prev_avg,prev_count = d[row,col]
            new_avg = (prev_avg * prev_count + cpu_time) / (prev_count + 1)
            d[row,col] = (new_avg,prev_count + 1)
        else:
            d[row,col] = (cpu_time,1)


rows = []
cols = []
z = []
for (row,col), (cpu_time,count) in d.items():
    print(f"{row} {col} {cpu_time} {count}")
    rows.append(row)
    cols.append(col)
    z.append(cpu_time)

# print(rows)
# print(cols)
# print(z)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_xlabel("row")
ax.set_ylabel("col")
ax.set_zlabel("time (ns)")
ax.scatter(xs = rows, ys = cols, zs = z)

for i in range(0,size):
    start, end = size*i, size*(i+1)
    line = z[start:end]
    # color = 'slateblue' if sorted(line) == line else 'crimson'
    linewidth = 1 if sorted(line) == line else 4
    ax.plot(rows[start:end],cols[start:end],line, linewidth=linewidth)
for i in range(0,size):
    line = z[i::size]
    linewidth = 1 if sorted(line) == line else 4
    ax.plot(rows[i::size],cols[i::size],line, linewidth=linewidth )

ax.set_title(filename)
plt.show()