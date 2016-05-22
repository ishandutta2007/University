// get the exponents of 2 and 3 in the prime factorization of x:
tuple<int,int> get32(int x)
{
  int r2 = 0, r3 = 0;
  while (x % 2 == 0) {
    r2++;
    x /= 2;
  }
  while (x % 3 == 0) {
    r3++;
    x /= 3;
  }
  return make_tuple(r2,r3);
}

set<vector<int> > seen; // a set of all the vectors p we have reached in the DFS:
 
void try_it(vector<int> & p) // DFS
{
  if (seen.count(p) == 0) {
    seen.insert(p);
    // pick two kinds of pairs:
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        if (p[a*3 + b] == 0) {
          continue;
        }
        for (int c = 0; c < 3; c++) {
          for (int d = 0; d < 3; d++) {
            if (p[c*3 + d] == 0) {
              continue;
            }
            for (int i = 0; i < 2; i++) {
              // i = 0: minimize
              // i = 1: maximize
              vector<int> q = p;
              q[a*3 + b]--;
              q[c*3 + d]--;
              if (q[a*3 + b] < 0) {
                // if there were equal pairs we decremented twice
                continue;
              }
              int s, t;
              if (i == 0) {
                s = std::min(a,c);
                t = std::min(b,d);
              } else {
                s = std::max(a,c);
                t = std::max(b,d);
              }    
              // increment the count of the new pair:
              q[s*3 + t]++;
              if (seen.count(q) == 0) {
                try_it(q); // continue the search now with q
              }
            }
          }
        }
      }
    }
  }
}
 
string isPossible(vector<int> x, int t)
{
  int w2,w3;
  tie(w2,w3) = get32(t);
  vector<int> p(9);
  for (int y: x) {
    int p2,p3;
    tie(p2,p3) = get32(y);
    // assign 0, 1 or 2, depending if the exponent is less, equal or more:
    if (p2 == w2) {
      p2 = 1;
    } else if (p2 > w2) {
      p2 = 2;
    } else {
      p2 = 0;
    }
    if (p3 == w3) {
      p3 = 1;
    } else if (p3 > w3) {
      p3 = 2;
    } else {
      p3 = 0;
    }
    if (p2 == 1 && p3 == 1) {
      // for (1,1) we need the accurate count
      p[ p2 * 3 + p3 ]++;
    } else {
      // for other pairs, we only need to know if there is at least one of them
      p[ p2 * 3 + p3 ] = 1;
    }
  }
  try_it(p);
   
  vector<int> want(9, 0);
  want[1*3 + 1] = 1;
   
  // perform the search.
  if ( seen.count(want) ) {
    return "Possible";
  } else {
    return "Impossible";
  }
}
