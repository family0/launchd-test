#include <iostream>
#include <sys/stat.h>

using namespace std;

int main() {
    cout << "exe2 START" << endl;
    cout << system("echo $(id -u)") << endl;
    cout << system("open -W '/Users/tj/Downloads/setup.pkg'") << endl;
    return 0;
}