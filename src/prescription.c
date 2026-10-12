/* ==========================================================================
 * prescription.c —— M05 处方管理 实现
 * --------------------------------------------------------------------------
 * 负责组：医生组
 * 对应头文件：inc/prescription.h
 * 说明：函数声明和返回值含义见 prescription.h，本文件只填实现。
 *       prescription_add 必须用事务把"写主表""写明细""扣库存"绑在一起，
 *       任一味药库存不足就整张处方回滚。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "prescription.h"

int prescription_add(DB_HANDLE* db, Prescription* p,
                     PrescDetail* items, int item_count) {
    (void)db; (void)p; (void)items; (void)item_count;
    return 0;  /* TODO: BEGIN → 插入 t_prescription 拿 presc_id
                *            → 逐条查药品单价、算 subtotal、插入 t_presc_detail
                *            → 扣减 t_medicine.stock（不足则 ROLLBACK 返回 -5）
                *            → COMMIT */
}

int prescription_void(DB_HANDLE* db, int presc_id, const char* doctor_id) {
    (void)db; (void)presc_id; (void)doctor_id;
    return 0;  /* TODO: 校验是本人开的且 status=1，UPDATE status=0（不回滚库存） */
}

int prescription_query_by_patient(DB_HANDLE* db, const char* patient_id,
                                  Prescription** out_list, int* out_count) {
    (void)db; (void)patient_id;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT ... FROM t_prescription WHERE patient_id=? */
}

int prescription_query_by_id(DB_HANDLE* db, int presc_id,
                             Prescription* out,
                             PrescDetail** out_items, int* out_item_count) {
    (void)db; (void)presc_id; (void)out;
    if (out_items)      *out_items      = NULL;
    if (out_item_count) *out_item_count = 0;
    return 0;  /* TODO: 查主表 + 查 t_presc_detail 明细，两块都返回 */
}

int prescription_query_all(DB_HANDLE* db, Prescription** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 全部处方（管理员用） */
}

void prescription_list_free(Prescription* list) {
    (void)list;
    /* TODO: free(list) */
}

void prescription_detail_free(PrescDetail* items) {
    (void)items;
    /* TODO: free(items) */
}
