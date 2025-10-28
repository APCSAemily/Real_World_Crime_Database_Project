#include "BinaryHeap.h"
using namespace std;

int BinaryHeap::parent(int i){return (i-1)/2;}
int BinaryHeap::left(int i) { return 2*i + 1;}
int BinaryHeap::right(int i){ return 2*i + 2;}

bool BinaryHeap::isEmpty(){
  return crimeData.empty(); }
