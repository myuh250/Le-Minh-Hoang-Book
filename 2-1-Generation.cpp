// Generate a binary string with given n (n digit)
// Le Minh Hoang book pg 20

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAX 1000

int main() {
  int x[MAX], n, i;

  cin >> n;

  memset(x, 0, sizeof(x)); // Set x=00..0
  do {
    for (i = 1; i <= n; i++) cout << x[i]; // Print the current configuration
    cout << endl;

    i = n; // x[i] is the last element of the array, decrement i until a 0 is encountered or i = 0
    while (i > 0 && x[i] == 1) i--;

    if (i > 0) { // Haven't encountered configuration 11..1
      x[i] = 1; // Set x[i] to 1
      memset(x + i + 1, 0, (n - 1) * sizeof(x[0])); // Set x[i+1] = x[i+2] = ... = x[n] := 0
    }
  } while (i > 0); // Haven't run out of configurations
}
