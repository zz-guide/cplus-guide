#include "main.h"

using namespace std;

class Friend;

class Home {
    friend class Friend;
public:
    string livingRoom = "客厅";
private:
    string bedRoom = "卧室";
};

// 友元类
class Friend {
public:
    Home* home;
    void visit1() {
        cout << home->livingRoom << endl;
        cout << home->bedRoom << endl;
    }

    void visit2() {
        cout << home->livingRoom << endl;
        cout << home->bedRoom << endl;
    }
};

int main()
{
    Home home;
    Friend f;
    f.home = &home;
    f.visit1();
    f.visit2();

    return 0;
}