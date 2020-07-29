count = 0

def createlist(x, n):
	l = [1]
	i = 2
	while(True):
		num = i ** n
		if(num > x):
			break
		l.append(num)
		i += 1
	return l

def solve(currsum, l, x):
	global count
	if(l == []):
		return
	if(currsum + l[0] == x):
		count += 1
		return
	elif(currsum + l[0] > x):
		return
	else:
		solve(currsum + l[0], l[1:], x)
		solve(currsum, l[1:], x)

def powerSum(x, n):
	l = createlist(x, n)
	solve(0, l, x)



x = int(input().strip())
n = int(input().strip())
powerSum(x, n)
print(count)