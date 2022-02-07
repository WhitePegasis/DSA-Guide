/*
Sum of digits (recursive)
Send Feedback
Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9
*/

#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if(n/10==0)
    {
        return n;
    }
    return sumOfDigits(n/10)+n%10;

}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}