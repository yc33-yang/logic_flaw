
#include <vector>

std::vector<int> FilterLessThan(std::vector<int> V, int pivot) {
	std::vector<int> result;

	 for (int elem : V) {
		 if (elem < pivot) {
			 result.push_back(elem);
		 }
	 }

	 return result;
 }

 std::vector<int> FilterGreaterThan(std::vector<int> V, int pivot) {
	 std::vector<int> result;

	 for (int elem : V) {
		 if (elem > pivot) {
			 result.push_back(elem);
		 }
	 }

	 return result;
 }

 std::vector<int> QuickSort(std::vector<int> V) {
	 if (static_cast<int>(V.size()) <= 1) {
		 return V;
	 }

	 int pivot = V.back();
	 V.pop_back();

	 std::vector<int> result;
	 for (int elem : QuickSort(FilterLessThan(V, pivot))) {
		 result.push_back(elem);
	 }
	 result.push_back(pivot);
	 for (int elem : QuickSort(FilterGreaterThan(V, pivot))) {
		 result.push_back(elem);
	 }

	 return result;
 }
