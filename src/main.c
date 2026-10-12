#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "db_mysql.h"

static void show_main_menu(void) {
    printf("\n========================================\n");
    printf("   社区医疗服务中心信息管理系统 v1.0\n");
    printf("========================================\n");
    printf("  1. 登录\n");
    printf("  2. 患者注册\n");
    printf("  0. 退出\n");
    printf("请输入选项[0-2]: ");
}

/* 读取环境变量，未设置或为空时用默认值 */
static const char* env_or(const char* key, const char* fallback) {
    const char* val = getenv(key);
    return (val && *val) ? val : fallback;
}

int main(void) {
    /* 数据库连接参数从环境变量读取，不要把密码写进源码 */
    const char* db_host = env_or("DB_HOST", "localhost");
    const char* db_user = env_or("DB_USER", "root");
    const char* db_pass = env_or("DB_PASSWORD", "");
    const char* db_name = env_or("DB_NAME", "medical_system");
    int         db_port = atoi(env_or("DB_PORT", "3306"));

    if (!*db_pass) {
        printf("提示: 未设置 DB_PASSWORD 环境变量\n");
    }

    DB_HANDLE* db = db_create();
    if (!db) {
        printf("db_create failed\n");
        return 1;
    }
    if (db_connect(db, db_host, db_user, db_pass, db_name, db_port) != 0) {
        db_close(db);
        return 1;
    }

    int running = 1;
    while (running) {
        show_main_menu();
        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: printf("登录功能待实现\n"); break;
            case 2: printf("患者注册待实现\n"); break;
            case 0: running = 0; break;
            default: printf("无效选项\n"); break;
        }
    }

    db_close(db);
    printf("程序退出\n");
    return 0;
}
