#!/usr/bin/python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys

filename,size = sys.argv[1],15

f = open(filename, "r")
xs = f.readlines()

rows = []
cols = []
z = []

REPEAT_COUNT = 2

for x in xs:
    if '-' in x:
        pass
    elif x.startswith('Benchmark'):
        pass
    elif x == '\n':
        pass
    else:
        cpu_time = x.split()[3] # ['bench_matrix_flatvector/add/16/16', '198', 'ns', '198', 'ns', '3414984']
        bench_names = x.split()[0].split('/') # ['bench_matrix_flatvector', 'add', '16', '16']
        row = bench_names[2] 
        col = bench_names[3] 
        rows.append(float(row))
        cols.append(float(col))
        z.   append(float(cpu_time))

print(rows)
print(cols)
print(z)

# vertices = [list(zip(rows,cols,z))]
# poly = Poly3DCollection(vertices, alpha=0.8)
# ax.add_collection3d(poly)
# plt.show()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_xlabel("row")
ax.set_ylabel("col")
ax.set_zlabel("time (ns)")
ax.scatter(xs = rows, ys = cols, zs = z)

for i in range(0,size):
    start, end = size*i, size*(i+1)
    ax.plot(rows[start:end],cols[start:end],z[start:end])
for i in range(0,size):
    ax.plot(rows[i::size],cols[i::size],z[i::size])

ax.set_title(filename)
plt.show()