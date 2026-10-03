n,T=map(int,input().split())
temp=list(map(int,input().split()))
idx=(i for i in range(n) if temp[i]>T)
idx=sorted(idx,key=lambda x: (-temp[x],x))
if not idx:
    print(-1)
else:
    print(*idx)
