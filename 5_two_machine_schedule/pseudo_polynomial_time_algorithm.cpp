#include <iostream>
using namespace std;

const int MAXN = 1e3 + 10;

int work[MAXN];

int dp[MAXN][MAXN];


int schedule(int n)
{
	int totalTime = 0;
	for (int i = 0; i < n; i++)totalTime += work[i];
	int halfTime = totalTime / 2;
	for (int i = 0; i <= halfTime; i++)dp[0][i] = i >= work[0] ? work[0] : 0;
	for (int k = 1; k < n; k++)
	{
		for (int y = 0; y <= halfTime; y++)
		{
			if (y < work[k])dp[k][y] = dp[k - 1][y];
			else dp[k][y] = max(dp[k - 1][y], dp[k - 1][y - work[k]] + work[k]);
		}
	}
	return totalTime - dp[n - 1][halfTime];
}

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    cout << "Enter the time required for each task:\n";
    for (int i = 0; i < n; ++i) {
        cin >> work[i];
    }

    int result = schedule(n);
    cout << "Maximum value of tasks completed within time limit: " << result << endl;

    return 0;
}
