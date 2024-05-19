from math import floor


def pokki_noise(inputNum: float, seed: list, k: float):
  inputFrac, inputInt = inputNum % 1, floor(inputNum)
  a, b, c = 0, 0, 0
  positiveWeight, negativeWeight = inputFrac ** k, (1 - inputFrac) ** k
  for i in range(len(seed)):
    a += ((inputInt - 1)**i) * seed[i]
    b += (inputInt**i) * seed[i]
    c += ((inputInt + 1)**i) * seed[i]
  a, b, c = negativeWeight * (a % 1), (b % 1), positiveWeight * (c % 1)
  return (a + b + c) / (negativeWeight + positiveWeight + 1)
