#include "BinaryHeap.h"
using namespace std;

int BinaryHeap::parent(int i){return (i-1)/2;}
int BinaryHeap::left(int i) { return 2*i + 1;}
int BinaryHeap::right(int i){ return 2*i + 2;}

bool BinaryHeap::isEmpty(){
  return crimeData.empty(); }

void BinaryHeap::insert(const Crime& c){
  crimeData.push_back(c);
  goUp(crimeData.size() -1);
}
void BinaryHeap::goUp (int i ) {
  while(i>0 && crimeData[i].HOUR > crimeData[parent(i)].HOUR){
    swap(crimeData[i], crimeData[parent(i)]);
    i = parent(i);
  }
}
