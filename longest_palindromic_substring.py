s = input().strip()
n = len(s)
maxlen = 1
l = 0
r = 0
table = [[False for j in range(n)] for i in range(n)]
for i in range(n):
	table[i][i] = True

for i in range(n - 1):
	if s[i] == s[i + 1]:
		table[i][i + 1] = True
		if maxlen < 2:
			maxlen = 2
			l = i
			r = i + 1

for k in range(3, n + 1):
	for i in range(n - k + 1):
		j = i + k - 1
		if(table[i + 1][j - 1] and s[i] == s[j]):
			table[i][j] = True
			if(maxlen < k):
				maxlen = k
				l = i
				r = j

print("Longest palindromic substring : " + s[l : r + 1])
print("Length : ", maxlen)
