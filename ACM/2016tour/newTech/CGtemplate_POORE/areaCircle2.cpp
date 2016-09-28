double areaCircle2(double x1, double y1, double r1, double x2, double y2, double r2) {
  double d = dist(x1, y1, x2, y2);
  if (r1+r2 < d-eps) return 0.0;
  if (fabs(r1-r2) > d-eps) {
    double tmp = min(r1, r2);
    return pi*tmp*tmp;
  }
  double ang1 = acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
  double ang2 = acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
  double ret = ang1*r1*r1+ang2*r2*r2-d*r1*sin(ang1);
  return ret;
}

