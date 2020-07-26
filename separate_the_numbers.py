def increment(s):
	return str(int(s) + 1)

def sequential(s, t):
	if len(s) == 0:
		return True
	if s.startswith(t):
		return sequential(s[len(t):], increment(t))
	return False
def separateNumbers(s):
	# write your code here
	n = len(s)
	for i in range(1, n // 2 + 1):
		if(sequential(s, s[:i])):
			return "YES " + s[:i]
	return "NO"


q = int(input().strip())
for _ in range(q):
	print(separateNumbers(input().strip()))