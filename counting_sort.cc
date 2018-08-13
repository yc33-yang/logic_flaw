#include <vector>

std::vector<int> CountingSort(std::vector<int> V) {
	std::vector<int> counting_array(V.size() + 10, 0);
	for (int i = 0; i < static_cast<int>(V.size()); ++i) {
		++counting_array[V[i]];
	}

	std::vector<int> sorted_array;
	for (int i = 0; i < static_cast<int>(counting_array.size()); ++i) {
		for (int j = 0; j < counting_array[i]; ++j) {
			sorted_array.push_back(i);
		}
	}

	return sorted_array;
}
