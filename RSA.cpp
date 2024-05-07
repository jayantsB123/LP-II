#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate gcd
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate modular exponentiation (base^exponent % modulus)
int modpow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{

    // Key Generation:
    // Choose two distinct prime numbers, p and q.
    // Calculate their product, n = p * q. This is used as the modulus for both the public and private keys.

    // Prime numbers
    int p = 31;
    int q = 29;
    int n = p * q;
    int totient = (p - 1) * (q - 1); // Calculate Euler's totient function, φ(n) = (p - 1) * (q - 1).

    // Public exponent
    int e = 65537; // Choose an integer e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1. This will be the public exponent.

    // Private exponent
    int d = 0; // Calculate the private exponent d such that (d * e) % φ(n) = 1.
    while (true)
    {
        if ((e * d) % totient == 1)
            break;
        d++;
    }

    // Encryption:
    // To encrypt a message m, compute c = m^e mod n.
    // Decryption:
    // To decrypt the ciphertext c, compute m = c^d mod n.

    // Message to be encrypted
    int msg = 12;

    // Encryption
    int c = modpow(msg, e, n);

    // Decryption
    int m = modpow(c, d, n);

    cout << "Message data = " << msg << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = pq = " << n << endl;
    cout << "totient = " << totient << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cout << "Encrypted data = " << c << endl;
    cout << "Original Message sent = " << m << endl;

    return 0;
}
