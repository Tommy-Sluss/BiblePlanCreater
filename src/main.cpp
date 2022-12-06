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
    // cout << verseSum << endl;

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

    int option2;
    cout << "\nWould you like to start from Genesis 1:1 or input a Book/Chapter/Verse to start at?" << endl;
    cout << "Input: \n(1): Start from Beginning\n(2): Input Book/Chapter/Verse\n";
    cin >> option2;
    if (option2 == 1) {
        cout << "\nYou have chosen to start from Genesis 1:1" << endl;
        cout << "Writing the plan to a file\nThank you for creating a new plan!" << endl;
    } else {
        string book;
        int chapter;
        int verse;
        cout << "Please input the book you wish to start at\n";
        cin >> book;
        cout << "Please input the chapter you wish to start at\n";
        cin >> chapter;
        cout << "Please input the verse you wish to start at\n";
        cin >> verse;
        cout << "\n\nStarting a new plan at " << book << " " << chapter << ":" << verse << endl;
    }

    Bible::versePerDay(bookAVG, verseSum, days, versesPerDay);
    cout << "\nYou have to read: " << versesPerDay << " verses per day." << endl;
    Bible::readBookstats(bookFile, bookStats, chaptersInBook);
    vector<vector<int>> readingPlan;
    int currentDay = 0;
    Bible::chapterAndVerse(bookStats, chaptersInBook, versesPerDay, readingPlan, book, days, currentDay);
    int difference = days - currentDay;
    cout << "\nThis plan is created with: " << difference << " grace days" << endl;
}
