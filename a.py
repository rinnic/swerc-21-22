def main():
  t = int(input())
  for _ in range(t):
    difficulties = {1,2,3,4,5,6,7,8,9,10}
    beauties = dict()
    n = int(input())
    for _ in range(n):
      b, d = [int(x) for x in input().strip().split(" ")]
      if d in difficulties:
        difficulties.remove(d)
      if d not in beauties or beauties[d] < b:
        beauties[d] = b
    
    if not difficulties:
      print(sum(beauties.values()))
    else:
      print("MOREPROBLEMS")
        

if __name__ == "__main__":
    main()

