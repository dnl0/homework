#include <iostream>
#include <vector>
#include <memory>
#include <string>

class ImageFormat {
    public:
        virtual ~ImageFormat() = default;
        virtual void Load(const std::string& filename) = 0;
        virtual void Save(const std::string& filename) = 0;
        virtual void Display() = 0;
};

class BmpImage {
    public:
        void LoadBmp(const std::string& filename) {
            std::cout << "Loading BMP image from " << filename << "\n";
        }
        void SaveBmp(const std::string& filename) {
            std::cout << "Saving BMP image to " << filename << "\n";
        }
        void DisplayBmp() {
            std::cout << "Displaying BMP image" << "\n";
        }
};

class JpgImage {
    public:
        void LoadBmp(const std::string& filename) {
            std::cout << "Loading JPG image from " << filename << "\n";
        }
        void SaveBmp(const std::string& filename) {
            std::cout << "Saving JPG image to " << filename << "\n";
        }
        void DisplayBmp() {
            std::cout << "Displaying JPG image" << "\n";
        }
};

class PngImage {
    public:
        void LoadPng(const std::string& filename) {
            std::cout << "Loading PNG image from " << filename << "\n";
        }
        void SavePng(const std::string& filename) {
            std::cout << "Saving PNG image to " << filename << "\n";
        }
        void DisplayPng() {
            std::cout << "Displaying PNG image\n";
        }
};

class BmpAdapter : public ImageFormat {
    private:
        BmpImage bmp_image_;
    public:
        void Load(const std::string& filename) override {
            std::cout << "Adapted BMP format\n";
            bmp_image_.LoadBmp(filename);
        }
        void Save(const std::string& filename) override {
            bmp_image_.SaveBmp(filename);
        }
        void Display() override {
            bmp_image_.DisplayBmp();
        }
};

class PngAdapter : public ImageFormat {
    private:
        PngImage png_image_;
    public:
        void Load(const std::string& filename) override {
            std::cout << "Adapted PNG format\n";
            png_image_.LoadPng(filename);
        }
        void Save(const std::string& filename) override {
            png_image_.SavePng(filename);
        }
        void Display() override {
            png_image_.DisplayPng();
        }
};

class JpgAdapter : public ImageFormat {
    private:
        JpgImage jpg_image_;
    public:
        void Load(const std::string& filename) override {
            std::cout << "Adapted JPG format\n";
            jpg_image_.LoadBmp(filename);
        }
        void Save(const std::string& filename) override {
            jpg_image_.SaveBmp(filename);
        }
        void Display() override {
            jpg_image_.DisplayBmp();
        }
};

auto main() -> int{
    std::vector <std::unique_ptr <ImageFormat>> images;
    images.emplace_back(std::make_unique <BmpAdapter>());
    images.emplace_back(std::make_unique <PngAdapter>());

    for (auto& image: images) {
        image->Load("example.png");
        image->Save("example.bmp");
        image->Display();
    }
}
