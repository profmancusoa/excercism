#include "clock.h"
#include <stdio.h>
#include <math.h>

void min_lt_0(int *hh, int *mm) {
    if(*mm < 0) {
        *hh -= ceil(((-*mm) / 60.0));
        *mm = (ceil(((-*mm) / 60.0)) * 60) + *mm;
    }
}

void min_eq_60(int *hh, int *mm) {
    if(*mm == 60) {
        *mm = 0;
        (*hh)++;
    }
}

void min_gt_60(int *hh, int *mm) {
    if(*mm > 60) {
        *hh += *mm / 60;
        *mm = *mm % 60;
    }
}

void hour_lt_0(int *hh, int *mm) {
    if(*hh < 0) {
        *hh = 48 + (*hh % 24);
    }
    *mm = *mm;
}

clock_t clock_create(int hour, int minute) {
    clock_t clock;

    min_lt_0(&hour, &minute);
    min_eq_60(&hour, &minute);
    min_gt_60(&hour, &minute); 
    hour_lt_0(&hour, &minute);  
    
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hour % 24, minute % 60);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    clock_t res;
    int hh,mm;

    sscanf(clock.text, "%d:%d", &hh, &mm);
    mm += minute_add;
    min_gt_60(&hh, &mm); 
    snprintf(res.text, MAX_STR_LEN, "%02d:%02d", hh % 24, mm % 60);
    
    return res;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    clock_t res;
    int hh,mm;

    sscanf(clock.text, "%d:%d", &hh, &mm);
    mm -= minute_subtract;
    min_lt_0(&hh, &mm);
    hour_lt_0(&hh, &mm);
    snprintf(res.text, MAX_STR_LEN, "%02d:%02d", hh % 24, mm % 60);
    
    return res;
}

bool clock_is_equal(clock_t a, clock_t b) {
    int hha, mma, hhb, mmb;

    sscanf(a.text, "%d:%d", &hha, &mma);
    sscanf(b.text, "%d:%d", &hhb, &mmb);
    
    return hha % 24 == hhb %24 && mma % 60 == mmb %60;
}
