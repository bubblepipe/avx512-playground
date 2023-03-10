#!/usr/bin/python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys
import numpy as np

filename = './verified-plot/plot-pivot-checked_check_unchecked'
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
        cpu_time = float(x.split()[3]) # check/double           25.4 ns         25.4 ns     28695205
        xx = x.split()[0].split('/') 
        bench_name = f'{xx[0]}'
        arg = xx[1]
        if not (bench_name in d):
            d[bench_name] = {}
        if arg in d[bench_name]:
            d[bench_name][arg].append(cpu_time)
        else:
            d[bench_name][arg] = [cpu_time]


color_iter = iter(['slateblue', 'crimson', 'lightseagreen', 'darkred'])

fig, ax = plt.subplots(figsize =(16, 9))

barWidth = 0.2
xss = []
xss.append(np.arange(4))
# xss.append(np.arange(3))
yss = []
errss = []
xlabel = ['int16 (vectorized)', 'float (vectorized)', 'double (vectorized)', 'MPInt (scalcar)']
# xlabel = ['int16 (vectorized)', 'float (vectorized)', 'double (vectorized)']
legends = ['overflow check disabled', 'overflow check enabled']
title = 'pivot, row 30, col 16, no normalize, fast FPE'
for bench_name, bench_vals in d.items():

    xss.append([x + barWidth for x in xss[-1]])
    ys = []
    errs = []
    for arg, (cpu_time_xs) in bench_vals.items():
        ys.append(sum(cpu_time_xs)/len(cpu_time_xs))
        errs.append(np.std(cpu_time_xs))
    yss.append(ys)
    errss.append(errs)

for (xs,ys,errs) in zip(xss,yss,errss):
    print(xs)
    print(ys)
    ax.bar(xs,ys,width=barWidth)
    
rects = ax.patches
labels = [f"label{i}" for i in range(len(rects))]
for rect, label in zip(rects, labels):
    height = rect.get_height()
    txt = height
    if txt != 0:
        ax.text(
            rect.get_x() + rect.get_width() / 2, height + 0.5, str(round(txt,1)), ha="center", va="bottom", fontsize="xx-large"
        )

ax.legend(labels=legends, fontsize="x-large", loc='upper left')

for (xs,ys,errs) in zip(xss,yss,errss):
    color = next(color_iter)
    ax.errorbar(xs,ys,yerr=errs,fmt="|",elinewidth=2)


plt.xticks([ x-0.5*barWidth for x in xss[1]], list(xlabel), fontsize="x-large")
ax.set_ylabel("time (ns), lower is better", fontsize="x-large")
ax.set_title(title, fontsize="xx-large")
plt.show()
