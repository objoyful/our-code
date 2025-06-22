//******************************************
// This program shows the placement
// of declarations and assignment operations
//******************************************
#include <string>
using namespace std;
int main() {
  const string firstPart = "Programming and Problem ";
  const string secondPart = "Solving with C++";
  string bookTitle;
  string newEdition;
  bookTitle = firstPart + secondPart;
  newEdition = bookTitle + ", 7th Edition";
}
