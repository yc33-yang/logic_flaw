#include <vector>

std::vector<int> InsertionSort(std::vector<int> V) {
	bool is_array_sorted = true;
	for (int i = 0; i < static_cast<int>(V.size()) - 1; ++i) {
		if (V[i] > V[i + 1]) {
			is_array_sorted = false;
			break;
		}
	}
	if (is_array_sorted) {
		return V;
	}

	for (int i = 0; i < static_cast<int>(V.size()) - 1; ++i) {
		int min_index = 0;
		for (int j = i; j < static_cast<int>(V.size()); ++j) {
			if (V[min_index] > V[j]) {
				min_index = j;
			}
		}
		int temp = V[min_index];
		V[min_index] = V[i];
		V[i] = temp;
	}

	return V;
}
