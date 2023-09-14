#pragma once
#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpcprovider.h"
#include "mprpccontroller.h"
#include "zookeeperutil.h"

// mprpc框架的基础类,负责框架的一些初始化操作
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication &GetInstance();
    static MprpcConfig &GetConfig();

private:
    static MprpcConfig m_config;
    MprpcApplication() {}
    MprpcApplication(const MprpcApplication &) = delete;
    MprpcApplication(MprpcApplication &&) = delete;
};