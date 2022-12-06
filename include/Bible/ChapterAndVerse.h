#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace Bible {

void
chapterAndVerse(vector<vector<int>>& bookStats,
  vector<int>& chaptersInBook,
  int versesPerDay,

  vector<vector<int>>& readingPlan,
  vector<string> book,
  int days,
  int& currentDay)
{
    int currentChapter = 0, currentBook = 0, currentVerse = 0;
    int verses;
    for (int day = 0; day < days; day++) {
        if (day == 0) { readingPlan.push_back({ 0, 0, 0 }); }
        while (verses < versesPerDay) {
            verses = verses + bookStats[currentBook][currentChapter];
            currentVerse = verses - versesPerDay;
            if (currentChapter < bookStats[currentBook].size()) {
                // cout << currentBook << " " << currentChapter << ":" << currentVerse << endl;
                //  placeholder
                currentChapter++;
                if (currentBook == 65 && currentChapter == 21) {
                    currentDay++;
                    goto end;
                }
            } else {
                currentBook++;
                currentChapter = 0;
            }
        }

        verses = 0;
        // cout << "on day " << day + 1 << " read until: " << book[currentBook] << " " << currentChapter + 1 << ":" <<
        // currentVerse + 1 << endl;
        currentDay = day;
    }
end:
    cout << "\n" << endl;
    // cout << "on day " << currentDay + 1 << " read until revelation 22:21" << endl;
}


}  // namespace Bible
