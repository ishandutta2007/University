struct Line {
  // Ax + By = C
  double A, B, C;
  Line(double _A, double _B, double _C):A(_A),B(_B),C(_C){}
  Line():A(0.0),B(0.0),C(0.0){}
};

Line getLineFromPoints(Point p1, Point p2) {
  double A = p2.y-p1.y;
  double B = p1.x-p2.x;
  double C = A*p1.x + B*p1.y;
  return Line(A,B,C);
}

// int = 0 无交点
// int = 1 一个交点
// int = 2 两直线重合
pair<Point, int> intersectPoint(Line l1, Line l2) {
  double det = l1.A*l2.B - l2.A*l1.B;
  if (dcmp(det) == 0) {
    // 两直线平行 重合
	if (dcmp(l1.A*l2.C - l2.A*l1.C) == 0 &&
        dcmp(l1.B*l2.C - l2.B*l1.C) == 0)
	return make_pair(Point(), 2);
    else
	  return make_pair(Point(), 0);
  }
  else {
    double x = (l2.B*l1.C - l1.B*l2.C) / det;
    double y = (l1.A*l2.C - l2.A*l1.C) / det;
    return make_pair(Point(x,y), 1);
  }
}

