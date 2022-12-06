#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace Bible {

void
versePerDay(vector<int>& bookAVG, int& verseSum, int days, int& versesPerDay)
{
    // comment here
    versesPerDay = verseSum / days;
}

}  // namespace Bible