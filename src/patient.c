/* ==========================================================================
 * patient.c —— M01 患者档案管理 实现
 * --------------------------------------------------------------------------
 * 负责组：患者组
 * 对应头文件：inc/patient.h
 * 说明：函数声明和返回值含义见 patient.h，本文件只填实现。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "patient.h"

int patient_register(DB_HANDLE* db, Patient* p) {
    (void)db; (void)p;
    return 0;  /* TODO: 生成 P+年份+4位流水号编号，插入 t_patient */
}

int patient_update_self(DB_HANDLE* db, const char* patient_id,
                        const char* phone, const char* address) {
    (void)db; (void)patient_id; (void)phone; (void)address;
    return 0;  /* TODO: UPDATE t_patient SET phone=?, address=? WHERE patient_id=? */
}

int patient_query_by_id(DB_HANDLE* db, const char* patient_id, Patient* out) {
    (void)db; (void)patient_id; (void)out;
    return 0;  /* TODO: SELECT ... FROM t_patient WHERE patient_id=? */
}

int patient_query_all(DB_HANDLE* db, Patient** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 全部患者，malloc 数组返回，调用方用 patient_list_free 释放 */
}

void patient_list_free(Patient* list) {
    (void)list;
    /* TODO: free(list) */
}

int patient_delete(DB_HANDLE* db, const char* patient_id) {
    (void)db; (void)patient_id;
    return 0;  /* TODO: UPDATE t_patient SET status=0 WHERE patient_id=?（软删除） */
}

int patient_export(DB_HANDLE* db, const char* filename) {
    (void)db; (void)filename;
    return 0;  /* TODO: 查询全部患者并写入 filename，如 data/patients_export_20260927.txt */
}
