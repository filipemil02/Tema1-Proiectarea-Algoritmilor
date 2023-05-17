#include <ctype.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long K = 1000000007;

vector < vector < long long > > inmultireM(vector < vector < long long > > A,
  vector < vector < long long > > B) {
  // vector < vector < long long> > C {
  //   { (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % K,
  //     (A[0][0] * B[0][1] + A[0][1] * B[1][1])  % K },
  //   { (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % K,
  //     (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % K }
  // };
  return vector < vector < long long> > {
    { (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % K,
      (A[0][0] * B[0][1] + A[0][1] * B[1][1])  % K },
    { (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % K,
      (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % K }
  };
}

vector < long long > inmultireV(vector < vector < long long > > A,
vector < int > x) {
  // vector < long long > y {
  //   ( (A[0][0] * x[0]) + (A[0][1] * x[1])) % K,
  //   ( (A[1][0] * x[0]) + (A[1][1] * x[1])) % K
  // };
  return vector < long long > {
    ( (A[0][0] * x[0]) + (A[0][1] * x[1])) % K,
    ( (A[1][0] * x[0]) + (A[1][1] * x[1])) % K
  };
}

vector < vector < long long > > matrix_pow(vector < vector < long long > > A,
long long n) {
  if ( n == 1 )
    return A;
  if ( n == 0 ) {
    A[0][0] = 1;
    A[0][1] = 0;
    A[1][0] = 0;
    A[1][1] = 1;
    return A;
  }
  vector < vector < long long > > A1 = matrix_pow(A, n / 2);
  vector < vector < long long > > A2 = inmultireM(A1, A1);
  if ( n % 2 == 0 )
    return A2;
  return inmultireM(A, A2);
}


long long fibo_quick(long long n) {
  if ( 0 <= n  && n <= 1 )
    return n;
  vector < vector <long long> > A = {
    {0, 1},
    {1, 1}
  };
  // transpose
  vector < int > x {0, 1};
  vector < vector < long long > > An = matrix_pow(A, n - 1);
  return (inmultireV(An, x))[1];
}


int main() {
  FILE* file = fopen("badgpt.in", "r");
  ifstream in("badgpt.in");
  ofstream out("badgpt.out");
  int flag = 0;
  long long rez = 1;
  int cont = 0;
  char x;
  in >> x;
  /*const int MAX_SIZE = 2000000;
  char buffer[MAX_SIZE];
  int len = 0;
while ((len = fread(buffer, sizeof(char), MAX_SIZE, file)) > 0){
  for (int i = 0; i < len; i++) {
      if (buffer[i] == 'u' || buffer[i] == 'n') {
      long long nr = 0;
      i++;
      while ( i < len && isdigit(buffer[i]) != 0) {
        nr = nr * 10 + (buffer[i++] - '0');
      }
      --i;
      //out << nr << " ";
      rez = rez * fibo_quick(nr+1) % K;
    }
}
}*/
  while ( !in.eof() ) {
    if (x == 'u' || x == 'n') {
      long long nr = 0;
      while ( in >> x && (isdigit(x) != 0 ) ) {
        nr = nr * 10 + (x - '0');
      }
      // out << nr << " ";
      rez = rez * fibo_quick(nr+1) % K;
    } else {
      in >> x;
    }
  }
  in.close();
  out << rez;
  out.close();
}
