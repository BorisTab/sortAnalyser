#include <SFML/Graphics/Color.hpp>

namespace Colors {
    const sf::Color darkPurple = sf::Color(79, 0, 112, 255);
    const sf::Color orange = sf::Color(255, 153, 0, 255);
}

namespace MaxValues {
    constexpr size_t maxCharactersInButtonText = 1000;
}

namespace ButtonsValues {
    constexpr size_t buttonDistance = 30;
    constexpr size_t buttonWidth = 150;
    constexpr size_t buttonHeight = 50;
    constexpr size_t buttonDownOffset = 80;
}

namespace Paths {
    constexpr char fontFilePath[] = "/home/boris/CLionProjects/sortAnalyser/UserInterface/Fonts/JosefinSans-Regular.ttf";
}
