// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct Point
{
    double x, y;
};

// A global point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
double distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (fabs(val) < EPS) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
stack<Point> convexHull(Point points[], int n){
   int menor = 0;
   for(int i = 0; i<n; i++){
      if(points[i].y < points[menor].y) menor = i;
      else if(points[i].y == points[menor].y) {
        if(points[i].x < points[menor].x) menor = i;
      } 
   }

   // Place the bottom-most point at first position
   swap(points[0], points[menor]);

   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);

   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;

       points[m] = points[i];
       m++;  // Update size of modified array
   }

   if (m < 3) return;

   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   for (int i = 3; i < m; i++)
   {
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }

   // Now stack has the output points, print contents of stack
   return S;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<Point> p(n);
    for(int i = 0; i<n; i++){
        ld a, b;
        cin>>a>>b;
        p[i] = Point(a, b);
    }
    int pivot = downmost(p);
    swap(p[0], p[pivot]);
    sort(p.begin() + 1, p.end(), cmp);
    vector<Point> h = ConvexHull(p);

    ld maior_dist = 0;
    int m_i = -1, m_j = -1;
    for(int i = 0; i<h.size(); i++){
        for(int j = 0; j<h.size(); j++){
            if(i == j) continue;
            ld dist = distance(h[i], h[j]);
            if(dist > maior_dist) {
                maior_dist = dist;
                m_i = i;
                m_j = j;
            }
        }
    }
    pair<ld, ld> center = {(h[m_i].x + h[m_j].x)/2.0, (h[m_i].y + h[m_j].y)/2.0};
    ld radius = sqrt(maior_dist)/2.0;
    ld circ = radius*2*3.14*4;
    printf("%.2f %.2f %.2f %.2f\n", center.first, center.second, radius, circ); 
}