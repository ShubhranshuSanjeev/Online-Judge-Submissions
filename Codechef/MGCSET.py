testCases = input()
arrResult = []

for t in range(int(testCases)):
    nm = input().split(" ")
    n = int(nm[0])
    m = int(nm[1])
    sequence = input().split(" ")
    counter = 0
    for i in sequence:
        if int(i) % m == 0:
            counter+=1
    arrResult.append(2**counter - 1)
for i in arrResult:
    print(i)
