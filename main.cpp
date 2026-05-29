#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> minimizeCashFlow(
    vector<vector<string>>& transactions
) {
    unordered_map<string, long long> balance;

    // Step 1: Compute net balance
    for (auto &t : transactions) {
        string from = t[0];
        string to = t[1];
        long long amount = stoll(t[2]);

        balance[from] -= amount;
        balance[to] += amount;
    }

    // Step 2: Separate debtors and creditors
    vector<pair<string, long long>> debtors;
    vector<pair<string, long long>> creditors;

    for (auto &entry : balance) {
        string person = entry.first;
        long long amt = entry.second;

        if (amt < 0) {
            debtors.push_back({person, -amt});
        }
        else if (amt > 0) {
            creditors.push_back({person, amt});
        }
    }

    // Step 3: Greedy settlement
    vector<vector<string>> result;

    int i = 0, j = 0;

    while (i < debtors.size() && j < creditors.size()) {

        long long pay =
            min(debtors[i].second, creditors[j].second);

        result.push_back({
            debtors[i].first,
            creditors[j].first,
            to_string(pay)
        });

        debtors[i].second -= pay;
        creditors[j].second -= pay;

        if (debtors[i].second == 0)
            i++;

        if (creditors[j].second == 0)
            j++;
    }

    return result;
}

int main() {

    vector<vector<string>> transactions = {
        {"Tom", "Jerry", "1000"},
        {"Jerry", "Spike", "1000"},
        {"Spike", "Tom", "500"}
    };

    vector<vector<string>> ans =
        minimizeCashFlow(transactions);

    for (auto &t : ans) {
        cout << t[0] << " pays "
             << t[1] << " ₹"
             << t[2] << endl;
    }

    return 0;
}
