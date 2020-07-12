#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;


int main() {

    int n, m, index, left, right, cmp;
    vector<pair<string, int>>pkmon;
    vector<string>quiz;
    vector<string>reply;
    string name, ask;

    cin >> n;
    cin >> m;
    if (n < 1 && n > 100000 || m < 1 && m > 100000)
        return 0;

    for (int i = 0; i < n; i++) {
        cin >> name;
        pkmon.push_back({ name, i + 1 });
    }

    for (int i = 0; i < m; i++) {
        cin >> name;
        quiz.push_back(name);
        reply.push_back("0");
    }

    for (int i = 0; i < m; i++) {               //quiz is number
        ask = quiz[i];
        if (isdigit(ask[0])) {
            index = stoi(ask) - 1;
            reply.insert(reply.begin() + i, pkmon[index].first);
        }
    }

    sort(pkmon.begin(), pkmon.end());           //ascending order

    for (int i = 0; i < m; i++) {

        ask = quiz[i];
        if (isdigit(ask[0])) {                 //quiz is number
            cout << reply[i] << endl;
            continue;
        }

        left = 0; right = n - 1;                //quiz is name
        while (left <= right) {
            index = (left + right) / 2;
            cmp = ask.compare(pkmon[index].first);
            if (cmp == 0) {
                cout << pkmon[index].second << endl;
                break;
            }
            else if (cmp > 0)
                left = index + 1;
            else
                right = index - 1;
        }
    }

    return 0;

}