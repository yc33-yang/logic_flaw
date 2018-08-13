
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


#include <iostream>

template <class T>
std::ostream & operator << (std::ostream &os, const std::vector<T> &v)
{
	size_t num_ret = v.size();
	for (size_t i = 0; i < num_ret; i++)
	{
		os << "[" << i << "] = " << v[i] << '\n';
	}
	return os;
}

 int main()
 {
	 std::vector<int> ary = { 33, 4, 1, 92, 33 ,100, 3, 4, 0, 5, 33 };
	 std::vector<int> ret = QuickSort(ary);

	 std::cout << ret;
	 
	 return 0;
 }
