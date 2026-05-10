[_SYS] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------,                    ,-----------------------------------------------------,
    XXXXXXX,  QK_RBT, XXXXXXX, UG_SPDU, UG_VALU, UG_NEXT,                      RM_NEXT, RM_VALU, RM_SPDU, XXXXXXX,  QK_RBT, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,                      RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, QK_BOOT, XXXXXXX, UG_SPDD, UG_VALD, UG_PREV,                      RM_PREV, RM_VALD, RM_SPDD, XXXXXXX, QK_BOOT, XXXXXXX,
//'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                  TO(_QWRT), TO(_DVRK), TO(_GAM1),  TO(_GAM1), TO(_DVRK), TO(_QWRT)
                                    //'--------------------------'  '--------------------------'
),
