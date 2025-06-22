#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "RelationType.h"

template <class ItemType>
void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped
{
  ItemType tempItem;
  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

template <class ItemType>
void Split(ItemType data[], int first, int last, int& splitPoint)
// Pre:  ComparedTo has been defined on ItemType
// Post: All items greater than split value are to the left and all
//       items less than or equal to split value are to the right
{
  ItemType splitVal = data[first];
  int saveFirst = first;
  bool onCorrectSide;

  first++;
  do {
    onCorrectSide = true;
    while (onCorrectSide)  // Move first toward last
      switch (data[first].ComparedTo(splitVal)) {
        case AFTER:
          onCorrectSide = false;
          break;
        case SAME:
        case BEFORE:
          first++;
          onCorrectSide = (first <= last);
          break;
      }
    onCorrectSide = (first <= last);
    while (onCorrectSide)  // Move last toward first
      switch (data[last].ComparedTo(splitVal)) {
        case SAME:
        case BEFORE:
          onCorrectSide = false;
          break;
        case AFTER:
          last--;
          onCorrectSide = (first <= last);
          break;
      }

    if (first < last) {
      Swap(data[first], data[last]);
      first++;
      last--;
    }
  } while (first <= last);

  splitPoint = last;
  Swap(data[saveFirst], data[splitPoint]);
}

template <class ItemType>
void Quicksort(ItemType data[], int first, int last)
// Pre:  ComparedTo has been defined on ItemType
// Post: data are sorted
{
  if (first < last) {
    int splitPoint;
    Split(data, first, last, splitPoint);
    // data[first]..data[splitPoint-1] <= splitVal
    // data[splitPoint] = splitVal
    // data[splitPoint+1]..data[last] > splitVal

    Quicksort(data, first, splitPoint - 1);
    Quicksort(data, splitPoint + 1, last);
  }
}

#endif  // QUICKSORT_H
