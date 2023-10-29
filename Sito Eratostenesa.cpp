#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int countPrimesMethodD(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
  cout << "podaj koniec przedzia³u" <<endl;
  int n;
  cin >> n;
  auto start_time = chrono::high_resolution_clock::now();
  int primeCount = countPrimesMethodD(n);
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end_time -     start_time);

  cout << "Metoda D (Sito Eratostenesa): " <<endl;
  cout << primeCount << " liczb pierwszych" <<endl;
  cout << "Czas: " << duration.count() << " mikrosekund" << endl;

    return 0;
}
