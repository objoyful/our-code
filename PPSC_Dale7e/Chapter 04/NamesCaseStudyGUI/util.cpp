#include "util.h"
#include "dialog.h"

string pathAppend(const string& p1, const string& p2) {
  char sep = '/';
  string tmp = p1;

#ifdef _WIN32
  sep = '\\';
#endif

  if (p1[p1.length()] != sep) {  // Need to add a
    tmp += sep;                  // path separator
    return (tmp + p2);
  } else
    return (p1 + p2);
}

void quitWithEmptyString(const string& p1) {
  if (p1 == "") {
    OutputDialog output("You did not provide an input to the GUI. Quitting!");
    output.display();
    exit(1);
  }
}

