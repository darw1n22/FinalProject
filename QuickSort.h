#include <vector>
using namespace std;
template<class T>
class QuickSort
{
private:
    static int partitionLomuto(std::vector<T*>& array, int low, int high)
    {
        T* pivot = array[high];

        int i = low;
        for (int j = low; j < high; j++) {
            if (*array[j] <= *pivot) {
                std::swap(array[i], array[j]);
                i++;
            }
        }

        swap(array[i], array[high]);
        return i;
    }

    static void sort(std::vector<T*>& array, int low, int high) {
        if (low < high) {
            int pivot = partitionLomuto(array, low, high);
            sort(array, low, pivot - 1);
            sort(array, pivot + 1, high);
        }
    }

public:
    static void sort(std::vector<T*>& array) {
        sort(array, 0, array.size() - 1);
    }
};