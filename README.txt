Filip Emil Fllorentin - 323CB
<filipemil02@yahoo.com>
16.05.2023

FERIBOT
Citesc N si K si in timp ce fac citirea celor N numere fac si suma acestora pentru a o folosi in metoda mea cu cautare binara.
Cautarea binara consta in cautarea celui mai mic numar C(costul maxim de pe feriboturi).M-am folosit de o functie auxiliara care verifica daca pot
incapea pe cele K feriboturi toate masinile, astfel incat costul maxim de pe feriboturi sa fie cel dat ca parametru.Cu ajutorul cautarii binare,
caut cel mai mic numar care indeplineste conditia. Complexitate: O(N * log N) ( cat imi ia sa citesc toate numerele)

NOSTORY
La task-ul 1 , pun toate elementele intr-un vector si il sortez descrescator si fac suma primelor N elemente.
Complexitate : O(N * log N)
La task-ul 2 , fac la fel ca la task-ul 1 si imi mai fac inca un vector unde pun maximul dintre a[i] si b[i]( asa cum cere cerinta).
Sortez si cel de-al doilea vector descrescator.Atat timp cat mai am miscari disponibile, parcurg vectorii cu 2 indici, la inceput egali.
In momentul in care gasesc 2 elemente diferite(nu am luat in suma un element mare), cresc suma cu diferenta dintre elemtnul care ar fi trebuit
luat in suma si cel mai mic element pe care l-am luat in considerare, scad numarul de schimbari si imi cresc contorul pentru cel de-al doilea vector
pentru a nu lua in considerare si numerele mici cu care am facut schimbul anterior.
Complexitate: O(N * log N)

BADGPT
Citesc caracter cu caracter pana cand intalnesc "n" sau "u".In cazul in care nu intalnesc, am un flag care ramane setat pe 0 ceea ce inseamna ca nu avem siruri
distincte deci raspunsul este 0.In cazul in care am dat peste unul din cele 2 litere, pun flag-ul pe 1 pentru ca inseamna ca avem mai multe siruri.Citesc in
continuare caracter cu caracter pana la urmatoarea litera si in acelasi timp imi calculez numarul de dupa "u" sau "n".
Am vazut pe hartie ca pentru cazurile pana la 6 am sirul lui Fiboancci asa ca pentru fiecare numar calculez fibonacci.Am luat codul pentru fibonacci din curs unde
era scris in python si l-am transcris in C++.Mi-am facut si functii ajutatoare pentru inmultirea matricelor.
Complexitate: O(log n), n=cel mai mare nr de caractere dupa u sau n din fisier