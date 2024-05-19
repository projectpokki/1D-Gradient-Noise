#include <iostream>
#include <vector>
#include <cmath>

double pokki_noise(double inputNum, std::vector<double> seed, double k) {
  int inputInt = floor(inputNum);
  double inputFrac = fmod(inputNum, 1.0),
    a = 0.0, b = 0.0, c = 0.0,
    positiveWeight = pow(inputFrac, k),
    negativeWeight = pow((1 - inputFrac), k);

  for (int i = 0; i < seed.size(); i++) {
    a += pow(inputInt - 1, i) * seed[i];
    b += pow(inputInt, i) * seed[i];
    c += pow(inputInt + 1, i) * seed[i];
  }

  a = negativeWeight * fmod(a, 1.0);
  b = fmod(b, 1.0);
  c = positiveWeight * fmod(c, 1.0);

  return (a + b + c) / (negativeWeight + positiveWeight + 1);
}
