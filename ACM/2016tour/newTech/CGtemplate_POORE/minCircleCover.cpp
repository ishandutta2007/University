void minCircleCover(int n, Point &c, double &r) {
  random_shuffle(p, p+n); c = p[0]; r = 0;
  for (int i = 1; i < n; i++) if (Lenth(p[i]-c) > r + eps) {
      c = p[i]; r = 0;
      for (int j = 0; j < i; j++) if (Lenth(p[j]-c) > r + eps) {
          c.x = (p[i].x+p[j].x)/2.0;
          c.y = (p[i].y+p[j].y)/2.0;
          r = Lenth(p[j]-c);
          for (int k = 0; k < j; k++) if (Lenth(p[k]-c) > r + eps) {
              c = outerCircle(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
              r = Lenth(p[i]-c);
          }
      }
  }
}

