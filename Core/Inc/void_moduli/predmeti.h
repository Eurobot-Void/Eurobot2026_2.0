#ifndef INC_VOID_MODULI_PREDMETI_H_
#define INC_VOID_MODULI_PREDMETI_H_

#include "rectangle.h"

static const Point_t SIZE_JENGA = {150, 50};

static const Rectangle_t AREA_YELLOW_NEST = make_rectangle((Point_t) {0, 0}, (Point_t) {600, 450});
static const Rectangle_t AREA_YELLOW_SIMA_START = make_rectangle((Point_t) {615, 0}, (Point_t) {815, 200});
static const Rectangle_t AREA_YELLOW_LOADING_AREA = make_rectangle((Point_t) {700, 250}, (Point_t) {900, 400});
static const Rectangle_t AREA_YELLOW_FRIDGE[] = {
	make_rectangle((Point_t) {1050, 200}, (Point_t) {1150, 350}),
	make_rectangle((Point_t) {1300, 150}, (Point_t) {1400, 300}),
};

static const Rectangle_t AREA_BLUE_NEST = make_rectangle((Point_t) {2400, 0}, (Point_t) {3000, 450});
static const Rectangle_t AREA_BLUE_SIMA_START = make_rectangle((Point_t) {2185, 0}, (Point_t) {2385, 200});
static const Rectangle_t AREA_BLUE_LOADING_AREA = make_rectangle((Point_t) {2100, 250}, (Point_t) {2300, 400});
static const Rectangle_t AREA_BLUE_FRIDGE[] = {
	make_rectangle((Point_t) {1600, 200}, (Point_t) {1700, 350}),
	make_rectangle((Point_t) {1850, 150}, (Point_t) {1950, 300}),
};

static const Rectangle_t AREA_COLLECTION[] = {
	make_rectangle((Point_t) {0, 1100},    (Point_t) {200, 1300}),
	make_rectangle((Point_t) {700, 1100},  (Point_t) {900, 1300}),
	make_rectangle((Point_t) {600, 1800},  (Point_t) {800, 2000}),
	make_rectangle((Point_t) {1150, 450},  (Point_t) {1350, 650}),
	make_rectangle((Point_t) {1650, 450},  (Point_t) {1850, 650}),
	make_rectangle((Point_t) {1400, 1100}, (Point_t) {1600, 1300}),
	make_rectangle((Point_t) {1400, 1800}, (Point_t) {1600, 2000}),
	make_rectangle((Point_t) {2100, 1100}, (Point_t) {2300, 1300}),
	make_rectangle((Point_t) {2200, 1800}, (Point_t) {2400, 2000}),
	make_rectangle((Point_t) {2800, 1100}, (Point_t) {3000, 1300})
};

static const Rectangle_t AREA_PANTRY[] = {
	make_rectangle((Point_t) {100, 700},   (Point_t) {250, 900}),
	make_rectangle((Point_t) {100, 1500},  (Point_t) {250, 1700}),
	make_rectangle((Point_t) {1050, 1125}, (Point_t) {1250, 1275}),
	make_rectangle((Point_t) {1000, 1750}, (Point_t) {1200, 1900}),
	make_rectangle((Point_t) {1750, 1125}, (Point_t) {1950, 1275}),
	make_rectangle((Point_t) {1800, 1750}, (Point_t) {2000, 1900}),
	make_rectangle((Point_t) {2750, 700},  (Point_t) {2900, 900}),
	make_rectangle((Point_t) {2750, 1500}, (Point_t) {2900, 1700})
};

#endif /* INC_VOID_MODULI_PREDMETI_H_ */
