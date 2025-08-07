#pragma once

#include <unordered_map>
#include <string>

// rpcserverip   rpcserverport    zookeeperip   zookeeperport
// 框架读取配置文件类
class MprpcConfig
{
public:
    // 负责解析加载配置文件
    void LoadConfigFile(const char *config_file);
    
    // 查询配置项信息
    std::string Load(const std::string &key);
private:
    std::unordered_map<std::string, std::string> m_configMap;  //记录配置文件中的对应关系
    // zookeeperip=127.0.0.1  配置项键值对来存储

    // 去掉字符串前后的空格
    void Trim(std::string &src_buf);
};


// 配置文件只需要读取一次 不然浪费资源