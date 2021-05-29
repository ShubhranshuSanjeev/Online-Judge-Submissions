while True:
    n = int(input())
    if n == 0:
        break
    arr = [int(x) for x in input().split()]
    st = [arr[0]]
    reordered = []
    for i in range(1, n):
        while arr[i] > st[-1]:
            reordered.append(st.pop())
            if len(st) == 0:
                break
        st.append(arr[i])
    
    for i in range(len(st)-1, -1, -1):
        if len(st) == 0:
            break
        if len(reordered) == 0 or st[i] == (reordered[-1]+1):
            reordered.append(st.pop())
        else:
            break
    
    if not len(st) == 0:
        print("no")
    else:
