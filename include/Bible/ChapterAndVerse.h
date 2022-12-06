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
  int& bookDay,
  int& chapterDay,
  int& verseDay,
  vector<vector<int>>& readingPlan,
  vector<string> book,
  int days)
{
    int currentChapter = 0, currentBook = 0, currentVerse = 0;
    int verses;
    int currentDay = 0;
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
        cout << "on day " << day + 1 << " read until: " << book[currentBook] << " " << currentChapter + 1 << ":"
             << currentVerse + 1 << endl;
        currentDay = day;
    }
end:
    cout << "on day " << currentDay + 1 << " read until revelation 22:21" << endl;
}


}  // namespace Bible

/*
for (int day = 0; day < days; day++) {
    if (day == 0) { readingPlan.push_back({ 0, 0, 0 }); }
    int verses = 0;
    int difference = 0;
    vector<int> temp;
    for (auto book = readingPlan[day][0]; book < bookStats.size(); ++book) {
        cout << verses << " ";
        for (auto chapter = readingPlan[day][1]; chapter < chaptersInBook[book]; ++chapter) {
            if (verses < versesPerDay) {
                verses = verses + bookStats[book][chapter];
                bookDay = book + 1;
                chapterDay = chapter + 1;
            } else {
                goto end;
            }
        }
    }
end:
    difference = verses - versesPerDay;
    verseDay = bookStats[bookDay - 1][chapterDay - 1] - difference;
    temp = { bookDay - 1, chapterDay - 1, verseDay };
    readingPlan.push_back(temp);
    cout << "on day " << day + 1 << " read until: " << book[bookDay - 1] << " " << chapterDay << ":" << verseDay
         << endl;
    // cout << readingPlan[day + 1][0] << readingPlan[day + 1][1] << readingPlan[day + 1][2] << endl;
}
*/