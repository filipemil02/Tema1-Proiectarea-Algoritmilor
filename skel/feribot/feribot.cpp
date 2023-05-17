#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;


bool numarMaxim(vector<long long> greutati,
                long long nrCrt,
                int nrElem,
                int feriboturi) {
    int cont  = 1;
    long long suma = 0;
    while (cont <= nrElem) {
        if (greutati[cont] > nrCrt)
            return false;
        if (suma + greutati[cont] <= nrCrt) {
            suma += greutati[cont++];
        } else {
            suma = greutati[cont++];
            feriboturi--;
        }
    }
    if (feriboturi <= 0)
        return false;
    return true;
}

long long cautareBinara(long long lo,
                        long long hi,
                        vector<long long> greutati,
                        int nrElem,
                        int feriboturi) {
    if (lo == hi)
        return lo;
    long long mid = (lo + hi) / 2;
    if (numarMaxim(greutati, mid, nrElem, feriboturi) == true)
        return cautareBinara (lo, mid, greutati, nrElem, feriboturi);
    else
        return cautareBinara (mid + 1, hi, greutati, nrElem, feriboturi);
}



int main() {
    int N, K, copien, i = 1;
    long long elMax = 0;
    long long suma = 0;
    ifstream in("feribot.in");
    ofstream out("feribot.out");
    in >> N >> K;
    vector<long long> greutati(N+1);
    copien = N;
    while (copien != 0) {
        in >> greutati[i];
        suma+= greutati[i];
        if (elMax < greutati[i])
            elMax = greutati[i];
        i++;
        copien--;
    }
    out << cautareBinara(0, suma, greutati, N, K);
}
