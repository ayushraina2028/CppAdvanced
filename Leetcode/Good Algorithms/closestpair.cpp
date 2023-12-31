#include <bits/stdc++.h>
using namespace std;

class Point{
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// Comparison functions that can be passed into sort function later
bool compareX(Point* a, Point* b) {
    return a->x < b->x;

}

bool compareY(Point* a, Point* b) {
    return a->y < b->y;
}

float findDistance(Point* a, Point* b) {
    return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
}

float bruteforce(vector < Point* > points) {
    float ans = FLT_MAX;
    for(int i = 0; i < points.size();i++) {
        for(int j = i+1;j < points.size();j++) {
            if(findDistance(points[i], points[j]) < ans) ans = findDistance(points[i], points[j]);
        }
    }
    return ans;
}

float stripClosest(vector < Point* > strip, float delta) {
    float min = delta;

    // sort using Y values
    sort(strip.begin(), strip.end(), compareY);

    // Compare with neighbouring points 
    for(int i = 0;i < strip.size();i++) {
        for(int j = i+1;j < strip.size() && (strip[j]->y - strip[i]->y) < min;j++) {
            if(findDistance(strip[i],strip[j]) < min) min = findDistance(strip[i],strip[j]);
        }
    }

    return min;
}

float findClosestDistance(vector < Point* > points) {

    // sort x - coordinates
    sort(points.begin(), points.end(), compareX);
    int n = points.size();

    // If there are 2 or 3 Points, use bruteforce
    if(n <= 3) {
        return bruteforce(points);
    }

    // else divide and conquer
    int mid = n/2;
    Point* midPoint = points[mid];

    vector < Point* > left;
    vector < Point* > right;

    for(int i = 0;i < mid;i++) {
        left.push_back(points[i]);
    }
    for(int i = mid;i < n;i++) {
        right.push_back(points[i]);
    }

    float left_smallest = findClosestDistance(left);
    float right_smallest = findClosestDistance(right);

    float delta = min(left_smallest,right_smallest);

    // Creating delta strip
    vector < Point* > strip;
    for(int i = 0; i < n;i++) {
        if(abs(points[i]->x - midPoint->x) < delta) {
            strip.push_back(points[i]);
        }
    }
    for(auto ele : strip) {
        cout << ele->x << " ";
    }
    cout << endl;

    // finding minimum elements in a strip
    return min(delta, stripClosest(strip, delta));
}

int main() {

    Point* a = new Point(3,6);
    Point* b = new Point(2,3);
    Point* c = new Point(12,4);
    Point* d = new Point(13,7);
    Point* e = new Point(6,4);
    Point* f = new Point(7,2);
    Point* g = new Point(4,9);
    Point* h = new Point(7,8);
    Point* i = new Point(10,2);
    Point* j = new Point(8,7);

    // Storing them in a vector
    vector < Point* > points = {a,b,c,d,e,f,g,h,i,j};

    float closestDistance = findClosestDistance(points);
    cout << closestDistance << endl;
    
}


