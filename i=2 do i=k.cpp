#include <chrono>
#include <iostream>

using namespace std;

int countPrimesMethodA(int n)
{
  int count = 0;
  for (int k = 2; k <= n; ++k)
  {
    bool isPrime = true;
    for (int i = 2; i < k; ++i)
    {
      if (k % i == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
    {
      count++;
    }
  }
  return count;
}

int main() {
  cout << "podaj zakres koñcowy" << endl;
  int n;
  cin >> n;
  auto start_time = chrono::high_resolution_clock::now();
  int primeCount = countPrimesMethodA(n);
  auto end_time = chrono::high_resolution_clock::now();
  auto duration =
      chrono::duration_cast<chrono::microseconds>(end_time - start_time);

  cout << "Metoda A (naiwna z pêtl¹ i=2 do i= " << n << ")" << endl;
  cout << primeCount << " liczb pierwszych" << endl;
  cout << "Czas: " << duration.count() << " mikrosekund" << endl;

  return 0;
}
