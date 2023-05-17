/*
 * Acest schelet citește datele de intrare și scrie răspunsul generat de voi,
 * astfel că e suficient să completați cele două funcții.
 *
 * Scheletul este doar un punct de plecare, îl puteți modifica oricum doriți:
 * puteți schimba parametrii, reordona funcțiile etc.
 */

#include <cstdint>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxim(int a, int b) {
    if (a < b)
        return b;
    return a;
}

int64_t SolveTask1(const vector<int>& a, const vector<int>& b) {
    vector<int> c(2*a.size()+1);
    int i, cont;
    for (i = 0 ; i < a.size(); i++)
        c[i] = a[i];
    cont = i;
    for (i = 0 ; i < a.size(); i++)
        c[cont + i] = b[i];
    sort(c.begin(), c.end(), greater<int>());
    long long suma = 0;
    for (i = 0 ; i < a.size() ; i++)
        suma+=c[i];
    return suma;
}


int64_t SolveTask2(const vector<int>& a, const vector<int>& b, int moves) {
    int len = a.size();
    long long suma = 0;
    vector<int> c(2*len+1);
    vector<int> d(len+1);
    int i, cont, elMij;
    for (i = 0 ; i < len; i++) {
        c[i] = a[i];
        c[len + i] = b[i];
    }
    sort(c.begin(), c.end(), greater<int>());
    for (i = 0; i < len; i++) {
        d[i] = maxim(a[i], b[i]);
        suma+=d[i];
    }
    sort(d.begin(), d.end(), greater<int>());
    i = 0;
    int schimbari = 0;
    while (moves != 0) {
        if (c[i] != d[i-schimbari]) {
            suma+=c[i]-d[len-1-schimbari];
            moves--;
            schimbari++;
        }
        i++;
        if (i == len)
            break;
    }
    return suma;
}

vector<int> ReadVector(istream& is, int size) {
    vector<int> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(a, b, moves);
    fout << res << "\n";

    return 0;
}
