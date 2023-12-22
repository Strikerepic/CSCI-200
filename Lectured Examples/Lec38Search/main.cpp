#include <iostream>
using namespace std;

void print_space(const int N) { 
    for(int i = 0; i < N; i++) cout << " ";
}

void recurse( const int N ) {
    if(N <= 1) {
        print_space(N);  cout << "Done!" << endl;
    } else {
        print_space(N);  cout << "Start " << N << endl;
        recurse(N-1);
        print_space(N);  cout << "End " << N << endl;
    }
}

//Use step or next
//Step to really get it

// b # for setting breakpoint

// Continue to move to next breakpoint

// BT to view frames

int main() {
    recurse(6);
    return 0;
}