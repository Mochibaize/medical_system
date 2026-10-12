# 社区医疗服务中心信息管理系统

C + MySQL 实现的社区医疗信息管理系统。5 人小组,**按角色分成三组独立开发**。

> **每个人在自己电脑上建自己的数据库。** 本项目不共享数据库,只共享 `init.sql` 建库脚本 —— 你 clone 下来之后,在自己机器上跑一遍脚本,就有了一套结构和预置数据完全一致的库,不会互相干扰。

---

## 一、环境要求

在 Rocky Linux 上执行以下 5 条检查:

```bash
gcc --version                          # 1. 编译器
sudo systemctl status mysqld           # 2. MySQL 服务
mysql_config --cflags --libs           # 3. MySQL 开发库
git --version                          # 4. 版本控制
mysql -u root -p                       # 5. 能登录 MySQL
```

**5 条全过才算环境 OK。** 有任何一条不过,先解决它,别往下走。

| 报错 | 解决办法 |
|------|----------|
| `mysql_config: command not found` | `sudo dnf install mysql-community-devel` |
| `Access denied` | 密码不对 |
| `Can't connect` | MySQL 没启动 → `sudo systemctl start mysqld` |
| `gcc: command not found` | `sudo dnf install gcc make` |

---

## 二、快速开始

```bash
# 1. 克隆项目
git clone git@github.com:tpzdcc/medical_system.git
cd medical_system

# 2. 建库建表(用你自己的 MySQL 密码)
mysql -u root -p < init.sql

# 3. 验证: 应该看到 9 张表
mysql -u root -p -e "use medical_system; show tables;"

# 4. 编译
make

# 5. 运行(把密码换成你自己的)
DB_PASSWORD='你的MySQL密码' ./bin/medical_system
```

第 5 步如果打印出 `db connect success`,环境就通了。

---

## 三、数据库配置

连接参数**通过环境变量传入,不要把密码写进源码、更不要提交到仓库**:

| 变量 | 默认值 | 说明 |
|------|--------|------|
| `DB_HOST` | `localhost` | 数据库地址 |
| `DB_USER` | `root` | 用户名 |
| `DB_PASSWORD` | (空) | 密码,**未设置时启动会提示** |
| `DB_NAME` | `medical_system` | 库名 |
| `DB_PORT` | `3306` | 端口 |

最简用法只需要给 `DB_PASSWORD`,其余走默认值:

```bash
DB_PASSWORD='你的密码' ./bin/medical_system
```

嫌每次输入麻烦,可以写进 `~/.bashrc`:

```bash
echo "export DB_PASSWORD='你的密码'" >> ~/.bashrc && source ~/.bashrc
```

> ⚠️ 检查一下:提交前先跑 `git diff --cached`,确认没有把自己的密码带进去。仓库是公开的。

### 表结构

`init.sql` 会创建 9 张表,并预置少量测试数据:

| 表名 | 说明 |
|------|------|
| `t_admin` | 管理员 |
| `t_doctor` | 医生 |
| `t_patient` | 患者 |
| `t_medicine` | 药品 |
| `t_appointment` | 预约挂号 |
| `t_visit_record` | 就诊记录 |
| `t_prescription` | 处方主表 |
| `t_presc_detail` | 处方明细 |
| `t_medical_record` | 病历 |

预置账号:

| 角色 | 用户名 | 密码 |
|------|--------|------|
| 管理员 | `admin` | `123456` |
| 医生 | `D001` | `123456` |

> 课程项目为简化实现,密码是明文存储的,不要用于任何真实场景。

**改了表结构怎么办?** `init.sql` 是**唯一的权威版本**。任何表结构变更都必须改这个文件并提交,队友 `git pull` 后重跑一遍脚本同步。不要各自在数据库里手动改表 —— 那样集成时必然对不上。

---

## 四、目录结构

```
src/      各模块实现
data/     数据访问层(MySQL 封装)
lib/      公共工具库
inc/      头文件(接口定义,先定死)
obj/      编译中间产物(不入库)
bin/      可执行文件(不入库)
init.sql  建库建表脚本
Makefile
```

常用命令:

```bash
make          # 编译
make DEBUG=1  # 带调试符号编译(可用 gdb)
make clean    # 清理
```

---

## 五、协作规范

### 各组分工

各组从主仓库 clone 代码后自行开发,**做完提交回来,由我审核后合并**。分支怎么建各组自己定,不限制。

| 组 | 负责范围 |
|----|----------|
| 管理员组 | 管理员登录、医生管理、药品管理、账号管理 |
| 医生组 | 医生登录、接诊、开处方、写病历 |
| 患者组 | 患者注册登录、挂号预约、查询本人记录 |

### 别两组改到同一张表

各组独立开发,最容易出问题的是两组改到同一张表。按角色划分归属:

| 表 | 主要归属 |
|----|----------|
| `t_admin`、`t_doctor`、`t_medicine` | 管理员组 |
| `t_patient` | 患者组 |
| `t_appointment` | 患者组(挂号)、医生组(查看与确认) |
| `t_visit_record`、`t_prescription`、`t_presc_detail`、`t_medical_record` | 医生组 |

**改表结构一律改 `init.sql` 并提交**,不要在数据库里手动改 —— 否则三组各自建库后结构不一致,集成时对不上。

### 写代码前先看一眼 `inc/common.h`

公共的常量已经定义好了,都在这个文件里,**别自己另起一套**:

- **函数返回值统一用错误码**:成功返回 `ERR_OK`,失败返回 `ERR_DB_CONN`、`ERR_NOT_FOUND`、`ERR_NO_STOCK` 等,不要返回自己编的数字
- **角色**:`ROLE_ADMIN`(管理员)、`ROLE_DOCTOR`(医生)、`ROLE_PATIENT`(患者)
- **预约状态**:`APPOINT_WAIT`(待就诊)、`APPOINT_VISITED`(已就诊)、`APPOINT_CANCELED`(已取消)
- **库存预警**:`LOW_STOCK`

自己模块的结构体和函数声明放 `inc/` 下自己的头文件(比如 `inc/patient.h`),实现放 `src/`。

---

## 六、常见问题

**编译报 `mysql/mysql.h: No such file or directory`**
缺开发库:`sudo dnf install mysql-community-devel`

**启动只打印 "未设置 DB_PASSWORD 环境变量" 然后连接失败**
没传密码,用 `DB_PASSWORD='你的密码' ./bin/medical_system` 运行。

**`db connect error: Access denied`**
密码错了,或库没建。先跑 `mysql -u root -p -e "show databases;"` 确认 `medical_system` 存在。

**改了 `init.sql` 之后表还是旧的**
脚本开头是 `DROP DATABASE IF EXISTS`,重跑会**清空重建**。确认没有你要保留的数据后再执行。

**`make` 报 `mysql_config: not found`**
Makefile 依赖 `mysql_config`,没装开发库就会这样,见第一条。
