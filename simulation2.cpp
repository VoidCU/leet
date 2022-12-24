#include <iostream>
#include <vector>

using namespace std;

vector<vector<float>> mulmat(vector<vector<float>> m1, vector<vector<float>> m2)
{
    int l1 = m1.size();
    int l2 = m1[0].size();
    int c1 = m2.size();
    int c2 = m2[0].size();
    vector<float> aa(c2, 0);
    vector<vector<float>> a(l1, aa);
    float val = 0;
    if (l2 != c1)
        cout << "error" << endl;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            val = 0;
            for (int k = 0; k < c1; k++)
            {
                val += m1[i][k] * m2[k][j];
            }
            a[i][j] = val;
        }
    }

    return a;
}

int main()
{
    int n = 3;
    cout << " Enter value of n: ";
    cin >> n;

    float a, b;
    cout << "Enter value of Q matrix [a b] (NOTE: a+b==1): ";
    cin >> a >> b;
    vector<vector<float>> Q{{a, b}};
    cout << "Enter probability of A buying A: ";
    cin >> a;
    cout << "Enter probability of B buying B: ";
    cin >> b;
    vector<vector<float>> P{{a, 1 - a}, {1 - b, b}};

    vector<vector<float>> ans;
    ans = mulmat(P, P);
    for (int i = 2; i < n; i++)
    {
        ans = mulmat(P, ans);
    }

    ans = mulmat(Q, ans);
    for (auto a : ans)
    {
        cout << "[ ";
        for (auto b : a)
            cout << b << " ";
        cout << "]" << endl;
    }
    return 0;
}