/* ==========================================================================
 * doctor.c —— M02 医生信息管理 实现
 * --------------------------------------------------------------------------
 * 负责组：管理员组
 * 对应头文件：inc/doctor.h
 * 说明：函数声明和返回值含义见 doctor.h，本文件只填实现。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "doctor.h"

int doctor_add(DB_HANDLE* db, Doctor* d) {
    (void)db; (void)d;
    return 0;  /* TODO: 生成 D+3位流水号编号，插入 t_doctor */
}

int doctor_delete(DB_HANDLE* db, const char* doctor_id) {
    (void)db; (void)doctor_id;
    return 0;  /* TODO: UPDATE t_doctor SET status=0 WHERE doctor_id=?（离职） */
}

int doctor_update(DB_HANDLE* db, const Doctor* d) {
    (void)db; (void)d;
    return 0;  /* TODO: UPDATE t_doctor SET 职称/科室/电话 WHERE doctor_id=? */
}

int doctor_query_by_id(DB_HANDLE* db, const char* doctor_id, Doctor* out) {
    (void)db; (void)doctor_id; (void)out;
    return 0;  /* TODO: SELECT ... FROM t_doctor WHERE doctor_id=? */
}

int doctor_query_all(DB_HANDLE* db, Doctor** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 在职医生列表，malloc 数组返回 */
}

void doctor_list_free(Doctor* list) {
    (void)list;
    /* TODO: free(list) */
}
