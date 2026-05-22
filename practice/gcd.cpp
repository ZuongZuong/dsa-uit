#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void print_butterfly_pattern(int n)
{
    if (n == 1)
    {
        std::cout << "*";
    }
    int left = 0;
    int right = n * 2 - 1;

    while (left < right)
    {
        if (left == right)
        {
            
        }
        
    }
        
}

int main()
{
    // int num1, num2;
    // cout << "Enter two numbers: ";
    // cin >> num1 >> num2;
    // cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
    print_butterfly_pattern(3);

    return 0;
}
