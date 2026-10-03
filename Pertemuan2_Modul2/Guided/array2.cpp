#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };
    //print array 2 dimensi
    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][i] << " "; 
        }

        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl; //88
    return 0;
}