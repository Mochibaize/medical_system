/* ==========================================================================
 * medical_record.c —— M07 电子病历 实现
 * --------------------------------------------------------------------------
 * 负责组：医生组
 * 对应头文件：inc/medical_record.h
 * 说明：函数声明和返回值含义见 medical_record.h，本文件只填实现。
 *       medical_record_update 要判断"是不是本人写的"和"有没有超 24 小时"。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "medical_record.h"

int medical_record_add(DB_HANDLE* db, MedicalRecord* r) {
    (void)db; (void)r;
    return 0;  /* TODO: INSERT INTO t_medical_record ...，成功后回写 r->record_id */
}

int medical_record_update(DB_HANDLE* db, const MedicalRecord* r) {
    (void)db; (void)r;
    return 0;  /* TODO: 校验 doctor_id 是本人 且 update_time 距今 < 24 小时，
                *       否则返回 -6 / -7 */
}

int medical_record_query_by_patient(DB_HANDLE* db, const char* patient_id,
                                    MedicalRecord** out_list, int* out_count) {
    (void)db; (void)patient_id;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT ... FROM t_medical_record WHERE patient_id=? */
}

int medical_record_query_all(DB_HANDLE* db, MedicalRecord** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 全部病历（管理员用） */
}

void medical_record_list_free(MedicalRecord* list) {
    (void)list;
    /* TODO: free(list) */
}
