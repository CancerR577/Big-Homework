#ifndef POINT_GUARD
#define POINT_GUARD

struct Point {
  int x, y;
  Point(int xx, int yy)
      : x { xx }
      , y { yy }
  {
  }
};

inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

inline bool operator!=(Point a, Point b) { return !(a == b); }

#endif

