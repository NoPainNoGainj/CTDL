#include <stdlib.h>
#include <stdio.h>
#include <stack>  // Stack library in C++

using namespace std;

int main() {
    stack<int> S;  // Declare a stack of integers
    int coso, so, du;

    // Input the number 'so' and the base 'coso' to convert
    printf("Nhap so can chuyen: ");
    scanf("%d", &so);
    printf("Nhap co so can chuyen: ");
    scanf("%d", &coso);

    // Convert the number 'so' into the given base 'coso' using a stack
    while (so) {
        du = so % coso;  // Find the remainder (du)
        S.push(du);      // Push the remainder into the stack
        so /= coso;      // Divide the number by the base 'coso'
    }

    // Output the digits in the new base
    while (!S.empty()) {
        printf("%d", S.top());  // Print the top element of the stack
        S.pop();                // Remove the top element
    }

    return 0;
}

