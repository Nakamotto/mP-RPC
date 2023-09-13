#include <iostream>
#include <string>
#include <vector>
#include "friend.pb.h"

#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "logger.h"

class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendList(uint32_t userid)
    {
        std::cout << "do GetFriendList service! userid: " << userid << std::endl;
        std::vector<std::string> vec = {"gaoyang", "liu hong", "wang shuo"};
        return vec;
    }

    // 重写基类的方法
    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::fixbug::GetFriendListRequest *request,
                       ::fixbug::GetFriendListResponse *response,
                       ::google::protobuf::Closure *done)
    {
        uint32_t userid = request->userid();
        std::vector<std::string> friends = GetFriendList(userid);

        fixbug::ResultCode *result = response->mutable_result();
        result->set_errcode(0);
        result->set_errmsg("");
        for (const auto &name : friends)
        {

            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();

        return;
    }
};

int main(int argc, char **argv)
{

    LOG_INFO("first log message");
    LOG_ERR("%s:%s:%d", __FILE__, __FUNCTION__, __LINE__);
    // 调用框架的初始化操作 provider -i config.conf
    MprpcApplication::Init(argc, argv);

    // provider是一个rpc网络服务对象，把FriendService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    // 启动一个rpc服务发布节点，run以后，进程进入阻塞状态，等待远程的rpc调用请求

    provider.Run();

    return 0;
}
