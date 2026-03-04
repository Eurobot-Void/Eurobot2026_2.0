#ifndef INC_VOID_MODULI_RECTANGLE_H_
#define INC_VOID_MODULI_RECTANGLE_H_

#include "point.h"

// rotacija je za slucaj da se jenga pomeri
// moze i velicina da se promeni ako padne na stranu, ako nam treba nesto sa tim bolje 3D
typedef struct {
	Point_t center, size;
	float rotation;
} Rectangle_t;

Rectangle_t make_rectangle(Point_t top_left, Point_t bottom_right);

// kolike prostora jenga zauzima u odnosu na robota da se ne sudare
Point_t get_rectangle_AABB(Rectangle_t rect, float angle_offset);

#endif /* INC_VOID_MODULI_RECTANGLE_H_ */
