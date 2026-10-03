def count_up(n):
    i=0
    while i<n:
        yield i
        i+=1
for i in count_up(3):
    print(i)



print(sum([x*x for x in range(10)]),sum(x*x for x in range (10)))

