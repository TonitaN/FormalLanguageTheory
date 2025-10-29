#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <utility>

using namespace std;
struct Rule {
    string l, r;
    Rule(string left, string right) : l(move(left)), r(move(right)) {}
};

struct InvariantCheckResult {
    bool success = true;
    string failedString;
    int ruleIndex = -1;
    int invariantIndex = -1;
};

// ===============================
//         ИНВАРИАНТЫ
// ===============================

namespace invariants {

    // 1. (#a + #b + #c + #d) mod 2 
    bool parityInvariant(const string& prev, const string& curr) {
        auto countAll = [](const string& s) {
            int cnt = 0;
            for (auto ch : s)
                if (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd')
                    cnt++;
            return cnt;
        };
        return (countAll(prev) % 2) == (countAll(curr) % 2);
    }

    // 2. (#a + 3*#b + #c + 3*#d) mod 4 
    bool weightedInvariant(const string& prev, const string& curr) {
        auto weighted = [](const string& s) {
            int sum = 0;
            for (auto ch : s) {
                if (ch == 'a' || ch == 'c') sum += 1;
                else if (ch == 'b' || ch == 'd') sum += 3;
            }
            return sum;
        };
        return (weighted(prev) % 4) == (weighted(curr) % 4);
    }

}

//класс переписывания

class RewritingSystem {
    mt19937 gen{ random_device{}() };

public:
    vector<Rule> rules;
    string alphabet = "abcd";

    void initRules() {
        rules = {
            {"aa", "bb"},
            {"ccb", "dca"},
            {"a", "dcc"},
            {"cd", "cb"},
            {"aabcd", "bbbbc"},
            {"aaaa", "bbbb"},
            {"abcbdb", "ddbcbcbc"},
            {"cccd", "dbcccc"},
            {"cbdcbcadcbd", "cbdcbcdccdbcd"},
            {"bcdacbdacd", "bcbdddcccbddcbccd"}
        };
    }

    string randomString(int n) {
        uniform_int_distribution<int> dist(0, alphabet.size() - 1);
        string s;
        for (int i = 0; i < n; ++i)
            s += alphabet[dist(gen)];
        return s;
    }

    int randomRuleIndex() {
        uniform_int_distribution<int> dist(0, rules.size() - 1);
        return dist(gen);
    }

    pair<bool, int> findRule(const Rule& rule, const string& s) {
        size_t pos = s.find(rule.l);
        return { pos != string::npos, static_cast<int>(pos) };
    }

    void applyRule(string& s, const Rule& rule, int pos) {
        s.replace(pos, rule.l.size(), rule.r);
    }
};

// проверка инвариантов

InvariantCheckResult checkString(
    RewritingSystem& rs,
    string s,
    bool (*invariant)(const string&, const string&),
    int invariantIndex,
    int maxAttempts = 7
) {
    InvariantCheckResult result;
    int n = rs.rules.size();

    for (int i = 0; i < maxAttempts; ++i) {
        int ruleNum = rs.randomRuleIndex();
        const Rule& rule = rs.rules[ruleNum];
        auto [canApply, pos] = rs.findRule(rule, s);

        if (!canApply)
            continue;

        string prev = s;
        rs.applyRule(s, rule, pos);

        if (!invariant(prev, s)) {
            result.success = false;
            result.failedString = prev;
            result.ruleIndex = ruleNum;
            result.invariantIndex = invariantIndex;
            return result;
        }
    }
    return result;
}

InvariantCheckResult runInvariantTests(
    RewritingSystem& rs,
    bool (*invariant)(const string&, const string&),
    int invariantIndex,
    int iterations = 50000
) {
    for (int i = 0; i < iterations; ++i) {
        string s = rs.randomString(15);
        auto res = checkString(rs, s, invariant, invariantIndex);
        if (!res.success)
            return res;
    }
    return {};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    RewritingSystem rs;
    rs.initRules();

    vector<bool (*)(const string&, const string&)> invariantFuncs = {
        invariants::parityInvariant,
        invariants::weightedInvariant
    };

    int num = 0;
    for (auto invariant : invariantFuncs) {
        auto result = runInvariantTests(rs, invariant, num);

        cout << "Инвариант №" << num << ":\n";
        if (result.success) {
            cout << "   Все тесты успешны.\n";
        } else {
            cout << "   Нарушение найдено!\n";
            cout << "  Строка: " << result.failedString << "\n";
            cout << "  Применено правило: "
                 << rs.rules[result.ruleIndex].l << " -> "
                 << rs.rules[result.ruleIndex].r << "\n";
        }
        cout << '\n';
        ++num;
    }
}
