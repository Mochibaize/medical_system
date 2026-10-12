#ifndef COMMON_H
#define COMMON_H

#define ERR_OK           0
#define ERR_DB_CONN    -1
#define ERR_DB_EXEC    -2
#define ERR_DUPLICATE  -3
#define ERR_NOT_FOUND  -4
#define ERR_NO_STOCK   -5
#define ERR_PERM       -6
#define ERR_LOCKED     -7

/* 角色 */
#define ROLE_ADMIN    1
#define ROLE_DOCTOR   2
#define ROLE_PATIENT  3

/* 预约状态 */
#define APPOINT_WAIT      0
#define APPOINT_VISITED   1
#define APPOINT_CANCELED  2

/* 库存预警阈值 */
#define LOW_STOCK 50

#endif
