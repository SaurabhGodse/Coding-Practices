cur = None
count = 0
n = int(input().strip())
s = input().strip()
l = []

for i in range(n):
	if s[i] == cur:
		count += 1
	else:
		if cur is not None:
			l.append((cur, count))
		cur = s[i]
		count = 1
l.append((cur, count))

ans = 0
for a, b in l:
	ans += b * (b + 1) // 2

for i in range(len(l) - 2):
	if(l[i][0] == l[i + 2][0] and l[i + 1][1] == 1):
		ans += min(l[i][1], l[i + 2][1])
print(ans)