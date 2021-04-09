def makeave(listn):
	'''计算平均数  输入列表'''
	a = 0
	tot = 0
	for item in listn:
		a = item + a
		tot = tot + 1
	return a / tot