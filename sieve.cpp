void sieveAndCountPrimes(int n, vector<int>& numPrimesUpTo) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;  

   
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

  
    numPrimesUpTo[0] = 0;
    for (int i = 1; i <= n; i++) {
        numPrimesUpTo[i] = numPrimesUpTo[i - 1] + (isPrime[i] ? 1 : 0);
    }
}



// sieve code to find number of primes from 1 to i
