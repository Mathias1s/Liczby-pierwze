#include <iostream>
#include <chrono>

using namespace std;

int countPrimesMethodB(int n)
{
    int count = 0;
    for (int k = 3; k <= n; ++k)
    {
        if (k % 2 != 0)
        {
            bool isPrime = true;
            for (int i = 3; i < k; i += 2)
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
  int primeCount = countPrimesMethodB(n);
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end_time -     start_time);

  cout << "Metoda B (naiwna z pêtl¹ i=3 do i=" << n << ")" <<endl;
  cout << primeCount << " liczb pierwszych" <<endl;
  cout << "Czas: " << duration.count() << " mikrosekund" << endl;

  return 0;
}
