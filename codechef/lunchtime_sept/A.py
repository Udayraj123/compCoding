t = int(raw_input())
diffmap={
    "cakewalk":0,
    "simple":1,
    "easy":2,
    "easy-medium":3,
    "medium":3,
    "medium-hard":4,
    "hard":4
}

for i in range(t):
	n=int(raw_input())
	probs={0:0,1:0,2:0,3:0,4:0}
	for p in range(n):
		diff = raw_input()
		probs[diffmap[diff]]+=1
	flag=1
	for k in range(5):
		if(probs[k]==0):
			flag=0
			break;
	print(("Yes" if flag else "No"))

