import numpy as np

def dooooit(N, result, comp_time):
	exact = 5*np.pi**2/16**2
	if len(comp_time) != 10:
		print "Something went wrong with N =", N
	# print "N              =", N
	# print "Average time   =", np.average(comp_time), "seconds"
	# print "Result         =", result
	# print "Relative error =", abs(result-exact)/exact

	print "%i 	&	%.5f	&	%.5f			&	$%.2f \pm %.2f$ s	\\\ \hline" % (N, result, abs(result-exact)/exact, np.average(comp_time), np.std(comp_time))

print "\hline"
print "\\textbf{N} 	&	\\textbf{Result}	&	\\textbf{Relative error}	&	\\textbf{CPU-time} \\\ \hline " 

N = 10
result = 0.129834
comp_time = np.array([0.10000000, 0.11000000, 0.10000000, 0.10000000, 0.11000000, 0.11000000, 0.11000000, 0.11000000, 0.11000000, 0.11000000])
dooooit(N, result, comp_time)


N = 16
result = 0.16786
comp_time = np.array([1.82000000, 1.89000000, 1.89000000, 1.90000000, 1.90000000, 1.87000000, 1.85000000, 1.94000000, 2.26000000, 1.79000000])
dooooit(N, result, comp_time)



N = 20
result = 0.177065
comp_time = np.array([6.78000000, 6.96000000, 6.94000000, 7.43000000, 7.53000000, 6.92000000, 6.91000000, 6.89000000, 6.94000000, 6.95000000])
dooooit(N, result, comp_time)



N = 24
result = 0.181941
comp_time = np.array([20.85000000, 20.78000000, 20.57000000, 21.10000000, 20.65000000, 20.62000000, 20.63000000, 20.86000000, 20.71000000, 21.49000000])
dooooit(N, result, comp_time)



N = 30
result = 0.185796
comp_time = np.array([77.41000000, 79.70000000, 79.81000000, 79.79000000, 79.26000000, 77.67000000, 78.01000000, 77.78000000, 79.70000000, 79.25000000])
dooooit(N, result, comp_time)


N = 36
result = 0.187817
comp_time = np.array([233.76000000, 232.33000000, 234.93000000, 235.05000000, 233.32000000, 230.58000000, 235.71000000, 231.37000000, 235.74000000, 234.22000000])
dooooit(N, result, comp_time)


N = 40
result = 0.18867
comp_time = np.array([443.47000000, 448.38000000, 440.34000000, 444.70000000, 459.84000000, 445.07000000, 433.95000000, 440.52000000, 434.94000000, 449.60000000])
dooooit(N, result, comp_time)





