import string
def weightedUniformStrings(s):
	weight = dict(zip(string.ascii_lowercase, range(1, 27)))
	n = len(s)	
	freq = dict()
	i = 0
	j = 1
	curr = s[0]
	while j < n:
		if(curr != s[j]):
			if curr in freq:
				freq[curr] = max(freq[curr], j - i)
			else:
				freq[curr] = j - i

			curr = s[j]
			i = j
		j += 1
	if curr in freq:
		freq[curr] = max(freq[curr], j - i)
	else:
		freq[curr] = j - i

	# print(freq)
	U = set()
	for key in freq:
		wt = weight[key]
		for i in range(1, freq[key] + 1):
			U.add(wt * i)
	return U

s = input().strip()
U = weightedUniformStrings(s)
n = int(input().strip())
for _ in range(n):
	ele = int(input().strip())
	if ele in U:
		print("Yes")
	else:
		print("No")

