def main():
  N = int(input())
  S = input()

  # Check if at least one interviewer rated the score as "good".
  good = False
  for i in range(N):
    if S[i] == "o":
      good = True
      break

  # Check if at least one interviewer rated him or her as "not acceptable".
  bad = False
  for i in range(N):
    if S[i] == "x":
      bad = True
      break

  # If both of the following two conditions are satisfied, then Takahashi passed; otherwise, he failed.
  if good and not bad:
    print("Yes")
  else:
    print("No")

if __name__ == "__main__":
  main()