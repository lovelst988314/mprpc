#include "mprpcconfig.h"

#include <iostream>
#include <string>

// 负责解析加载配置文件
void MprpcConfig::LoadConfigFile(const char *config_file)
{
    FILE *pf = fopen(config_file, "r");  //读打开文件 
    if (nullptr == pf)
    {
        std::cout << config_file << " is note exist!" << std::endl;  //文件不存在
        exit(EXIT_FAILURE);
    }

    // 1.注释   2.正确的配置项 =    3.去掉开头的多余的空格 
    while(!feof(pf))  // 检查文件流是否已到达文件末尾（End Of File）
    {
        char buf[512] = {0};
        fgets(buf, 512, pf);  //从 pf 向 buf 读取

        // 去掉字符串前面多余的空格
        std::string read_buf(buf);
        Trim(read_buf);  //去掉字符串前后的空格

        // 判断#的注释
        if (read_buf[0] == '#' || read_buf.empty())
        {
            continue;
        }

        // 解析配置项
        int idx = read_buf.find('=');
        if (idx == -1)
        {
            // 配置项不合法
            continue;
        }

        std::string key;
        std::string value;
        key = read_buf.substr(0, idx);  // =为分隔符
        Trim(key);
        // rpcserverip=127.0.0.1\n  
        int endidx = read_buf.find('\n', idx);  //用换行找到末尾
        value = read_buf.substr(idx+1, endidx-idx-1);
        Trim(value);
        m_configMap.insert({key, value});

        //不需要线程安全，因为只执行一次
    }

    fclose(pf);
}

// 查询配置项信息
std::string MprpcConfig::Load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if (it == m_configMap.end())
    {
        return "";
    }
    return it->second;
}

// 去掉字符串前后的空格
void MprpcConfig::Trim(std::string &src_buf)
{
    int idx = src_buf.find_first_not_of(' ');  // 找到第一个非空格字符
    if (idx != std::string::npos)   // 原始 if (idx != -1)
    {
        // 说明字符串前面有空格
        src_buf = src_buf.substr(idx, src_buf.size()-idx);
    }
    // 去掉字符串后面多余的空格
    idx = src_buf.find_last_not_of(' ');  // 找到最后一个非空格字符
    if (idx != std::string::npos)
    {
        // 说明字符串后面有空格
        src_buf = src_buf.substr(0, idx+1);
    }
}