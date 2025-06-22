//******************************************************************
// Favorite Rock Group program
// This program reads votes represented by level number and
// rock group number from a data file, calculates the sums per
// level and per rock group, and writes all totals to an
// output file
//******************************************************************
#include <fstream>  // For file I/O
#include <iomanip>  // For setw()
#include <iostream>
#include <string>  // For string type

#include "dialog.h"

using namespace std;

const int NUM_LEVELS = 4;
const int NUM_ROCK_GROUPS = 4;
typedef int VoteArray[NUM_LEVELS][NUM_ROCK_GROUPS];

void GetNames(string names[]);
// Rock group names have been prompted for and read
void OpenFiles(ifstream& voteFile, ofstream& reportFile);
// File names have been prompted for and read
void WritePerRockGroup(const VoteArray votes, const string name[],
                       ofstream& reportFile);
// The name of each rock group followed by the number of
// votes the group received have been written on reportFile
void WritePerLevel(const VoteArray votes, ofstream& reportFile);
// The level and the number of votes cast by the level
// have been written on reportFile
void WriteReport(const VoteArray votes, const string name[],
                 ofstream& reportFile);
// The array of votes has been written in tabular form on
// reportFile
void ZeroVotes(VoteArray votes);
// The array of votes has been set to all zeros

int main() {
  string name[NUM_ROCK_GROUPS];  // Array of rockGroup names
  VoteArray votes;               // Totals for level vs. rockGroups
  int rockGroup;                 // Group number from voteFile
  int level;                     // Level number input from voteFile
  ifstream voteFile;             // Input file of level, rockGroups
  ofstream reportFile;           // Output file receiving summaries

  OpenFiles(voteFile, reportFile);
  if (!voteFile || !reportFile) {
    cout << "Files did not open successfully." << endl;
    return 1;
  }

  GetNames(name);
  ZeroVotes(votes);

  // Read and tally votes
  voteFile >> level >> rockGroup;
  while (voteFile) {
    votes[level - 1][rockGroup - 1]++;
    voteFile >> level >> rockGroup;
  }
  WriteReport(votes, name, reportFile);
  WritePerRockGroup(votes, name, reportFile);
  WritePerLevel(votes, reportFile);
  return 0;
}

//******************************************************************

void OpenFiles(ifstream& text, ofstream& outFile) {
  string inFileName;
  string outFileName;

  // Add a GUI widget for input
  FileDialog chooseInput("Choose the file to be processed");
  inFileName = chooseInput.display();
  text.open(inFileName.c_str());

  // Add a GUI widget for output
  NewFileDialog chooseOutput("Choose the name of the output file");
  outFileName = chooseOutput.display();
  outFile.open(outFileName.c_str());
  outFile << "Analysis of exams on file " << inFileName << endl << endl;
}

//******************************************************************

void GetNames(string name[]) {
  string inputStr;
  int rockGroup;

  for (rockGroup = 0; rockGroup < NUM_ROCK_GROUPS; rockGroup++) {
    // Add a GUI widget for input
    TextDialog getRockGroup("Enter the name of a rock group");
    inputStr = getRockGroup.display();
    name[rockGroup] = inputStr.substr(0, 16);
  }
}

//******************************************************************

void ZeroVotes(VoteArray votes) {
  int level;
  int rockGroup;
  for (level = 0; level < NUM_LEVELS; level++)
    for (rockGroup = 0; rockGroup < NUM_ROCK_GROUPS; rockGroup++)
      votes[level][rockGroup] = 0;
}

//******************************************************************

void WriteReport(const VoteArray votes, const string name[],
                 ofstream& reportFile) {
  int level;
  int rockGroup;

  reportFile << "            ";
  for (rockGroup = 0; rockGroup < NUM_ROCK_GROUPS; rockGroup++)
    reportFile << setw(17) << name[rockGroup];
  reportFile << endl;

  // Print array by row
  for (level = 0; level < NUM_LEVELS; level++) {
    reportFile << "level" << setw(4) << level + 1;
    for (rockGroup = 0; rockGroup < NUM_ROCK_GROUPS; rockGroup++)
      reportFile << setw(17) << votes[level][rockGroup];

    reportFile << endl << endl;
  }
}

//******************************************************************

void WritePerRockGroup(const VoteArray votes, const string name[],
                       ofstream& reportFile) {
  int level;
  int rockGroup;
  int total;  // Total votes for a rockGroup

  for (rockGroup = 0; rockGroup < NUM_ROCK_GROUPS; rockGroup++) {
    total = 0;

    // Compute column sum
    for (level = 0; level < NUM_LEVELS; level++)
      total = total + votes[level][rockGroup];
    reportFile << "Total votes for " << setw(17) << name[rockGroup] << ":"
               << setw(3) << total << endl;
  }
  reportFile << endl;
}

//******************************************************************
void WritePerLevel(const VoteArray votes, ofstream& reportFile) {
  int level;
  int rockGroup;
  int total;

  for (level = 0; level < NUM_LEVELS; level++) {
    total = 0;

    // Compute row sum
    for (rockGroup = 0; rockGroup < NUM_ROCK_GROUPS; rockGroup++)
      total = total + votes[level][rockGroup];

    reportFile << "Total votes for level" << setw(3) << level + 1 << ':'
               << setw(5) << total << endl;
  }
}
