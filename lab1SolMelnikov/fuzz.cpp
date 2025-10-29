#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <optional>
#include <algorithm>

using namespace std;

struct Rule {
    string left;
    string right;

    Rule(string l, string r) : left(std::move(l)), right(std::move(r)) {}
};

class RuleSystem {
public:
    explicit RuleSystem(vector<Rule> rules) : rules_(std::move(rules)) {}

    bool applyOnce(string& text) const {
        for (const auto& rule : rules_) {
            size_t pos = text.find(rule.left);
            if (pos != string::npos) {
                text.replace(pos, rule.left.size(), rule.right);
                return true;
            }
        }
        return false;
    }

    void normalize(string& text) const {
        while (applyOnce(text)) {}
    }

    vector<int> randomTransform(string& text, int steps) const {
        vector<int> path;
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, (int)rules_.size() - 1);

        for (int i = 0; i < steps; ++i) {
            int idx = dist(gen);
            path.push_back(idx);

            const auto& rule = rules_[idx];
            size_t pos = text.find(rule.left);
            if (pos != string::npos) {
                text.replace(pos, rule.left.size(), rule.right);
            }
        }
        return path;
    }

private:
    vector<Rule> rules_;
};

string getRandomString(int length, const string& alphabet = "abcd") {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, (int)alphabet.size() - 1);

    string s;
    s.reserve(length);
    for (int i = 0; i < length; ++i) s += alphabet[dist(gen)];
    return s;
}

struct FuzzResult {
    bool success;
    string finalString;
    vector<int> path;
};

FuzzResult fuzzTest(const RuleSystem& systemT, const RuleSystem& systemT2) {
    string s = getRandomString(6);
    string original = s;
    auto path = systemT.randomTransform(s, 7);
    string normalized = s;
    systemT2.normalize(normalized);

    bool ok = !normalized.empty();
    return {ok, s, path};
}
/*
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
        };*/
int main() {
    RuleSystem T({
        {"aa", "bb"},
        {"ccb", "dca"},
        {"a", "dcc"},
        {"cd", "bc"}
    });

    RuleSystem T2({
        {"aa", "bb"},
        {"ccb", "dca"},
        {"a", "dcc"},
        {"cd", "bc"},
        {"aabcd", "bbbbc"},
        {"aaaa", "bbbb"},
        {"abcbdb", "ddbcbcbc"},
        {"cccd", "dbcccc"},
        {"cbdcbcadcbd", "cbdcbcdccdbcd"},
        {"bcdacbdacd", "bcbdddcccbddcbccd"}
    });

    auto result = fuzzTest(T, T2);
    if (result.success) {
        cout << "Все тесты успешны\n";
    } else {
        cout << "Ошибка. Итоговая строка: " << result.finalString << "\n";
        cout << "Применённые правила: ";
        for (int i : result.path) cout << i << " ";
        cout << endl;
    }
}
