#include <iostream>
#include "test.pb.h"

using namespace fixbug;
int main()
{
    // LoginRequest req;
    // req.set_name("zhang san");
    // req.set_pwd("123456");

    // // 对象数据序列化
    // std::string send_str;
    // if (req.SerializeToString(&send_str))
    // {
    //     std::cout << send_str.c_str() << std::endl;
    // }
    // // 反序列化
    // LoginRequest reqB;
    // if (reqB.ParseFromString(send_str))
    // {
    //     std::cout << reqB.name() << std::endl;
    //     std::cout << reqB.pwd() << std::endl;
    // }
    // LoginResponse rsp;
    // ResultCode* rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登陆处理失败了");

    GetFriendListResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);

    User *usr1 = rsp.add_friend_list();
    usr1->set_age(23);
    usr1->set_name("ZHANG SAN");
    usr1->set_sex(User::MAN);
    User *usr2 = rsp.add_friend_list();
    usr1->set_age(23);
    usr1->set_name("ZHANG SAN");
    usr1->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl;

    return 0;
}