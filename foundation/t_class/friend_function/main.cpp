#include "main.h"

using namespace std;

// 注意顺序

class Home;
class GoodFriend {
public:
    Home* home;
    void visitBedRoom();

};

class Home {
    friend void GoodFriend::visitBedRoom(); // 成员函数作为友元
public:
    string livingRoom = "客厅";
private:
    string bedRoom = "卧室";
};

// 成员函数
void GoodFriend::visitBedRoom() {
    cout << home->livingRoom << endl;
    cout << home->bedRoom << endl;
}

int main()
{
    Home home;
    GoodFriend gf = GoodFriend();
    gf.home = &home;
    gf.visitBedRoom();

    return 0;
}