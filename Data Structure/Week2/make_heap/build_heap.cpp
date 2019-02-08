#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;

class HeapBuilder final {
private:
	vector<int> data_;
	vector<pair<int, int>> swaps_;

	void WriteResponse() const {
		cout << swaps_.size() << "\n";
		for(const auto& swap : swaps_) { cout << swap.first << " " << swap.second << "\n"; }
	}

	void ReadData() {
		int n;
		cin >> n;
		data_.resize(n);
		for(auto i = 0; i < n; ++i) cin >> data_[i];
	}

	void SelectionSort() {
		// The following naive implementation just sorts 
		// the given sequence using selection sort algorithm
		// and saves the resulting sequence of swaps.
		for(unsigned int i = 0; i < data_.size(); ++i)
			for(auto j = i + 1; j < data_.size(); ++j) {
				if(data_[i] > data_[j]) {
					swap(data_[i], data_[j]);
					swaps_.emplace_back(i, j);
				}
			}
	}

	static unsigned int LeftChild(const int i) { return 2 * i + 1; }
	static unsigned int RightChild(const int i) { return 2 * i + 2; }

	void SiftDown(const int i) {
		auto max_index = i;
		const auto l_child = LeftChild(i);
		if(l_child < data_.size() && data_[l_child] < data_[max_index]) { max_index = l_child; }
		const auto r_child = RightChild(i);
		if(r_child < data_.size() && data_[r_child] < data_[max_index]) { max_index = r_child; }
		if(i != max_index) {
			swap(data_[i], data_[max_index]);
			swaps_.emplace_back(i, max_index);
			SiftDown(max_index);
		}
	}

	void BuildHeap() {
		const unsigned int size = data_.size();
		for(int i = (size - 1) / 2; i >= 0; i--) SiftDown(i);
	}

	void GenerateSwaps() {
		swaps_.clear(); 
		BuildHeap();
	}

public:
	void Solve() {
		ReadData();
		GenerateSwaps();
		WriteResponse();
	}
};

int main() {
	// NOLINT(bugprone-exception-escape)
	std::ios_base::sync_with_stdio(false);
	HeapBuilder heap_builder;
	heap_builder.Solve();
	return 0;
}
