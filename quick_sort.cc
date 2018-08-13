
#include <vector>


template <class T>
std::vector<T> FilterLessThan(const std::vector<T> & V, T pivot) {
	std::vector<T> result;

	for (T elem : V) {
		if (elem < pivot) {
			result.push_back(elem);
		}
	
	}
	return result;
}


template <class T>
std::vector<T> FilterGreaterThan(const std::vector<T> & V, T pivot) {
	std::vector<T> result;

	for (T elem : V) {
		if (elem > pivot) {
			result.push_back(elem);
		}
	}
	return result;
}

template <class T>
size_t CountSame(const std::vector<T> &V, T value) {
	size_t count = 0;

	for (T elem : V) {
		if (elem == value) {
			count++;
		}
	}
	return count;
}

template <class T>
std::vector<T> QuickSort(std::vector<T> V) {
	if (static_cast<T>(V.size()) <= 1) {
		return V;
	}
	
	T pivot = V.back();
	size_t num_pivot = CountSame(V, pivot);
	V.pop_back();
	
	std::vector<T> result;
	for (T elem : QuickSort(FilterLessThan(V, pivot))) {
		result.push_back(elem);
	}
	for (size_t i = 0; i < num_pivot; i++) {
		result.push_back(pivot);
	}
	for (T elem : QuickSort(FilterGreaterThan(V, pivot))) {
		result.push_back(elem);
	}
	
	return result;
}

#ifdef TEST_QUICKSORT_VECTOR_INT

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

#endif
