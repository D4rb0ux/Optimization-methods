#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, W;
    cin >> N;
    vector<int> w(N);
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> w[i];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    cin >> W;

    vector<int> m(W + 1);

    for (int i = 0; i < N; i++) {
        for (int space = W; space >= 1; space--) {
            int val_withoutCurr = m[space];
            int val_withCurr = 0;
            int weight_Curr = w[i];

            if (space >= weight_Curr) {
                val_withCurr = v[i];
                int rem_space = space - weight_Curr;
                val_withCurr += m[rem_space];
            }

            m[space] = max(val_withCurr, val_withoutCurr);
        }
    }

    cout << W << " " << m[W] << '\n';
    return 0;
}
