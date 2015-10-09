def genPrimes(n):
    primesList = [2]
    for i in range(0,n):
        isPrime = False
        x = primesList[-1] + 1
        while not isPrime:
            isPrime = True
            for n in primesList:
                if x%n == 0:
                    isPrime = False
                    break
            if isPrime:
                primesList.append(x)
            else:
                x += 1
    return primesList

print genPrimes(1)
print genPrimes(2)
print genPrimes(3)
print genPrimes(10)
print genPrimes(20)