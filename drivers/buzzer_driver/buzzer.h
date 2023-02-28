#ifndef _BUZZER_H_
#define _BUZZER_H_
#include "pwm.h"

typedef struct buzzer_obj_t
{
     pwm_obj_t pwm;
     int major_num;
     _Bool instance;
     void (*SuccessSoundFunc)(struct buzzer_obj_t *this);
     void (*ButtonPushSoundFunc)(struct buzzer_obj_t *this);
     void (*RemoveObjFunc)(struct buzzer_obj_t *this);
}buzzer_obj_t;

_Bool CreateBuzzerObj(struct buzzer_obj_t *this);
#endif