#include <iostream>
using namespace std;

class ParticleGraphics {
    private:
        Color color;
    public:
        ParticleGraphics() {}
        Color get_color() const {
            return color;
        }
        void set_color(Color new_color) {
            color = new_color;
        }
        void setColor(Color color) { return 0; } // sets color
        void drawPoint(double x, double y) { return 0; } // draws particle point
        void drawRectangle(double x, double y) { return 0;} // draws rectangle
        void drawOval(double x, double y) { return 0; } // draws oval
        void drawPolygon(double x, double y) { return 0; } // draws polygon
        void drawLie(double x, double y) { return 0; } // draws line

};

