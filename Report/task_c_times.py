import numpy as np

def dooooit(N, result, comp_time, variance):
	exact = 5*np.pi**2/16**2

	# print "N              =", N
	# print "Average time   =", np.average(comp_time), "seconds"
	# print "Result         =", result
	# print "Relative error =", abs(result-exact)/exact

	print "$10^%i$ 	&	%.5f	&	%.5f	&	%.2e	&	$%.2f \pm %.2f$ s	\\\ \hline " % (np.log10(N), result, abs(result-exact)/exact, variance, np.average(comp_time), np.std(comp_time))

print '\hline'
print '\\textbf{N} 		&	\\textbf{Result}		&	\\textbf{Relative error}	&	\\textbf{Variance}	&	\\textbf{CPU-time} \\\ \hline'

N = 1e5
result = 0.197257
comp_time = np.array([0.03, 0.03, 0.08, 0.03, 0.03])
variance = 1.86273e-09
dooooit(N, result, comp_time, variance)


N = 1e6
result = 0.136952
comp_time = np.array([0.78, 0.41, 0.78, 0.38, 0.58])
variance =  8.29133e-10
dooooit(N, result, comp_time, variance)



N = 1e7
result = 0.16192
comp_time = np.array([3.38, 3.34, 3.36, 3.34, 3.45])
variance = 8.77437e-09
dooooit(N, result, comp_time, variance)



N = 1e8
result = 0.194669
comp_time = np.array([33.52, 33.68, 33.4, 34.31, 33.4])
variance = 2.63761e-08
dooooit(N, result, comp_time, variance)



N = 1e9
result = 0.194494
comp_time = np.array([327.54, 342.43, 333.93, 332.71, 345.08])
variance = 1.95963e-08
dooooit(N, result, comp_time, variance)






