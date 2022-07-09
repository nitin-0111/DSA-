#include <iostream>
using namespace std;

void print(int n){
   
    if(n == 0){
        cout << n << "";
        return;
    }

    print(n -1);
    cout << n <<" ";
}

int main(void) {
    int num = 3;
    print(num);
    return 0;
}