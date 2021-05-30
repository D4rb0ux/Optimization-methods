#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long> ans;

void Find_Knapsack_Objects(unsigned long k, unsigned long s, vector<vector<unsigned long>>& A, vector<unsigned long>& w) {
    if (A[k][s] == 0)
        return;
    if (A[k - 1][s] == A[k][s])
        Find_Knapsack_Objects(k - 1, s, A, w);
    else {
        Find_Knapsack_Objects(k - 1, s - w[k], A, w);
        ans.push_back(k);
    }
}

int main()
{
    unsigned long N, W;
    cin >> N;
    vector<unsigned long> w(N);
    vector<unsigned long> p(N);
    for (unsigned long i = 0; i < N; i++)
        cin >> w[i];
    for (unsigned long i = 0; i < N; i++)
        cin >> p[i];
    cin >> W;

    vector<vector<unsigned long>> A(N + 1, vector<unsigned long>(W + 1, 0));
    for (unsigned long i = 0; i < N; i++)
        A[i][0] = 0;
    for (unsigned long i = 0; i < W; i++)
        A[0][i] = 0;

    for (unsigned long k = 1; k <= N; k++) {
        for (unsigned long s = 1; s <= W; s++) {
            if (s >= w[k])
                A[k][s] = max(A[k - 1][s], A[k - 1][s - w[k]] + p[k]);
            else
                A[k][s] = A[k - 1][s];
        }
    }

    Find_Knapsack_Objects(N, W, A, w);

    unsigned long total_weight = 0, total_price = 0;
    for (unsigned long i = 0; i < ans.size(); i++) {
        total_weight += w[ans[i]];
        total_price += p[ans[i]];
    }

    cout << total_weight << " " << total_price;
    return 0;
}
