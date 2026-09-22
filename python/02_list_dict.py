nums=[5,2,9,1]
nums.append(7)
nums.sort()
print(nums)
print(nums[1:3])
print(nums[-1])

squares=[n*n for n in nums]
even =[n for n in nums if n%2 ==0]
print(squares)
print(even)
count={}
for ch in "hello":
    count[ch]=count.get(ch,0)+1
print(count)
