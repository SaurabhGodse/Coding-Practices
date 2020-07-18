# l = []
freq = dict()
nums_of_freq = dict()

def insert(x):
	# l.append(x)
	if x in freq:
		f = freq[x]
		nums_of_freq[f].remove(x)
		freq[x] += 1
		if freq[x] in nums_of_freq:
			nums_of_freq[freq[x]].add(x)
		else:
			nums_of_freq[freq[x]] = {x}
	else:
		freq[x] = 1
		if 1 in nums_of_freq:
			nums_of_freq[1].add(x)
		else:
			nums_of_freq[1] = {x}
def delete(y):
	if y in freq:
		f = freq[y]
		nums_of_freq[f].remove(y)		
		freq[y] -= 1
		if(freq[y] == 0):
			freq.pop(y)
		else:
			if freq[y] in nums_of_freq:
				nums_of_freq[freq[y]].add(y)
			else:
				nums_of_freq[freq[y]] = {y}

def check(z):
	if z > 0 and z in nums_of_freq:
		if(len(nums_of_freq[z]) > 0):
			return 1
	return 0
l = []
n = int(input().strip())
for _ in range(n):
	a, b = list(map(int, input().strip().split()))
	if(a == 1):
		insert(b)
	elif(a == 2):
		delete(b)
	elif(a == 3):
		l.append(check(b))
for i in l:
	print(i)


