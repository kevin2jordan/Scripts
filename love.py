import matplotlib.pyplot as mpplt
import matplotlib.gridspec as gridspec
import numpy
 
figure = mpplt.figure(figsize=(11, 10))
gs = gridspec.GridSpec(3, 12)
 
# I
plt = figure.add_subplot(gs[0, :])
plt.hlines(3, -10, 10, color='red')
plt.hlines(-3, -10, 10, color='red')
plt.vlines(0, -3, 3, color='red')
plt.set_xlim([-20, 20])
plt.set_ylim([-4, 4])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# L
plt = figure.add_subplot(gs[1, 0:3])
x = numpy.linspace(0.1, 100, 10000)
y = 1 / x
plt.plot(x, y, color='blue')
plt.set_ylim([-0.1, 5])
plt.set_xlim([-1, 20])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# 0
plt = figure.add_subplot(gs[1, 3:6])
theta = numpy.linspace(0, 2 * numpy.pi, 100)
# the radius of the circle
r = numpy.sqrt(9)
# compute x1 and x2
x1 = r * numpy.cos(theta)
x2 = r * numpy.sin(theta)
# create the figure
plt.plot(x1, x2, color='blue')
plt.set_ylim([-3.2, 3.2])
plt.set_xlim([-3.2, 3.2])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# V
plt = figure.add_subplot(gs[1, 6:9])
x = numpy.linspace(-10, 10, 1000)
y = numpy.absolute(x)
plt.plot(x, y, color='blue')
plt.set_ylim([0, 10])
plt.set_xlim([-10, 10])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# E
plt = figure.add_subplot(gs[1, 9:12])
y = -1 * numpy.sin(x)
plt.plot(y, x, color='blue')
plt.set_ylim([-2.5 * numpy.pi, 1.5 * numpy.pi])
plt.set_xlim([-1.1, 1.1])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# Y
plt = figure.add_subplot(gs[2, 0:4])
x = numpy.linspace(-10, 10, 1000)
y = numpy.absolute(x)
plt.plot(x, y, color='green')
plt.vlines(0, -10, 0, color='green')
plt.set_ylim([-11, 10])
plt.set_xlim([-10, 10])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# 0
plt = figure.add_subplot(gs[2, 4:8])
theta = numpy.linspace(0, 2 * numpy.pi, 100)
# the radius of the circle
r = numpy.sqrt(9)
# compute x1 and x2
x1 = r * numpy.cos(theta)
x2 = r * numpy.sin(theta)
# create the figure
plt.plot(x1, x2, color='green')
plt.set_ylim([-3.2, 3.2])
plt.set_xlim([-4, 4])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
# U
plt = figure.add_subplot(gs[2, 8:12])
x = numpy.linspace(-10, 10, 1000)
y = (x**2) / 12
plt.plot(x, y, color='green')
plt.set_ylim([0, 7])
plt.set_xlim([-10, 10])
plt.set_xticklabels([])
plt.set_yticklabels([])
 
figure.tight_layout()
figure.savefig('test.png', facecolor='white', edgecolor='black')
