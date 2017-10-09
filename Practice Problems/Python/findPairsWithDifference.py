from sets import Set

class Pair:
	a = 1
	b = 2

	def __init__(self, myA, myB):
		self.a = myA
		self.b = myB

	def __repr__(self):
		return "(" + str(self.a) + ", " + str(self.b) + ")"
	def __str__(self):
		return "A: " + self.a + " B: " + self.b + " "


def findPairsWithDifference(difference, arr):
	setArr = Set([])
	result = []
	if difference == 0:
		for i in arr:
			if i in setArr:
				result.append(Pair(i,i))
			else:
				setArr.add(i)
		return result
	for i in arr:
		setArr.add(i)

	for i in setArr:
		if (i + difference) in arr:
			result.append(Pair(i, i + difference))
	return result

print findPairsWithDifference(3, [1,2,3,4,5,6])
print findPairsWithDifference(0, [1,1,2,3,4,5,6,9,9,9])
print findPairsWithDifference(-1, [1,1,2,3,4,5,6,9,9,9])