n = int(input())
arr = list(map(int, input().strip().split()))
max_sum = []
if n == 1:
	print(arr[0])
if n == 2:
	print(max(arr[0], arr[1]))
else:
	max_sum.append(arr[0])
	max_sum.append(max(arr[0], arr[1]))
	for i in range(2, n):
		max_sum.append(max(max_sum[i - 2] + arr[i], max_sum[i - 1], arr[i]))
	print(max_sum[n - 1])
