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
result = 0.194373
comp_time = np.array([0.06, 0.06, 0.06, 0.06, 0.05])
variance = 7.12094e-06
dooooit(N, result, comp_time, variance)

N = 1e6
result = 0.192976
comp_time = np.array([0.61, 0.63, 0.6, 0.6, 0.72])
variance = 6.74326e-06
dooooit(N, result, comp_time, variance)

N = 1e7
result = 0.192717
comp_time = np.array([5.98, 6.27, 6.01, 5.99, 5.97])
variance = 7.40962e-06
dooooit(N, result, comp_time, variance)

N = 1e8
result = 0.192789
comp_time = np.array([59.28, 60.74, 60.08, 60.05, 60.41])
variance = 7.14382e-06
dooooit(N, result, comp_time, variance)

N = 1e9
result = 0.192764
comp_time = np.array([601.94, 605.15, 599.73])
variance = 7.12096e-06
dooooit(N, result, comp_time, variance)






