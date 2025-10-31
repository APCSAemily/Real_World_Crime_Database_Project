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
Crime BinaryHeap::removeMax(){
  if(crimeData.empty()){
      Crime noCrime;
      noCrime.OFFENSE_DESCRIPTION = "no data";
      noCrime.HOUR = -1;
      return noCrime;
  }

Crime root = crimeData[0];
crimeData[0] = crimeData.back();
crimeData.pop_back();
goDown(0);
return root;
}

void BinaryHeap::goDown(int i){
  int size = crimeData.size();
int biggestI = i;
int leftChild = left(i);
int rightChild = right(i);

if(leftChild < size && crimeData[leftChild].HOUR > crimeData[biggestI].HOUR)
    biggestI = leftChild;
if(rightChild < size && crimeData[rightChild].HOUR > crimeData[biggestI].HOUR)
  biggestI = rightChild;
if (biggestI != i){
  swap(crimeData[i], crimeData[biggestI]);
  goDown(biggestI); 
}
}
