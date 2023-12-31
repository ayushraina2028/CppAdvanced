#include <iostream>
#include <vector>
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

int orientation(Point* a, Point* b, Point* c) {

    // Calculating Difference in Slopes
    int diffInSlopes = (b->y - a->y)*(c->x - b->x) - (c->y - b->y)*(b->x - a->x);

    // Collinearity
    if(diffInSlopes == 0) return 0;

    
    if(diffInSlopes < 0) return 2; // => counter clockwise
    else return 1; // => clockwise

}

void JarvisConvexHull(vector <Point*> Points) {
    int n = Points.size();
    if(n < 3) return;

    // Result Vector
    vector <Point*> Jarvis;
    
    // Finding Leftmost Point to start
    int left = 0;
    for(int i = 1;i < n;i++) {
        if(Points[i]->x < Points[left]->x) {
            left = i;
        }
    }
    cout << left << endl;

    int p = left;
    int q;
    
    do{ 
        // Adding Current point to hull
        Jarvis.push_back(Points[p]);

        // => Search for q such that orientation (p,q,x) is counterClockWise for all points x;
        q = (p+1) % n;

        // Checking Orientation;
        for(int i = 0;i < n;i++) {
            if(orientation(Points[p], Points[q], Points[i])==2) {  // if you check orientation of (p,i,q) -> this will make hull from down
                q = i;
                cout << q << endl;
            }
        }
        
        // Now q is most CounterClockwise with respect to p
        // Setting p as q for next
        p = q;
        

    } while(p != left);

    for(int i = 0;i < Jarvis.size();i++) {
        cout << Jarvis[i]->x << " " << Jarvis[i]->y << endl;
    }
    

}

int main() {

    // => Describing Points
    Point* a = new Point(1,2);
    Point* b = new Point(7,4);
    Point* c = new Point(3,1);
    Point* d = new Point(6,6);
    Point* e = new Point(4,3);
    Point* f = new Point(5,3);
    
    
    vector <Point*> Points;
    Points.push_back(a);
    Points.push_back(b);
    Points.push_back(c);
    Points.push_back(d);
    Points.push_back(e);
    Points.push_back(f);
    
    
    JarvisConvexHull(Points);
}