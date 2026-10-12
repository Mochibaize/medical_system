/* ==========================================================================
 * medicine.c —— M06 药品库存管理 实现
 * --------------------------------------------------------------------------
 * 负责组：管理员组
 * 对应头文件：inc/medicine.h
 * 说明：函数声明和返回值含义见 medicine.h，本文件只填实现。
 *       库存低于 50 视为不足，判断时直接写 50。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "medicine.h"

int medicine_add(DB_HANDLE* db, const Medicine* m) {
    (void)db; (void)m;
    return 0;  /* TODO: INSERT INTO t_medicine ... */
}

int medicine_stock_in(DB_HANDLE* db, const char* med_id, int quantity) {
    (void)db; (void)med_id; (void)quantity;
    return 0;  /* TODO: UPDATE t_medicine SET stock=stock+? WHERE med_id=? */
}

int medicine_stock_out(DB_HANDLE* db, const char* med_id, int quantity) {
    (void)db; (void)med_id; (void)quantity;
    return 0;  /* TODO: 先查库存确认够扣，再 UPDATE stock=stock-?（不足返回 -5） */
}

int medicine_update_price(DB_HANDLE* db, const char* med_id, double new_price) {
    (void)db; (void)med_id; (void)new_price;
    return 0;  /* TODO: UPDATE t_medicine SET price=? WHERE med_id=? */
}

int medicine_query_all(DB_HANDLE* db, Medicine** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 全部药品，malloc 数组返回（列表展示时标注库存<50 的行） */
}

int medicine_query_by_id(DB_HANDLE* db, const char* med_id, Medicine* out) {
    (void)db; (void)med_id; (void)out;
    return 0;  /* TODO: SELECT ... FROM t_medicine WHERE med_id=? */
}

void medicine_list_free(Medicine* list) {
    (void)list;
    /* TODO: free(list) */
}
