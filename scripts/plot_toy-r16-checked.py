#!/usr/bin/python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys
import numpy as np

filename = "./verified-plot/checked-bar"
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
            d[bench_name][row,col].append(cpu_time)
        else:
            d[bench_name][row,col] = [cpu_time]


color_iter = iter(['slateblue', 'crimson', 'lightseagreen', 'darkred'])

fig, ax = plt.subplots(figsize =(16, 9))

barWidth = 0.2
xss = []
xss.append(np.arange(3))
yss = []
errss = []
xlabel = ['col size 8','col size 16','col size 32']

for bench_name, bench_vals in d.items():

    xss.append([x + barWidth for x in xss[-1]])
    ys = []
    errs = []
    for (row,col), (cpu_time_xs) in bench_vals.items():
        ys.append(sum(cpu_time_xs)/len(cpu_time_xs))
        errs.append(np.std(cpu_time_xs))
    yss.append(ys)
    errss.append(errs)

for (xs,ys,errs) in zip(xss,yss,errss):
    ax.bar(xs,ys,width=barWidth)

rects = ax.patches
labels = [f"label{i}" for i in range(len(rects))]
for rect, label in zip(rects, labels):
    height = rect.get_height()
    txt = height
    ax.text(
        rect.get_x() + rect.get_width() / 2, height + 0.5, str(round(txt,1)), ha="center", va="bottom", fontsize="large"
    )
ax.legend(labels=['int16', 'float', 'double'], fontsize="x-large")

for (xs,ys,errs) in zip(xss,yss,errss):
    color = next(color_iter)
    ax.errorbar(xs,ys,yerr=errs,fmt="|",elinewidth=2)


ax.set_ylim([0, 65])


plt.xticks([ x for x in xss[1]], list(xlabel), fontsize="x-large")
ax.set_ylabel("time (ns), lower is better", fontsize="x-large")
title = 'Toy FMA Example, Row Size = 16, Overflow Check Enabled'
ax.set_title(title, fontsize="xx-large")
plt.show()
