#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace Bible {

void
readStats(const char* fname, vector<int>& bookAVG, int& verseSum, vector<string>& book)
{
    vector<string> row;
    string line, word;

    vector<string> chapters;
    vector<string> verses;
    vector<int> chapter;
    vector<int> verse;


    fstream file(fname, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ',')) {
                row.push_back(word);
                // comment
            }
            book.push_back(row[0]);
            chapters.push_back(row[1]);
            verses.push_back(row[2]);
        }
    } else {
        cout << "could not open the file" << endl;
    }

    transform(chapters.begin(), chapters.end(), back_inserter(chapter), [&](std::string s) { return stoi(s); });
    transform(verses.begin(), verses.end(), back_inserter(verse), [&](std::string s) { return stoi(s); });

    int avg;
    for (int i = 0; i < book.size(); i++) {
        avg = verse[i] / chapter[i];
        bookAVG.push_back(avg);
    }

    for (int i = 0; i < book.size(); i++) { verseSum += verse[i]; }
}

}  // namespace Bible