def check(p, q):
	a = [""]
	b = [""]
	a.extend(list(p))
	b.extend(list(q))

	# if(p == "" and q == ""):
	# 	return True
	# elif(p == ""):
	# 	return False
	# elif(q == ""):
	# 	if(p.islower()):
	# 		return True
	# 	else:
	# 		return False
	# else:
	# 	if(p[-1].isupper()):
	# 		if(p[-1] == q[-1]):
	# 			return check(p[:-1], q[:-1])
	# 		else:
	# 			return False
	# 	else:
	# 		if(p[-1].upper() == q[-1]):
	# 			return check(p[:-1], q[:-1]) or check(p[:-1], q)
	# 		else:
	# 			return check(p[:-1], q)

	table = [[False for _ in range(len(a))] for _ in range(len(b))]
	table[0][0] = True
	flag = 0
	for i in range(1, len(a)):
		if(flag == 1):
			table[0][i] = False
		elif(a[i].isupper()):
			table[0][i] = False
			flag = 1
		else:
			table[0][i] = True
	for i in range(1, len(b)):
		table[i][0] = False

	for i in range(1, len(b)):
		for j in range(1, len(a)):
			if(a[j].isupper()):
				if(a[j] == b[i]):
					table[i][j] = table[i - 1][j - 1]
				else:
					table[i][j] = False
			else:
				if(a[j].upper() == b[i]):
					table[i][j] = table[i - 1][j - 1] or table[i][j - 1]
				else:
					table[i][j] = table[i][j - 1]
	return table[-1][-1]
	





q = int(input())
for _ in range(q):
	p = input()
	q = input()
	if(check(p, q)):
		print("YES")
	else:
		print("NO")