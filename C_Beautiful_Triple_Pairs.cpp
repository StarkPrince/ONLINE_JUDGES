#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the number of test cases

    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore(); // To ignore the newline after reading n
        vector<string> lt(n);
        string input_line;
        getline(cin, input_line);
        istringstream iss(input_line);
        for (int i = 0; i < n; i++)
        {
            iss >> lt[i];
        }

        unordered_map<string, unordered_set<int>> triplets;
        unordered_map<string, unordered_set<int>> dct1, dct2, dct3;

        for (int i = 0; i < n - 2; ++i)
        {
            string nm1 = lt[i] + " " + lt[i + 1];
            string nm2 = lt[i + 1] + " " + lt[i + 2];
            string nm3 = lt[i] + " " + lt[i + 2];
            if (dct1.find(nm1) == dct1.end())
            {
                dct1[nm1] = unordered_set<int>();
            }
            if (dct2.find(nm2) == dct2.end())
            {
                dct2[nm2] = unordered_set<int>();
            }
            if (dct3.find(nm3) == dct3.end())
            {
                dct3[nm3] = unordered_set<int>();
            }
            dct1[nm1].insert(i);
            dct2[nm2].insert(i);
            dct3[nm3].insert(i);
            string pm = lt[i] + " " + to_string(stoi(lt[i + 1]) * 10) + " " + lt[i + 2];
            if (triplets.find(pm) == triplets.end())
            {
                triplets[pm] = unordered_set<int>();
            }
            triplets[pm].insert(i);
        }

        long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
        for (const auto &p : dct1)
        {
            long long len = p.second.size();
            ans1 += len * (len - 1) / 2;
        }
        for (const auto &p : dct2)
        {
            long long len = p.second.size();
            ans2 += len * (len - 1) / 2;
        }
        for (const auto &p : dct3)
        {
            long long len = p.second.size();
            ans3 += len * (len - 1) / 2;
        }
        for (const auto &p : triplets)
        {
            long long len = p.second.size();
            ans4 += len * (len - 1) / 2;
        }

        cout << ans1 + ans2 + ans3 - 3 * ans4 << endl;
    }

    return 0;
}
