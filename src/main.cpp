#include <Bible/ChapterAndVerse.h>
#include <Bible/ReadBookStatsFile.h>
#include <Bible/ReadStatsFile.h>
#include <Bible/VersesPerDay.h>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;


int
main()
{
    // Here is a comment
    int days;
    vector<int> bookAVG;
    int verseSum;
    int versesPerDay;
    vector<vector<int>> bookStats;
    vector<int> chaptersInBook;
    int bookDay, chapterDay, verseDay;
    vector<string> book;

    const char* file = "BibleStats.csv";
    const char* bookFile = "BookStats.csv";

    Bible::readStats(file, bookAVG, verseSum, book);
    cout << verseSum << endl;

    int option;
    cout << "Input: \n(1): Input number of days\n(2): Input date\n";
    cin >> option;
    if (option == 1) {
        cout << "Please enter how many days you wish your Bible Plan to take: " << endl;
        cin >> days;
    } else {
        char dateString1[100];
        time_t currTime;
        tm* currTm;
        time(&currTime);
        currTm = localtime(&currTime);
        strftime(dateString1, 50, "DD/MM/YY: %d/%m/%Y", currTm);
        tm tmb;
        cout << "Please input the date you wish to finish reading\n In this format: DD/MM/YYYY\n";
        cin >> get_time(&tmb, "%d/%m/%Y");
        // cout << tmb;
        time_t time1 = mktime(currTm);
        time_t time2 = mktime(&tmb);

        const int seconds_per_day = 60 * 60 * 24;
        // time_t difference = (time1 - time2) / seconds_per_day;
        int portable_difference = difftime(time1, time2) / seconds_per_day;
        days = abs(portable_difference);
        cout << days << endl;
    }

    Bible::versePerDay(bookAVG, verseSum, days, versesPerDay);
    cout << "You have to read: " << versesPerDay << " verses per day." << endl;
    Bible::readBookstats(bookFile, bookStats, chaptersInBook);
    vector<vector<int>> readingPlan;
    Bible::chapterAndVerse(
      bookStats, chaptersInBook, versesPerDay, bookDay, chapterDay, verseDay, readingPlan, book, days);
}
