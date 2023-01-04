// List all permutation of given set
// Le Minh Hoang book pg 9-10

#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 12

int main() {
    int n, i, k, a, b;
    int x[MAX];

    cin >> n;

    for (i = 1; i <= n; i++) x[i] = i; // x = 12..n (Initial configuration)
    do {
        // Print the current configuration
        for (i = 1; i <= n; i++) cout << x[i] << " ";
        cout << endl;

        // Generate the next configuration
        i = n - 1;

        // Consider elements from the end of the array upwards to find x[i] > x[i + 1]
        while (i > 0 && x[i] > x[i + 1]) --i;

        // If we haven't reached 0, it means we haven't reached the end configuration
        if (i > 0) {
            k = n; // x[k] is the last element of the array

            // Decrement k to find x[k] > x[i]
            while (x[k] < x[i]) --k;
            swap(x[k], x[i]);

            // Reverse the decreasing sequence at the end, a: start of the sequence, b: end of the sequence
            a = i + 1;
            b = n;
            while (a < b) {
                swap(x[a], x[b]);
                ++a;
                --b;
            }
        }
    } while (i > 0); // Reaching 0 means all elements is in the decreasing sequence and we have reached the end configuration

    return 0;
}