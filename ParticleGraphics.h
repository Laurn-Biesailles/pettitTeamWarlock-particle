#include <iostream>
#include "/public/colors.h"
using namespace std;

class ParticleGraphics {
    private:
        Color color;

    public:
        ParticleGraphics(Color new_color = RED) {
			color = new_color;
		}
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
        void drawLine(double x, double y) { return 0; } // draws line

};

void ParticleGraphics_test() {
	ParticleGraphics a;
	if (a.get_color() != RED) {
		cout << "Color in constructor or get function does not work. Please fix." << endl;
		exit (1);
	}
	if (a.setColor(0,0) || a.drawPoint(0,0) || a.drawRectangle(0,0) || a.drawOval(0,0) || a.drawPolygon(0,0) || a.drawLine(0,0) != 0) { 
		cout << "Other methods have not been stubbed out." << endl; 
		exit(1);
	}
}
