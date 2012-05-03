#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	int x;
	int y;

	bool operator!=(Point point);
	bool operator==(Point point);
	Point(){};
	Point(int x, int y);
	virtual ~Point(){};
};

#endif /* POINT_H_ */
