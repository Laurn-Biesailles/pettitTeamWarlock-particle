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
        //void setColor(Color color) {} // sets color
        //void drawPoint(double x, double y) {} // draws particle point
        //void drawRectangle(double x, double y) {} // draws rectangle
        //void drawOval(double x, double y) {} // draws oval
        //void drawPolygon(double x, double y) {} // draws polygon
        //void drawLie(double x, double y) {} // draws line

};

