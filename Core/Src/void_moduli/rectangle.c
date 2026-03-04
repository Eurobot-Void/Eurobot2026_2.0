#include <math.h>
#include "void_moduli/rectangle.h"
#include "void_moduli/util.h"

Rectangle_t make_rectangle(Point_t top_left, Point_t bottom_right) {
	Point_t size = {bottom_right.x - top_left.x, bottom_right.y - top_left.y};
	Point_t center = offset(top_left, size.x / 2, size.y / 2);
	return (Rectangle_t) {.center = center, .size = size};
}

Point_t get_rectangle_AABB(Rectangle_t rect, float angle_offset) {
	float relative_angle = normalize_rad_angle(rect.rotation - angle_offset);
	float cos_theta = fabsf(cosf(relative_angle));
	float sin_theta = fabsf(sinf(relative_angle));
	// width = w|cosθ| + h|sinθ|
	float width = rect.size.x * cos_theta + rect.size.y * sin_theta;
	// height = w|sin⁡θ| + h|cos⁡θ|
	float height = rect.size.x * sin_theta + rect.size.y * cos_theta;
	return (Point_t) {width, height};
}
