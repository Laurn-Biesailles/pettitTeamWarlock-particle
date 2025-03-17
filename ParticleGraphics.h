#pragma once
#include <iostream>
#include "/public/colors.h"
using namespace std;

class ParticleGraphics {
    private:
        uint8_t r, g, b;

    public:
        ParticleGraphics(uint8_t new_r = 0, uint8_t new_g = 0, uint8_t 0) {
			r = new_r;
			g = new_g;
			b = new_b;
		}
        uint8_t get_r() const {
            return r;
        }
        void set_r(uint8_t new_r) {
            r = new_r;
        }
		uint8_t get_g() const {
			return g;
		}
		void set_g(uint8_t new_g) {
			g = new_g;
		}
		uint8_t get_b() const {
			return b;
		}
		void set_b(uint8_t new_b) {
			b = new_b;
		}
        void setColor(uint8_t r, uint8_t g, uint8_t b) { return 0; } // sets color
        void drawPoint(double x, double y) { return 0; } // draws particle point
        void drawRectangle(double x, double y) { return 0;} // draws rectangle
        void drawOval(double x, double y) { return 0; } // draws oval
        void drawPolygon(double x, double y) { return 0; } // draws polygon
        void drawLine(double x, double y) { return 0; } // draws line

};

void ParticleGraphics_test() {
	ParticleGraphics a;
	if (get_r() || get_g() || get_b() != 0) {
		cout << "Color in constructor or get function does not work. Please fix." << endl;
		exit (1);
	}
	if (a.setColor(0,0) || a.drawPoint(0,0) || a.drawRectangle(0,0) || a.drawOval(0,0) || a.drawPolygon(0,0) || a.drawLine(0,0) != 0) { 
		cout << "Other methods have not been stubbed out." << endl; 
		exit(1);
	}
}
