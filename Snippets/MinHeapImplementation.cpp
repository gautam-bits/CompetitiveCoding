#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int Parent(int i) { return (i-1)/2; }

  int LeftChild(int i) { return (i<<1) + 1; }

  int RightChild(int i) { return (i<<1) + 2; } 

  void ShiftUp(int i) {              //O(logn)
    if(i > 0 && data_[Parent(i)] > data_[i]) {
      swap(data_[Parent(i)],data_[i]);
      ShiftUp(Parent(i));
    }
  }

  void ShiftDown(int i) {          //O(logn)  //with print overload
    int minidx = i;

    int l = LeftChild(i);
    int r = RightChild(i);

    if(l < data_.size() && data_[l] < data_[minidx] ){
      minidx = l;
    }

    if(r < data_.size() && data_[r] < data_[minidx] ){
      minidx = r;
    }

    if(i != minidx){
      swap(data_[i],data_[minidx]);
      swaps_.push_back(make_pair(i,minidx));
      ShiftDown(minidx);

    }


  }

  void GenerateSwaps() {
    swaps_.clear();

    int n = data_.size();

    for(int i = n/2 - 1; i >=0;i--){
      ShiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
