import random
import os

def gen():
	n = random.randint(2, 6)
	a = []
	for i in range(n):
		x = random.randint(1, n)
		a.append(x)
	s = str(n) + "\n"
	for i in a:
		s = s + str(i) + " "
	return s

print(os.popen("g++ -Wall -std=gnu++17 -o 28 28.cpp").read())
print(os.popen("g++ -Wall -std=gnu++17 -o 28ok 28ok.cpp").read())
a = input()
for i in range(1000):
	test = gen()
	f = open("nextmultiperm.in", "r")
	v1 = os.popen("./28 < nextmultiperm.in").read()
	v2 = os.popen("./zalupa < nextmultiperm.in").read()
	f1 = open("nextmultiperm.out", "r")
	v2 = f1.read()
	if (v1 != v2) :
		print("WA " + str(i) + "\n Test : " + test + "\n" + "Expected : " + v2 + "\n Found : " + v1)
		break
	else:
		print("OK" + str(i))
	f.close()
	f1.close()