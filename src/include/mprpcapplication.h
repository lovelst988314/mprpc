#pragma once

#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"

// mprpc框架的基础类，负责框架的一些初始化操作
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance();  //获取实例的方法
    static MprpcConfig& GetConfig();
private:
    static MprpcConfig m_config;  // 静态方法中只能调用静态变量

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication&&) = delete;
};

//单例模式的设计