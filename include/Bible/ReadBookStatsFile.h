#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace Bible {

void
readBookstats(const char* fname, vector<vector<int>>& bookStats, vector<int>& chaptersInBook)
{
    vector<string> row;
    string line, word;
    vector<vector<string>> book;
    vector<string> chapters;


    vector<string> verse;

    fstream file(fname, ios::in);
    int iter = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ',')) {
                if (word.empty()) {
                    row.push_back("0");
                } else {
                    row.push_back(word);
                }
            }
            book.push_back(vector<string>());
            chapters.push_back(row[1]);
            for (int i = 2; i < row.size(); i++) {
                // comment
                book[iter].push_back(row[i]);
            }
            iter++;
        }
    } else {
        cout << "could not open the file" << endl;
    }

    for (int i = 0; i < book.size(); i++) {
        bookStats.push_back(vector<int>());
        for (int j = 0; j < book[i].size(); j++) {
            int num = atoi(book[i].at(j).c_str());
            bookStats[i].push_back(num);
            // cout << bookStats[i][j] << endl;
            //  comment
        }
    }
    transform(chapters.begin(), chapters.end(), back_inserter(chaptersInBook), [&](std::string s) { return stoi(s); });
}

}  // namespace Bible