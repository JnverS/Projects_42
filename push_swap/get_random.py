import random
import sys

a = list(range(int(sys.argv[1])))
random.shuffle(a)
for i in a:
	print(i, end=" ")