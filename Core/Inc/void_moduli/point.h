#ifndef INC_VOID_MODULI_POINT_H_
#define INC_VOID_MODULI_POINT_H_

typedef struct {
	float x, y;
} Point_t;

Point_t offset(Point_t point, float x, float y);

#endif /* INC_VOID_MODULI_POINT_H_ */
