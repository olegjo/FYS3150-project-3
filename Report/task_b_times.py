import numpy as np

def dooooit(N, result, comp_time):
	exact = 5*np.pi**2/16**2
	if len(comp_time) != 10:
		print "Something went wrong with N =", N
	# print "N              =", N
	# print "Average time   =", np.average(comp_time), "seconds"
	# print "Result         =", result
	# print "Relative error =", abs(result-exact)/exact

	print "%i 	&	%.5f	&	%.5f			&	%.2f	\\\ " % (N, result, abs(result-exact)/exact, np.average(comp_time))

print "N 	&	Result	&	Relative error	&	CPU-time \\\ " 

N = 10
result = 0.186457
comp_time = np.array([0.55, 0.26, 0.33, 0.25])
dooooit(N, result, comp_time)


N = 16
result = 0.190113
comp_time = np.array([4.16, 4.10, 4.14, 4.29])
dooooit(N, result, comp_time)



N = 20
result = 0.191082
comp_time = np.array([15.72, 15.76, 16.58, 16.55])
dooooit(N, result, comp_time)



N = 24
result = 0.191639
comp_time = np.array([48.04, 47.61, 48.03, 47.78])
dooooit(N, result, comp_time)



N = 30
result = 0.192114
comp_time = np.array([181.88, 180.91, 213.08, 184.88])
dooooit(N, result, comp_time)


N = 36
result = 0.192378
comp_time = np.array([537.88, 532.76, 595.02, 535.52])
dooooit(N, result, comp_time)


N = 40
result = 0.192493
comp_time = np.array([1102.01, 1288.28, 1261.27, 1218.23])
dooooit(N, result, comp_time)





