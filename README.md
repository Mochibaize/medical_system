# 社区医疗服务中心信息管理系统

C + MySQL 实现的社区医疗信息管理系统。

## 依赖

- gcc
- MySQL 客户端开发库(`mysql_config` 可用,如 `mysql-devel` / `libmysqlclient-dev`)

## 编译

```bash
make          # 生成 bin/medical_system
make DEBUG=1  # 带调试符号
make clean    # 清理
```

## 运行

数据库连接参数通过环境变量传入,**不要把密码写进源码或提交到仓库**:

| 变量 | 默认值 | 说明 |
| --- | --- | --- |
| `DB_HOST` | `localhost` | 数据库地址 |
| `DB_USER` | `root` | 用户名 |
| `DB_PASSWORD` | 空 | 密码,未设置时启动会提示 |
| `DB_NAME` | `medical_system` | 库名 |
| `DB_PORT` | `3306` | 端口 |

例如:

```bash
DB_PASSWORD='你的密码' ./bin/medical_system
```

## 目录结构

```
src/    主程序
data/   数据访问层(MySQL)
lib/    公共工具库
inc/    头文件
obj/    编译中间产物(不入库)
bin/    可执行文件(不入库)
```
