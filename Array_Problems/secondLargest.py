def solve(arr):
  small = 10**9
  ssmall = 10**9
  
  n = len(arr)
  for num in arr:
    if num < small:
      ssmall = small
      small = num
    elif num < ssmall and num != small:
      ssmall = num
  
  print(ssmall)
  
arr = [5,3,8,3,1,1,2,4,9]
solve(arr)