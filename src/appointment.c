/* ==========================================================================
 * appointment.c —— M03 挂号预约 实现
 * --------------------------------------------------------------------------
 * 负责组：患者组（挂号、取消）、医生组（当日列表、接诊入口）
 * 对应头文件：inc/appointment.h
 * 说明：函数声明和返回值含义见 appointment.h，本文件只填实现。
 *       status 含义：0 待就诊，1 已就诊，2 已取消，判断时直接写数字。
 *       下面的空壳保证整个项目随时能编译通过，把 return 0 换成真正的逻辑即可。
 * ========================================================================== */

#include "appointment.h"

int appointment_add(DB_HANDLE* db, Appointment* a) {
    (void)db; (void)a;
    return 0;  /* TODO: 校验同一患者同天同医生未重复，插入 t_appointment（status=0） */
}

int appointment_cancel(DB_HANDLE* db, int appoint_id, const char* patient_id) {
    (void)db; (void)appoint_id; (void)patient_id;
    return 0;  /* TODO: 校验预约属于该患者且 status=0，再 UPDATE status=2 */
}

int appointment_query_by_patient(DB_HANDLE* db, const char* patient_id,
                                 Appointment** out_list, int* out_count) {
    (void)db; (void)patient_id;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT ... FROM t_appointment WHERE patient_id=? */
}

int appointment_query_by_doctor_today(DB_HANDLE* db, const char* doctor_id,
                                      Appointment** out_list, int* out_count) {
    (void)db; (void)doctor_id;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT ... WHERE doctor_id=? AND appoint_date=CURDATE() AND status=0 */
}

int appointment_query_all(DB_HANDLE* db, Appointment** out_list, int* out_count) {
    (void)db;
    if (out_list)  *out_list  = NULL;
    if (out_count) *out_count = 0;
    return 0;  /* TODO: SELECT 全部预约（管理员用） */
}

void appointment_list_free(Appointment* list) {
    (void)list;
    /* TODO: free(list) */
}
