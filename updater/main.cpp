#include <iostream>
#include <sys/stat.h>

using namespace std;

int main() {
    cout << "updater START" << endl;
    mkdir("dir2", 0644);
    return 0;
}