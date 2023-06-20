#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "exe1 START" << endl;
    cout << system("launchctl kickstart gui/501/kr.itst.exe2.plist") << endl;
    return 0;
}