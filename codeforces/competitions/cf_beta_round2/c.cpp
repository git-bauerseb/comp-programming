#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

ld distToCircle(ld midX, ld midY, ld radius, ld x, ld y) {
    ld dist = std::sqrt((midX - x) * (midY - y) + (midY - y));
    return dist - radius;
}

void circle_circle_intersection(ld x0, ld y0, ld r0,
                                ld x1, ld y1, ld r1,
                                ld* x_i, ld* y_i,
                                ld* x_ii, ld* y_ii) {

    ld a, dx, dy, d, h, rx, ry;
    ld x2, y2;

    dx = x1 - x0;
    dy = y1 - y0;

    d = std::hypot(dx, dy);

    a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d);
    x2 = x0 + (dx * a/d);
    y2 = y0 + (dy * a/d);
    h = sqrt((r0*r0) - (a*a));
    rx = -dy * (h/d);
    ry = dx * (h/d);
    *x_i = x2 + rx;
    *x_ii = x2 - rx;
    *y_i = y2 + ry;
    *y_ii = y2 - ry;
}

void solution() {
    ld c1x, c1y, r1, c2x, c2y, r2, c3x, c3y, r3;

    cin >> c1x >> c1y >> r1
        >> c2x >> c2y >> r2
        >> c3x >> c3y >> r3;

    vector<pair<ld,ld>> points;
   
    // Equivalent distance from first to second
    ld r = (r1/r2);
    ld r_inv = (r2/r1);
    ld total = r + r_inv;

    ld d1 = std::sqrt((c1x - c2x)*(c1x - c2x) + (c1y - c2y)*(c1y - c2y));
    ld p[2];
    p[0] = (r/total) * (c2x - c1x) + c1x;
    p[1] = (r/total) * (c2y - c1y) + c1y;

    points.push_back({p[0], p[1]});

    p[0] = (r_inv/total) * (c1x - c2x) + c2x;
    p[1] = (r_inv/total) * (c1y - c2y) + c2y;
    points.push_back({p[0], p[1]});

    for (auto& e : points) printf("%.5Lf %.5Lf\n", e.first, e.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
