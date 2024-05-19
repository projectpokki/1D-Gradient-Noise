# 1D-Gradient-Noise
Gradient noise generator algorithm, based on drawing a spline from a list of pseudorandom numbers. Originally a small math project, ported into Python and C++.

In the noise algorithm below, there are two functions.

$$m(x) = x - \lfloor x \rfloor $$

$$r(x) = m \bigg( \sum_{i=1}^{s_{length}} x^i s_i \bigg)$$

$m(x)$ is taking the fractional part of a number. $r(x)$ generates a pseudorandom number where $0 \leq n < 1$, based on a seed. The seed, $s$, is a list of numbers where $0 < s_n < 1$, like {0.1327, 0.4293, 0.9551, 0.5869}.  $s_n$ is the nth element of the list, starting from 1. $s_{length}$ is the total amount of elements in the list. The more complicated each decimal is, the more random $r(x)$ feels.


The noise algorithm:

$$f(x) = \frac{ ( 1-m(x) )^k r(\lfloor x \rfloor - 1) + r(\lfloor x \rfloor) + m(x)^k r(\lfloor x \rfloor + 1)}{ ( 1-m(x) )^k + 1 + m(x)^k }$$

The algorithm takes the weighted average of values of $r(x)$ for integers near $x$. $k$ affects how the weight is applied. It can be any number where $k > 1$. The higher $k$ is, the closer the spline fits the random values.

# Using Python or C++ Code
The function ```pokki_noise()``` has three inputs:
<br>```inputNum```: (a float in python, a double in C++), the input value of the function. It is something like 1.37.
<br>```seed```: (a list of floats in python, a vector<double> in C++), the seed of the function. It is something like [0.432, 0.135, 0.228].
<br>```k```: (a float in python, a double is C++), affects the sharpness of the noise. it is something like 3. It works best between 2 and 5.

Note: In C++, the function returns a double.
