import time

def timer(f):
    def wrapper(*args,**kwargs):
        t=time.time()
        r=f(*args,**kwargs)
        print(f"{f.__name__}用了{time.time() - t:.4f}s")
        return r
    return wrapper

@timer
def slow(n):
    return sum(i*i for i in range(n))

print(slow(300000))
