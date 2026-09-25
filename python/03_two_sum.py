n,target=map(int,input().split())
rpm=list(map(int,input().split()))
seen={}
for i,x in enumerate(rpm):
    need=target-x
    if need in seen:
        print(seen[need],i)
        break
    seen[x]=i
