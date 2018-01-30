#include <iostream>
#include <cstdlib>
#include <cassert>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b)
{
  if (b == 0)
    return a;
  if (a == 0)
    return b;
  int remainder = a % b;
  return gcd_fast(b, remainder);
}

long long lcm_fast (int a, int b) {
  long long product = (long long) a * b;
  int gcd = gcd_fast(a,b);
  return product / gcd;
}

void testSolution()
{
  assert(lcm_fast(6, 8) == 24);
  assert(lcm_fast(28851538, 1183019) == 1933053046);
  while (true)
  {
    int a = rand() % 1000 + 2;
    int b = rand() % 1000 + 2;
    std::cout << "a = " << a << ",b = " << b << '\n';
    assert(lcm_fast(a, b) == lcm_naive(a, b));
    std::cout << "Passed\n";
  }
}

int main() {
  int a, b;
  //testSolution();
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}