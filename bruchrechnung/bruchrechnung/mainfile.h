#ifndef _MAINFILE_H_
#define _MAINFILE_H_

/* Prototypen der benötigten Funktionen */
struct bruch_s;
struct bruch_s addition(struct bruch_s b1, struct bruch_s b2);
struct bruch_s subtraktion(struct bruch_s b1, struct bruch_s b2);
struct bruch_s multiplikation(struct bruch_s b1, struct bruch_s b2);
struct bruch_s division(struct bruch_s b1, struct bruch_s b2);
struct bruch_s kuerz(struct bruch_s value);
int ggt(int value, int value2);

#endif
