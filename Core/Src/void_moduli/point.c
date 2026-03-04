#include "void_moduli/point.h"

Point_t offset(Point_t p, float x, float y) {
	return (Point_t) {p.x + x, p.y + y};
}
