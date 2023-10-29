#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int countPrimesMethodC(int n)
{
    int count = 0;
    for (int k = 3; k <= n; ++k)
    {
        if (k % 2 != 0)
        {
            bool isPrime = true;
            for (int i = 2; i <= sqrt(k); ++i)
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
    }
    return count + 1;
}

int main()
{
  cout << "podaj koniec przedzia³u" <<endl;
  int n;
  cin >> n;
  auto start_time = chrono::high_resolution_clock::now();
  int primeCount = countPrimesMethodC(n);
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end_time -     start_time);

  cout << "Metoda C (naiwna z pêtl¹ i=2 do i=sqrt(" << n << ")) " <<endl;
  cout << primeCount << " liczb pierwszych" <<endl;
  cout << "Czas: " << duration.count() << " mikrosekund" << endl;

  return 0;
}
