#include "main.h"

using namespace std;

class Home {
    friend void gotoBedRoom(Home * home); // 全局函数作为友元
public:
    string livingRoom = "客厅";
private:
    string bedRoom = "卧室";
};

// 全局函数
void gotoBedRoom(Home * home) {
    cout << home->livingRoom << endl;
    cout << home->bedRoom << endl;
}

int main()
{
    Home home;
    gotoBedRoom(&home);

    return 0;
}