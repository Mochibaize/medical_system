/* ==========================================================================
 * visit.c —— M04 接诊与就诊记录 实现
 * --------------------------------------------------------------------------
 * 负责组：医生组
 * 对应头文件：inc/visit.h
 * 说明：函数声明和返回值含义见 visit.h，本文件只填实现。
 *       visit_add 必须用事务把"写就诊记录"和"预约置为已就诊"绑在一起。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "visit.h"

int visit_add(DB_HANDLE* db, VisitRecord* v) {
    (void)db; (void)v;
    return 0;  /* TODO: BEGIN → 校验预约 status=0 → 插入 t_visit_record
                *            → UPDATE t_appointment SET status=1 → COMMIT */
}

int visit_query_by_patient(DB_HANDLE* db, const char* patient_id,
                           VisitRecord** out_list, int* out_count) {
    (void)db; (void)patient_id;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT ... FROM t_visit_record WHERE patient_id=? */
}

int visit_query_by_doctor(DB_HANDLE* db, const char* doctor_id,
                          VisitRecord** out_list, int* out_count) {
    (void)db; (void)doctor_id;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT ... FROM t_visit_record WHERE doctor_id=? */
}

int visit_query_all(DB_HANDLE* db, VisitRecord** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 全部就诊记录（管理员用） */
}

void visit_list_free(VisitRecord* list) {
    (void)list;
    /* TODO: free(list) */
}
