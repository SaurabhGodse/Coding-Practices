def new_year_chaos(n, arr):
	total_swaps = 0
	for i in reversed(range(n)):
		pos = i + 1
		num = arr[i]
		if(num - pos > 2):
			return "Too chaotic"
		for j in range(max(0, num - 2), i):
			if(arr[j] > num):
				total_swaps += 1
	return total_swaps

T = int(input().strip())
for _ in range(T):
	n = int(input().strip())
	arr = list(map(int, input().strip().split()))
	print(new_year_chaos(n, arr))