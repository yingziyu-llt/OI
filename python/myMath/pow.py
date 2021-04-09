def pow(x,n):
	"""x是底数，n是指数，n是正整数"""
	while(n > 0):
		x *= x
		n = n - 1
	return x