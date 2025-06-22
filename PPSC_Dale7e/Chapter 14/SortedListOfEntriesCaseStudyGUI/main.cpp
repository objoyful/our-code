#include <QApplication>

#include "EntriesWindow.h"
#include "EventHandlers.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  SortedList entries;
  EventHandlers handlers(entries);
  EntriesWindow window(handlers);
  window.show();

  return app.exec();
}
