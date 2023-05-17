#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
	int bani = n * x;
    vector< vector<int> > dp(m + 1, vector<int>(bani + 1, 0));
	vector <int> buget(m);
	for (int i =0 ; i < m ; i++)
		for (int j =0 ; j < n ; j++)
			buget[i] += g[j][i];
    for (int i = 1; i <= m; ++i) {
        for (int cap = 0; cap <= bani; ++cap) {
            dp[i][cap] = dp[i-1][cap];
            if (cap - p[i - 1] >= 0) {
                int sol_aux = dp[i-1][cap - p[i - 1]] + buget[i - 1];
                dp[i][cap] = max(dp[i][cap], sol_aux);
            }
        }
    }
    return dp[m][bani];
}

int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	int bani = n * x;
    vector< vector<int> > dp(m + 1, vector<int>(bani + 1, 0));
	vector <int> buget(m);
	for (int i =0 ; i < m ; i++)
		for (int j =0 ; j < n ; j++)
			buget[i] += g[j][i];
    for (int i = 1; i <= m; ++i) {
        for (int cap = 0; cap <= bani; ++cap) {
            dp[i][cap] = dp[i-1][cap];
            if (cap - p[i - 1] >= 0) {
                int sol_aux = dp[i-1][cap - p[i - 1]] + buget[i - 1];
                dp[i][cap] = max(dp[i][cap], sol_aux);
            }
			if (cap - p[i - 1]*2 >= 0) {
                int sol_aux = dp[i-1][cap - p[i - 1]*2] + buget[i - 1]*2;
                dp[i][cap] = max(dp[i][cap], sol_aux);
            }
        }
    }
    return dp[m][bani];
}

int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	return 0;
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
