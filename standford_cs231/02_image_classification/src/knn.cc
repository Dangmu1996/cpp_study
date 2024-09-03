#include <matplot/matplot.h>
#include "cifar_utils.hpp"
#include "dangmu_utils.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int main() {
    // load data and print the shape of it
    CIFAR10_Data train_data, test_data;

    try {
        std::string ROOT = "/home/dangmu/cpp_study/standford_cs231/cifar-10-batches-bin";
        load_CIFAR10(ROOT, train_data, test_data);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    cout << "Tringing data shape: " << train_data.images.size()
        << ", " << train_data.images[0].cols 
        << ", " << train_data.images[0].rows
        << ", " << train_data.images[0].channels()
        << endl;

    cout << "Tringing label shape: " << train_data.labels.size() << endl;

    cout << "Test data shape: " << test_data.images.size()
        << ", " << test_data.images[0].cols 
        << ", " << test_data.images[0].rows
        << ", " << test_data.images[0].channels()
        << endl;

    cout << "Test label shape: " << test_data.labels.size() << endl;

    vector<string> classes={"plane", "car", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck"};
    int num_classes = classes.size();
    int samples_per_class = 7; 

    for(int y = 0; y < num_classes; y++){
        vector<int> idxs;
        for(int i =0; i < train_data.labels.size(); i++){
            if(train_data.labels(i) == y){
                idxs.push_back(i);
            }
        }

        random_shuffle(idxs.begin(), idxs.end());

        cout << "Class: " << classes[y] << endl;
        for (int i = 0; i < samples_per_class; ++i) {
            int idx = idxs[i];
            std::cout << "Sample " << i + 1 << ": Image index " << idx << std::endl;

            // 이미지 출력
            cv::imshow(classes[y] + " Sample " + std::to_string(i + 1), train_data.images[idx]);
            cv::waitKey(0); // 키 입력을 기다립니다. 이미지 간 전환을 위해 필요합니다.
            cv::destroyWindow(classes[y] + " Sample " + std::to_string(i + 1)); // 창을 닫습니다.
        }
    }


    return 0;
}