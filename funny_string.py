def funnystring(s):
	# write your code here
	n = len(s)
	l = [abs(ord(s[i]) - ord(s[i - 1])) for i in range(1, n)]
	if l == l[::-1]:
		return "Funny"
	else:
		return "Not Funny"
q = int(input().strip())
for _ in range(q):
	print(funnystring(input().strip()))
