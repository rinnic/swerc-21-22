
def solution(lines):
  difficulties = {1,2,3,4,5,6,7,8,9,10}
  beauties = dict()
  for line in lines:
    b, d = line.split(" ")
    b, d = int(b), int(d)
    if d in difficulties:
      difficulties.remove(d)
    if d not in beauties or beauties[d] < b:
      beauties[d] = b
  if difficulties:
    return "MOREPROBLEMS"
  return sum([beauties[d] for d in beauties])
  
    

def main():
    with open('data/secret/2.in') as file: 
      lines = [line.strip() for line in file.readlines()]
      start = 0
      t = int(lines[start])
      for _ in range(t):
        start = start + 1
        end = start + int(lines[start])
        print(solution(lines[start+1 : end+1]))
        start = end
        

if __name__ == "__main__":
    main()

