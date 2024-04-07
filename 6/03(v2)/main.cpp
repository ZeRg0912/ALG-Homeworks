#include <iostream>
#include <string>
#include <cmath>

typedef long long ll;

const int prime = 101;  // Простое число для хэширования

ll calculateHash(const std::string& s, int len) {
    ll hash = 0;
    for (int i = 0; i < len; i++) {
        hash += (ll)(s[i] * pow(prime, i));
    }
    return hash;
}

int rabinKarpSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    ll patternHash = calculateHash(pattern, m);
    ll textHash = calculateHash(text, m);

    for (int i = 0; i <= n - m; i++) {
        if (i == 0) {
            textHash = calculateHash(text, m);
        }
        else {
            textHash = textHash - text[i - 1];
            textHash = textHash / prime;
            textHash += (ll)(text[i + m - 1] * pow(prime, m - 1));
        }
        if (textHash != patternHash) {
            continue;
        }
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string text = "abracadabra";
    std::string pattern = "cad";
    int result = rabinKarpSearch(text, pattern);
    if (result != -1) {
        std::cout << "Найдено вхождение подстроки с позиции " << result << std::endl;
    }
    else {
        std::cout << "Подстрока не найдена" << std::endl;
    }
    return 0;
}
