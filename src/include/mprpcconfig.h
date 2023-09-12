#pragma once
#include <unordered_map>
#include <string>
// rpcserverip rpcserverport zookeeperip zookeeperport
class MprpcConfig
{
public:
    // 负责解析加载配置文件
    void LoadConfigFile(const char *config_file);
    // 查询配置项信息
    std::string Load(const std::string &key);

private:
    void Trim(std::string &src_buf);
    std::unordered_map<std::string, std::string> m_configMap;
};