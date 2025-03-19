#pragma once
#include <iostream>
#include <cstdlib>
#include "particle.h"
#include "/public/colors.h"
using namespace std;

class ParticleGraphics {
    private:
        uint8_t r, g, b;

    public:
        ParticleGraphics(uint8_t new_r = 0, uint8_t new_g = 0, uint8_t new_b = 0) {
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
        void setColor(uint8_t new_r, uint8_t new_g, uint8_t new_b) {
			r = new_r;
			g = new_g;
			b = new_b;
		} // sets color

        void drawPoint(int x, int y) {
			resetcolor();
			setbgcolor(r,g,b);
			int col = x;
			int row = y;
			cout << " ";
			cout.flush();
			resetcolor();
		} // draws particle point

        void drawRectangle(int min_x, int max_x, int min_y, int max_y) { 
			assert(min_x < max_x);
			assert(min_y < max_y);
			resetcolor();
			setbgcolor(r,g,b);
			for (int col = min_x; col <= max_x; col++) {
				for (int row = min_y; row <= max_y; row++) {
					movecursor(row,col);
					cout << " ";
				}
			}
			cout.flush();
			reesetcolor();
		} // draws rectangle

        void drawOval(int min_x, int max_x, int min_y, int max_y) { 
			assert(min_x < max_x);
			assert(min_y < max_y);
			resetcolor();
			setbgcolor(r,g,b);
			for (int col = min_x; col <= max_x; col++) {
				for (int row = min_y; row <= max_y; row++) {
					movecursor(row,col);
					cout << " ";
				}
			}
			cout.flush();
			resetcolor();
		} // draws oval - not done!

        void drawPolygon(int min_x, int max_x, int min_y, int max_y) { 
			assert(min_x < max_x);
			assert(min_y < max_y);
			resetcolor();
			setbgcolor(r,g,b);
			for (int col = min_x; col <= max_x; col++) {
				for (int row = min_y; row <= max_y; row++) {
					movecursor(row,col);
					cout << " ";
				}
			}
			cout.flush();
			resetcolor();
			return; 
		} // draws polygon - not done!

        void drawLine(int x, int y) { 
			resetcolor();
			setbgcolor(r,g,b);
			int col = x;
			int row = y;
			if (col == 1);
			if (row == 1);
			cout << " ";
			cout.flush();
			resetcolor();
			return; 
		} // draws line - not done!

};


void ParticleGraphics_test() {
	ParticleGraphics a;
	if (a.get_r() != 0 || a.get_g() != 0 || a.get_b() != 0) {
		cout << "Color in constructor or get function does not work. Please fix." << endl;
		exit (1);
	}
	else {
		cout << "All Tests Passed" << endl;
	}
}
