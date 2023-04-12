#!/usr/bin/python3

# import proplot
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys
import numpy as np

filename='bench_fenv'

title = 'Performance of fetestexcept and feclearexcept' 

size = "xx-large"

xlabel = ['fetestexcept', 'fetestexcept_x87', 'fetestexcept_mxcsr', 'feclearexcept', 'feclearexcept_x87', 'feclearexcept_mxcsr']

cluster_count = 6

xss = []
xss.append(np.arange(cluster_count))

f = open(filename, "r")
xs = f.readlines()

d = {}

for x in xs:
    if '-' in x:
        pass
    elif x.startswith('Benchmark'):
        pass
    elif x == '\n':
        pass
    else:
        cpu_time = float(x.split()[1]) # check/double           25.4 ns         25.4 ns     28695205
        xx = x.split()[0].split('/') 
        bench_name = '' # f'{xx[2]}'
        arg = f'{xx[0]}'
        if not (bench_name in d):
            d[bench_name] = {}
        if arg in d[bench_name]:
            cpu_time = 0 if cpu_time < 2 else cpu_time
            d[bench_name][arg].append(cpu_time)
        else:
            d[bench_name][arg] = [cpu_time]


# legends = list(d.keys())
print(d.keys()) 

fig, ax = plt.subplots(figsize =(16, 9))

barWidth = 0.2

yss = []
errss = []

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
    # print(ys)
    ax.bar(xs,ys,width=barWidth, )
    
rects = ax.patches
labels = [f"label{i}" for i in range(len(rects))]
for rect, label in zip(rects, labels):
    height = rect.get_height()
    txt = height
    if txt != 0:
        ax.text(
            rect.get_x() + rect.get_width() / 2, height + 0.5, str(round(txt,1)), ha="center", va="bottom", fontsize='x-large'
        )

plt.yticks(fontsize=size)

# ax.legend(labels=legends, fontsize=size, loc="upper left")
# ax.set_ylim(ymin=0,ymax=80)
for (xs,ys,errs) in zip(xss,yss,errss):
    ax.errorbar(xs,ys,yerr=errs,fmt="|",elinewidth=2,)


plt.xticks([  x for x in xss[0] ], list(xlabel), fontsize=size, rotation = 10)
ax.set_ylabel("CPU Time (ns), lower is better", fontsize=size)
# ax.set_xlabel(x_axis_label, fontsize=size)
ax.set_title(title, fontsize=size)
plt.savefig( filename +'.png', dpi=300)