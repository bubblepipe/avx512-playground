#!/usr/bin/python3

# import proplot
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys
import numpy as np

filename='i16-3ymmf32-overflow'

title = 'pivot, row 30, col 16, specia' + filename 
# size = int(sys.argv[2])

size = "xx-large"
# size = "medium"

# xlabel = ['int16 (vectorized)', 'float (vectorized)', 'double (vectorized)', 'Upstream Impl (scalcar)']
xlabel = ['int16_t',
          'float',
          'MLIR upstream int64_t',
           ]


legends = [ 
             "Overflow ignored", 
             "Overflow aware",
             ]

xss = []
xss.append(np.arange(3))

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
        cpu_time = float(x.split()[1]) # check/double           25.4 ns         25.4 ns     28695205
        xx = x.split()[0].split('/') 
        # print(xx)
        # exit(0)
        bench_name = f'{xx[2]}'
        arg =  f'{xx[3]}'
        if not (bench_name in d):
            d[bench_name] = {}
        if arg in d[bench_name]:
            cpu_time = 0 if cpu_time < 2 else cpu_time
            d[bench_name][arg].append(cpu_time)
        else:
            d[bench_name][arg] = [cpu_time]

print(d)



fig, ax = plt.subplots(figsize =(12, 9))
ax.set_yscale('log')

barWidth = 0.15

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


# color_iter = iter(colors)
for (xs,ys,errs) in zip(xss,yss,errss):
    print(xs)
    print(ys)
    ax.bar(xs,ys,width=barWidth) #, color=next(color_iter))
    
rects = ax.patches
labels = [f"label{i}" for i in range(len(rects))]
for rect, label in zip(rects, labels):
    height = rect.get_height()
    txt = height
    if txt != 0:
        txt = str(round(txt,1))
    else:
        txt = 'N/A'
    ax.text(
        rect.get_x() + rect.get_width() / 2, height + 0.5, txt, ha="center", va="bottom", fontsize='x-large'
    )

# color_iter = iter(colors)
ax.legend(labels=legends, fontsize=size, loc="upper left")
ax.set_ylim(ymin=0,ymax=800)
for (xs,ys,errs) in zip(xss,yss,errss):
    print('=================')
    print(xs)
    print(ys)
    print(errs)
    ax.errorbar(xs,ys,yerr=errs,fmt="|",elinewidth=2 )#, color=next(color_iter))


plt.xticks([ x  - 0.5 * barWidth for x in xss[1]], list(xlabel), fontsize='xx-large',)
ax.set_ylabel("time (ns), log scale, lower is better", fontsize=size)
# ax.set_title(title, fontsize=size)
plt.savefig( filename +'.png', dpi=300)
