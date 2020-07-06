def isvalid():
	d = dict()
	for character in s:
		if character in d:
			d[character] += 1
		else:
			d[character] = 1
	f = dict()
	for key in d:
		if d[key] in f:
			f[d[key]].add(key)
		else:
			f[d[key]] = {key}
	# print(f)
	if(len(f) == 1):
		print("YES")
	elif(len(f) > 2):
		print("NO")
	else:
		max_key = max(f.keys())
		min_key = min(f.keys())
		if(max_key - min_key == 1 and (len(f[max_key]) == 1 or len(f[min_key]) == 1)):
			print("YES")
		elif(len(f[min_key]) == 1):
			print("YES")
		else:
			print("NO")

s = input().strip()
isvalid()