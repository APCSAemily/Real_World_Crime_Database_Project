#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

class Crime;

class BinaryHeap{
private:
  vector<Crime>crimeData;
  int parent(int i);
  int left(int i);
  int right(int i);

  void goUp(int i);
  void goDown(int i);

public:
  void insert(const Crime& c);
  Crime removeMax();
  bool isEmpty();
  void printTop(int n);

};
#endif
