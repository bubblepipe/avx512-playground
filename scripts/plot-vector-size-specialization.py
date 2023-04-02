#!/usr/bin/python3

# import proplot
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import sys
import numpy as np

filename='vector_size_specialization'

title = 'pivot, row 30, col 16, specia' + filename 
# size = int(sys.argv[2])

# size = "xx-large"
size = "medium"

# xlabel = ['int16 (vectorized)', 'float (vectorized)', 'double (vectorized)', 'Upstream Impl (scalcar)']
xlabel = ['col = 8, off', 'col = 8, on',
          'col = 16, off', 'col = 16, on',
          'col = 24, off', 'col = 24, on',
          'col = 32, off', 'col = 32, on' ]


# legends = [ "XMM/float",  "XMM/double",  "XMM/int16_t",  "YMM/float",  "YMM/double",  "YMM/int16_t",  "ZMM/float",   "ZMM/double",   "ZMM/int16_t",  ]

xss = []
xss.append(np.arange(8))
# xss.append(np.arange(3))

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
        bench_name = f'{xx[0]}{xx[3]}'
        arg = f'{xx[1]}{xx[2]}'
        if not (bench_name in d):
            d[bench_name] = {}
        if arg in d[bench_name]:
            cpu_time = 0 if cpu_time < 2 else cpu_time
            d[bench_name][arg].append(cpu_time)
        else:
            d[bench_name][arg] = [cpu_time]

legends = list(d.keys())
print(d.keys()) 
print(d['XMMfloat'])
print(d['ZMMfloat'])

# pink 4 6 8 f783ac e64980 c2255c
# red 4 6 8 ff8787 fa5252 e03131
# blue 4 6 8 4dabf7 228be6 1971c2
# grape 4 6 8 da77f2 be4bdb 9c36b5
# teal 4 6 8 38d9a9 12b886 087f5b
colors =  [
 '#38d9a9', '#4dabf7', '#ff8787',  #'#da77f2', '#f783ac', 
 '#12b886', '#228be6', '#fa5252',  #'#be4bdb', '#e64980', 
 '#087f5b', '#1971c2', '#e03131',  #'#9c36b5', '#c2255c', 
]






fig, ax = plt.subplots(figsize =(16, 9))

barWidth = 0.1

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


color_iter = iter(colors)
for (xs,ys,errs) in zip(xss,yss,errss):
    print(xs)
    print(ys)
    ax.bar(xs,ys,width=barWidth, color=next(color_iter))
    
rects = ax.patches
labels = [f"label{i}" for i in range(len(rects))]
for rect, label in zip(rects, labels):
    height = rect.get_height()
    txt = height
    if txt != 0:
        ax.text(
            rect.get_x() + rect.get_width() / 2, height + 0.5, str(round(txt,1)), ha="center", va="bottom", fontsize='small'
        )

color_iter = iter(colors)
ax.legend(labels=legends, fontsize=size, loc="upper center")
ax.set_ylim(ymin=0,ymax=80)
for (xs,ys,errs) in zip(xss,yss,errss):
    ax.errorbar(xs,ys,yerr=errs,fmt="|",elinewidth=2, color=next(color_iter))


plt.xticks([ x for x in xss[4]], list(xlabel), fontsize=size)
ax.set_ylabel("time (ns), lower is better", fontsize=size)
ax.set_title(title, fontsize=size)
plt.show()
