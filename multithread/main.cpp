#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

class SaveAsThread {
public:
    SaveAsThread(const std::string& filename, const std::vector<int>& arr) :
        filename_(filename), arr_(arr) {}

    void operator()() {
        std::ofstream file(filename_);
        if (file.is_open()) {
            for (int num : arr_) {
                file << num << " ";
            }
            file.close();
            std::cout << "Saved array to file: " << filename_ << std::endl;
        } else {
            std::cerr << "Failed to open file: " << filename_ << std::endl;
        }
    }

private:
    std::string filename_;
    std::vector<int> arr_;
};

int main() {
    // Example integer arrays
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {6, 7, 8, 9, 10};
    std::vector<int> arr3 = {11, 12, 13, 14, 15};

    // Create SaveAsThread objects for each array
    SaveAsThread saveThread1("array1.txt", arr1);
    SaveAsThread saveThread2("array2.txt", arr2);
    SaveAsThread saveThread3("array3.txt", arr3);

    // Create threads for each SaveAsThread object
    std::thread thread1(saveThread1);
    std::thread thread2(saveThread2);
    std::thread thread3(saveThread3);

    // Join threads to wait for them to complete
    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "All threads finished." << std::endl;
}
