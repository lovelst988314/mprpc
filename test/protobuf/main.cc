#include <iostream>
#include <string>
#include "test.pb.h"

using namespace fixbug;
using namespace std;


int main()
{
    // LoginResponse rsp;
    // ResultCode* rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登录失败");   使用protobuf中的列表

    GETFriendListResponse rsp;
    ResultCode* rc = rsp.mutable_result();
    rc->set_errcode(0);

    User* user1 = rsp.add_friends_list();
    user1->set_name("张三");
    user1->set_age(18);
    user1->set_sex(User::MALE);

    User* user2 = rsp.add_friends_list();
    user1->set_name("li shi");
    user1->set_age(20);
    user1->set_sex(User::MALE);

    cout << rsp.friends_list_size() << endl;
}

// int main1()
// {
//     // 封装了login请求数据的对象
//     LoginRequest req;
//     req.set_name("zhang san");
//     req.set_pwd("123456");

//     // 对象序列化 成为一个 char*
//     string tempstr;
//     if(req.SerializeToString(&tempstr)) {
//         cout << tempstr << endl;
//     }

//     // 从字符串反序列化一个login 对象
//     LoginRequest reqB;
//     if(reqB.ParseFromString(tempstr)) {
//         cout << reqB.name() << endl;
//         cout << reqB.pwd() << endl;

//     }

//     return 0;
// }

