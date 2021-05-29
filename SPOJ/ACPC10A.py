while True:
    a,b,c = [int(x) for x in input().split(' ')]
    if a==0 and b==0 and c==0: break
    if(a-b==b-c):
        print('AP ', c + (c-b))
    else:
        print('GP ', int(c*(c/b)))
