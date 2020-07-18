maximum = 0
nodes = dict()
class Node:
	def __init__(self, data):
		self.data = data
		self.parent = self
		self.rank = 1
	def isequal(self, node):
		return self.data == node.data and self.parent == node.parent and self.rank == node.rank

def createNode(data):
	n = Node(data)
	nodes[data] = n

def find(n : Node):
	if(n.isequal(n.parent)):
		return n
	return find(n.parent)
def union(a : Node, b : Node):
	global maximum
	parent_a = find(a)
	parent_b = find(b)
	# print("parent of : " + str(a.data) + " is : " + str(parent_a.data))
	# print("parent of : " + str(b.data) + " is : " + str(parent_b.data))
	# print("rank of " + str(parent_a.data) + " is : " + str(parent_a.rank))
	# print("rank of " + str(parent_b.data) + " is : " + str(parent_b.rank))

	if(parent_a.isequal(parent_b)):
		return False

	if(parent_a.data >= parent_b.data):
		parent_a.rank += parent_b.rank
		maximum = max(maximum, parent_a.rank)
		# print("if : " + str((parent_b.parent).data))
		parent_b.parent = parent_a
		# print((parent_b.parent).data)

	else:
		parent_b.rank += parent_a.rank
		maximum = max(maximum, parent_b.rank)
		# print("else : " + str((parent_a.parent).data))
		parent_a.parent = parent_b
		# print((parent_a.parent).data)
	# print("parent of : " + str(a.data) + " is : " + str((a.parent).data))
	# print("parent of : " + str(b.data) + " is : " + str((b.parent).data))
	# print("rank of " + str(find(a).data) + " is : " + str(find(a).rank))
	# print("rank of " + str(find(b).data) + " is : " + str(find(b).rank))
	
	return True


n = int(input())
queries = []
for _ in range(n):
	queries.append(list(map(int, input().strip().split())))
for a, b in queries:
	if a not in nodes:
		createNode(a)
	if b not in nodes:
		createNode(b)
	union(nodes[a], nodes[b])
	print(maximum)

