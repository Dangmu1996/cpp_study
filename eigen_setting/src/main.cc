#include <eigen3/Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

int main()
{
    Eigen::Matrix2d mat;
    mat<<1, 2,
    3, 4;
    cout << "Here is mat.sum*(): " << mat.sum()<<endl;
    cout << "Here is map.product(): " << mat.prod()<<endl;
    cout << "Here is mat.minCoeff(): " << mat.minCoeff()<<endl;
    cout << "Here is  mat.maxCoeff(): " << mat.maxCoeff()<<endl;
    cout << "here is  mat.trace(): " << mat.trace() << endl;
    return 0;
}
