// 1666 统计单词数
// 第1行给定单词（只含字母），第2行文章（字母和空格）。
// 忽略大小写、完全匹配（独立单词），输出出现次数与首次出现的位置（从0开始）。
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string toLowerStr(string s) {
    for (char &c : s) c = (char)tolower((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word, article;
    if (!getline(cin, word)) return 0;
    if (!getline(cin, article)) return 0;

    // 去掉行尾可能存在的 '\r'
    if (!word.empty() && word.back() == '\r') word.pop_back();
    if (!article.empty() && article.back() == '\r') article.pop_back();

    string w = toLowerStr(word);
    string a = toLowerStr(article);

    int count = 0;
    int firstPos = -1;

    int n = (int)a.size();
    int i = 0;
    while (i < n) {
        if (a[i] == ' ') { i++; continue; }
        int start = i;
        while (i < n && a[i] != ' ') i++;
        if (i - start == (int)w.size() && a.compare(start, i - start, w) == 0) {
            count++;
            if (firstPos == -1) firstPos = start;
        }
    }

    if (count == 0) cout << -1 << "\n";
    else cout << count << " " << firstPos << "\n";
    return 0;
}
