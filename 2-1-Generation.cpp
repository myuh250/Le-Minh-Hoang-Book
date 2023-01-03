// Generate a binary string with given n (n digit)
// Le Minh Hoang book pg 6

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 30

int main() {
  int x[MAX], n, i;

  cin >> n;
  
  // Set x=00..0
  memset(x, 0, sizeof(x)); 
  do {
    // Print the current configuration
    for (i = 1; i <= n; i++) cout << x[i]; 
    cout << endl;

    i = n; // x[i] is the last element of the array, decrement i until a 0 is encountered or i = 0
    while (i > 0 && x[i] == 1) i--;
  
    // Haven't encountered configuration 11..1
    if (i > 0) { 
      // Set x[i] to 1
      x[i] = 1; 
      // Set x[i+1] = x[i+2] = ... = x[n] := 0
      memset(x + i + 1, 0, (n - 1) * sizeof(x[0])); 
    }
  } while (i > 0); // Haven't run out of configurations
}
