// List all subset from given set of element k
// Le Minh Hoang book pg 8

#include <iostream>

using namespace std;

#define max 30

int main() {
  int x[max];
  int n, k, i, j;

  cin >> n >> k;

  for (i = 1; i <= k; i++) x[i] = i; // x := 12 k (Initial configuration)

  do {
    // Print the current configuration
    cout << '{';
    for (i = 1; i < k; i++) cout << x[i] << ", ";
    cout << x[k] << '}' << endl;

    // Generate the next configuration
    i = k; 

    // Consider elements from the end of the array upwards to find x[i] that has not reached the upper limit n - k + i
    while (i > 0 && x[i] == n - k + i) i--;

    // If we haven't reached 0, it means we haven't reached the end configuration
    if (i > 0) { 
        // Increase x[i] by 1, set the correct elements after x[i] to their lower limit
        x[i]++; 
        for (j = i + 1; j <= k; j++) x[j] = x[j-1] + 1;
    }
  } while (i > 0); // Reaching 0 means all elements have reached their upper limit and we have reached the end configuration
  return 0;
}