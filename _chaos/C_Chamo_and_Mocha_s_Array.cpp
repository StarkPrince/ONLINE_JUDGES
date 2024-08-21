#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int mx = *max_element(a.begin(), a.end());
        if (find(a.begin(), a.end(), mx) != a.end() - 1)
        {
            cout << mx << endl;
        }
        else
        {
            sort(a.begin(), a.end());
            cout << a[n - 2] << endl;
        }
    }
    return 0;
}
