#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include "/public/colors.h"
using namespace std;

class ParticleGraphics {
    private:
        uint8_t r, g, b; // color: red, green, blue

    public:
        ParticleGraphics(uint8_t new_r = 0, uint8_t new_g = 0, uint8_t new_b = 0) { 
			r = new_r;
			g = new_g;
			b = new_b;

		} // sets particle color 

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
		} // sets particle to a new color

        void drawPoint(int x, int y) {
			resetcolor();
			setbgcolor(r,g,b);
			movecursor(x,y);
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
					movecursor(col,row);
					cout << " ";
				}
			}
			cout.flush();
			resetcolor();
		} // draws rectangle

        void drawCircle(int x, int y, int radius) { 
			resetcolor();
			setbgcolor(r,g,b);
			for (int col = x; col <= (2*radius); ++col) {
				for (int row = y; row <= (2*radius); ++row) {
					int distance = sqrt(pow((col-radius),2) + pow((row-radius),2));
					if (distance <= radius) {
						movecursor(col,row);
						cout << " ";
					}
				}
			}
			cout.flush();
			resetcolor();
		} // draws circle with particles

		void drawOs(int x, int y) {
			resetcolor();
			setcolor(r,g,b);
			movecursor(x,y);
			cout << "⬤ " << endl;
			cout.flush();
			resetcolor();
		} // draws unicode circle

		void drawSparks(int x, int y) {
			resetcolor();
			setcolor(r,g,b);
			cout << "⊹₊⁺" << endl; // feel free to change the string 
			cout.flush();
			resetcolor();
		} // draws unicode sparks

		void drawCustom(int x, int y, string Custom) {
			resetcolor();
			setcolor(r,g,b);
			cout << Custom << endl;
			cout.flush();
			resetcolor();
		} // draws whatever custom string input

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
	ParticleGraphics b(204,153,255);
	ParticleGraphics c;
	c.setColor(51,255,255);
	if (a.get_r() != 0 || a.get_g() != 0 || a.get_b() != 0) { // Checks default constructor
		cout << "Color in constructor or get function does not work. Please fix." << endl;
		exit (1);
	}
	else if (b.get_r() != 204 || b.get_g() != 153 || b.get_b() != 255) { // Checks if constructor takes on color 
		cout << "Color in constructor or get function does not work. Please fix." << endl;
		exit (1);
	}
	else if (c.get_r() != 51 || c.get_g() != 255 || c.get_b() != 255) { // Checks if setColor sets a new color
		cout << "Color in setColor does not work. Please fix." << endl;
	}
	else {
		cout << "Color works" << endl;
	}
	b.drawPoint(1,1); // checking on constructor color in tests
	c.drawPoint(1,1); // checking on setColor color in tests
	cout << "\n";
	//cout << "Checking draw functions" << endl; 
	//b.drawRectangle(0,10,0,10);
	//c.drawCircle(0,0,10);
	//c.drawOs(0,0);
	//c.drawSparks(0,0);
	//c.drawCustom(0,0, "₍^. .^₎⟆");
}
