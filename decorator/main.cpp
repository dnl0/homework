#include <iostream>
#include <array>
#include <utility>

class Rectangle {
    public:
        std::array <std::pair <int, int>, 4> coordinates;
        virtual void Draw() = 0;
};

class ExtendedRectangle : public Rectangle {
    public:
        std::string color;

        void Draw() override {
            std::cout << "raw information on ExtendedRectangle coordinates\n";
        }
};

class Decorator : public Rectangle {
    protected:
        Rectangle* rectangle_;
    public:
        void Draw() override {
            rectangle_->Draw();
        }
};

class ConsoleRectangleDecorator: public Decorator {
    public:
        ConsoleRectangleDecorator(Rectangle* u_rectangle)
        {
            rectangle_ = u_rectangle;
        }

        void Draw() override {
            std::cout << "drawing rectangle in the console\n";
        }
};

class GUIRectangleDecorator : public Decorator {
    public:
        GUIRectangleDecorator(Rectangle* u_rectangle)
        {
            rectangle_ = u_rectangle;
        }

        void Draw() override {
            std::cout << "drawing rectangle in the GUI\n";
        }
};

auto main() -> int {
    Rectangle* extended_rectangle = new ExtendedRectangle {};

    ConsoleRectangleDecorator console_rectangle_decorator {extended_rectangle};
    console_rectangle_decorator.Draw();
    GUIRectangleDecorator gui_rectangle_decorator {extended_rectangle};
    gui_rectangle_decorator.Draw();

    delete extended_rectangle;
}
