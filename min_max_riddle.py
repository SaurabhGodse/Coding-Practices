n = int(input().strip())
arr = list(map(int, input().strip().split()))
stack = []
window_size = dict()

def incrementEach():
	for stack_ele in stack:
		window_size[stack_ele] += 1


for i in range(n):
	if(stack == []):
		stack.append((arr[i], i))
		window_size[(arr[i], i)] = 1
	elif(stack[-1][0] < arr[i]):
		incrementEach()
		stack.append((arr[i], i))
		window_size[(arr[i], i)] = 1
	elif(stack[-1][0] >= arr[i]):
		ws = window_size[stack[-1]] + 1
		stack.pop()
		while(stack != [] and stack[-1][0] >= arr[i]):
			ws = window_size[stack[-1]] + 1
			stack.pop()
		incrementEach()
		stack.append((arr[i], i))
		window_size[(arr[i], i)] = ws

invert_dict = dict()
for key in window_size:
	value = window_size[key]
	ele = key[0]
	if value not in invert_dict:
		invert_dict[value] = ele
	else:
		invert_dict[value] = max(invert_dict[value], ele)
ans = []
currmax = invert_dict[n]
ans.append(currmax)
for i in reversed(range(1, n)):
	if i in invert_dict:
		currmax = max(currmax, invert_dict[i])
	ans.append(currmax)
for i in reversed(range(n)):
	print(ans[i], end = " ")

	

