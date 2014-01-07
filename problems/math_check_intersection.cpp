// Write a function to return the intersection geometry of a circle and a square.

struct Coord2D {
    float x;
    float y;
};

// note that a is at the left upper position of d
bool contains(const Coord2D & a, const Coord2D & d, const Coord2D & x) {
    return a.x <= x.x && d.x >= x.x && a.y <= x.y && d.y >= x.y;
}

bool check_intersection(const Coord2D & rect, float l, const Coord2D & circle, float r) {
    if (!contains(rect - Coord2D(l/2, l/2) - (r, r), rect + Coord2D(l/2, l/2) + (r, r), circle)) {
        return false;
    }

    if (contains(rect - Coord2D(l/2, l/2) - (r, 0), rect + Coord2D(l/2, l/2) + (r, 0), circle)) {
        return true;
    }
    if (contains(rect - Coord2D(l/2, l/2) - (0, r), rect + Coord2D(l/2, l/2) + (0, r), circle)) {
        return true;
    }

    // for four different cases.
    if (contains(rect - Coord2D(l/2, l/2) - (r, r), rect + Coord2D(l/2, l/2), circle)) {
        // check distance between circle and rect + Coord2D(l/2, l/2)
        // and if the distance is smaller than r, return true
    }
    return false;
}