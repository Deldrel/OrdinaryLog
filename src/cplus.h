#ifndef TEMPLATE_CPLUS_H
#define TEMPLATE_CPLUS_H

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>

template<typename Template>
inline void print(Template t) {
    std::cout << t;
}

template<typename Template>
inline void print(const std::vector<Template> &vector) {
    std::string string;
    string.reserve(vector.size());
    for (Template i : vector) string += std::to_string(i) + " ";
    std::cout << string << std::endl;
}

template<typename Template>
inline void println(Template t) {
    std::cout << t << std::endl;
}

inline int random(int min, int max) {
    static std::mt19937 randGen(time(nullptr));
    return std::uniform_int_distribution<>(min, max)(randGen);
}

inline float map(float n, float min1, float max1, float min2, float max2) {
    return min2 + (max2 - min2) * ((n - min1) / (max1 - min1));
}

inline bool inbound(int x, int y, int upperLeftX, int upperLeftY, int downRightX, int downRightY) {
    return x >= upperLeftX && x < downRightX && y >= upperLeftY && y < downRightY;
}

inline void resizeImage(const sf::Image &originalImage, sf::Image &resizedImage) {
    const sf::Vector2u originalImageSize{originalImage.getSize()};
    const sf::Vector2u resizedImageSize{resizedImage.getSize()};
    for (unsigned int y{0u}; y < resizedImageSize.y; ++y) {
        for (unsigned int x{0u}; x < resizedImageSize.x; ++x) {
            unsigned int origX{
                    static_cast<unsigned int>(static_cast<double>(x) / resizedImageSize.x * originalImageSize.x)};
            unsigned int origY{
                    static_cast<unsigned int>(static_cast<double>(y) / resizedImageSize.y * originalImageSize.y)};
            resizedImage.setPixel(x, y, originalImage.getPixel(origX, origY));
        }
    }
}

inline sf::Image newImage(const std::string &path, int resizedWidth, int resizedHeight) {
    sf::Image originalImage;
    sf::Image resizedImage;
    resizedImage.create(resizedWidth, resizedHeight);
    if (!originalImage.loadFromFile(path)) return sf::Image();
    resizeImage(originalImage, resizedImage);
    return resizedImage;
}


inline void
drawLine(float x1, float y1, float x2, float y2, float thickness, sf::Color color, sf::RenderWindow &window) {
    sf::Vector2f point1 = {x1, y1};
    sf::Vector2f point2 = {x2, y2};
    sf::Vector2f direction = point2 - point1;
    sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

    sf::Vector2f offset = (thickness / 2.f) * unitPerpendicular;

    sf::Vertex line[] = {
            sf::Vertex(point1 + offset, color),
            sf::Vertex(point2 + offset, color),
            sf::Vertex(point2 - offset, color),
            sf::Vertex(point1 - offset, color)
    };

    window.draw(line, 4, sf::Quads);
}

#endif
