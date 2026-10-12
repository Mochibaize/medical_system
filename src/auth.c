/* ==========================================================================
 * auth.c —— M08 登录与用户 实现
 * --------------------------------------------------------------------------
 * 负责组：三组共用
 * 对应头文件：inc/auth.h
 * 说明：函数声明和返回值含义见 auth.h，本文件只填实现。
 *       role 取值：1 管理员，2 医生，3 患者。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "auth.h"
#include <stdlib.h>
#include <string.h>

/* 登录失败计数：用户名 -> 连续失败次数 / 锁定到的时刻
 * 见 auth.h 的【锁定状态存在哪】说明，不要为这个去改表结构 */
/* TODO: 在这里定义一个 static 数组，供 user_login 记录失败次数和锁定时间 */

int user_login(DB_HANDLE* db, int role, const char* username,
               const char* password, LoginUser* out) {
    (void)db; (void)role; (void)username; (void)password; (void)out;
    return 0;  /* TODO: 先查上面的 static 表，锁定期内直接返回 -7；
                *       按 role 决定查 t_admin / t_doctor / t_patient，
                *       校验密码和 status=1，回填 out->id / name / role；
                *       失败累加次数，满 5 次记录锁定 10 分钟并返回 -7，
                *       成功则清零 */
}

int user_register_patient(DB_HANDLE* db, Patient* p) {
    (void)db; (void)p;
    return 0;  /* TODO: 校验账号和身份证号唯一后，调用 patient_register 建档 */
}

int user_change_password(DB_HANDLE* db, int role, const char* id,
                         const char* old_pwd, const char* new_pwd) {
    (void)db; (void)role; (void)id; (void)old_pwd; (void)new_pwd;
    return 0;  /* TODO: 校验原密码正确，再按 role 更新对应表的 password 字段 */
}

char* hash_password(const char* plain) {
    if (!plain) return NULL;
    /* TODO: 教学阶段直接返回明文副本；部署时替换为加盐 SHA-256 */
    char* out = (char*)malloc(strlen(plain) + 1);
    if (!out) return NULL;
    strcpy(out, plain);
    return out;
}
