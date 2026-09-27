n=int(input())
info={}
order=[]
for i in range(n):
    parts=input().split()
    op=int(parts[0])
    if op==1:
        pos=int(parts[1])
        name=parts[2]
        age=int(parts[3])
        score=int(parts[4])
        info[name]=(age,score)
        if pos>len(order):
            order.append(name)
        else:
            order.insert(pos,name)
    elif op==2 :
        name=parts[1]
        if name in order :
            del info[name]
            order.remove(name)
    elif op==3:
        name=parts[1]
        if name in order:
            a,g=info[name]
            p=order.index(name)+1
            print("Score:",g,"Pos:",p)
        else:
            print("Not found")



