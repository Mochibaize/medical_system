#ifndef DB_MYSQL_H
#define DB_MYSQL_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** fields;
    int    col_cnt;
} DB_ROW;

typedef struct {
    MYSQL_RES* res;
    int row_cnt;
    int col_cnt;
} DB_RES;

typedef struct {
    MYSQL* mysql;
    int    is_connected;
} DB_HANDLE;

DB_HANDLE* db_create(void);
int  db_connect(DB_HANDLE* h, const char* host, const char* user,
                const char* passwd, const char* dbname, int port);
void db_close(DB_HANDLE* h);
int  db_execute(DB_HANDLE* h, const char* sql);
DB_RES* db_query(DB_HANDLE* h, const char* sql);
DB_ROW* db_fetch_row(DB_RES* res);
void db_res_free(DB_RES* res);

#endif
