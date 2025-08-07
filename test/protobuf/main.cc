#include <iostream>
#include <string>
#include "test.pb.h"

using namespace fixbug;



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
    user1->set_name("张三");  // 设user的值
    user1->set_age(18);
    user1->set_sex(User::MALE);

    User* user2 = rsp.add_friends_list();
    user2->set_name("li shi");
    user2->set_age(20);
    user2->set_sex(User::MALE);
    
    std::cout << user2->name() << " " << user2->age() << " " << user2->sex() << std::endl;

    // std::cout << rsp.friends_list(1).age() << " " << rsp.friends_list(1).name() << std::endl;  //打印user2的 age和name
    // std::cout << rsp.friends_list_size() << std::endl;

    // // 序列化对象rsp 得到一个字符串
    // std::string send_str;
    // rsp.SerializeToString(&send_str);

    // GETFriendListResponse rsp2;
    // rsp2.ParseFromString(send_str);
    // std::cout << rsp2.friends_list(1).age() << " " << rsp2.friends_list(1).name() << std::endl;
    
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

