#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

struct Lyricsong {
    string text;
    double charDelay;
};

void animateText(const string &text, double charDelay) {
    for (char ch : text) {
        cout << ch << flush;
        this_thread::sleep_for(chrono::duration<double>(charDelay));
    }
    cout << endl;
}

int main() {
    vector<Lyricsong> lyrics = {
        {"\nCause there is something", 0.06},
        {"and there is nothing", 0.09},
        {"and there is nothing", 0.09},
        {"in-between", 0.09},
        {"And in my eyes", 0.10},
        {"there is a tiny dancer ", 0.12},
        {"watching over me ", 0.09},
        {"He's singing, She's a, she's a lady ", 0.12},
        {"and I am just a boy ", 0.11},
        {"He's singing, She's a, she's a lady ", 0.12},
        {"and I am just a line without a", 0.10}
    };

    vector<double> delays = {0.9, 0.9, 0.9, 0.9, 1.2, 1.1, 0.9, 1.2, 1.0, 1.2, 0.9};

    for (size_t i = 0; i < lyrics.size(); ++i) {
        animateText(lyrics[i].text, lyrics[i].charDelay);
        if (i < lyrics.size() - 1) {
            double nextLineDelay = max(0.0, delays[i] - lyrics[i].text.length() * lyrics[i].charDelay);
            this_thread::sleep_for(chrono::duration<double>(nextLineDelay));
        }
    }

    return 0;
}
