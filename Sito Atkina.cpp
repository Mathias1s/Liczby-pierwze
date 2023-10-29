#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;

int countPrimesMethodE(int n)
{
    if (n < 2) return 0;

    vector<bool> isPrime(n + 1, false);
    isPrime[2] = isPrime[3] = true;

    for (int x = 1; x * x <= n; ++x)
    {
        for (int y = 1; y * y <= n; ++y)
        {
            int num = (4 * x * x) + (y * y);
            if (num <= n && (num % 12 == 1 || num % 12 == 5))
            {
                isPrime[num] = true;
            }

            num = (3 * x * x) + (y * y);
            if (num <= n && (num % 12 == 7))
            {
                isPrime[num] = true;
            }

            num = (3 * x * x) - (y * y);
            if (x > y && num <= n && (num % 12 == 11))
            {
                isPrime[num] = true;
            }
        }
    }

    for (int i = 5; i * i <= n; ++i)
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
  int primeCount = countPrimesMethodE(n);
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end_time -     start_time);

  cout << "Metoda E (Sito Atkina): " <<endl;
  cout << primeCount << " liczb pierwszych" <<endl;
  cout << "Czas: " << duration.count() << " mikrosekund" << endl;

    return 0;
}
