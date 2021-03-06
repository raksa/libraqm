#include <iostream>

extern "C" {
  #include "utils.h"
}

int main(int argc, char *argv[])
{
  const char *fontfile;
  const char *text;
  const char *direction;
  const char *language;

  std::cout << "\n\n\n";
  if (argc < 5)
  {
    std::cout << "Usage: " << argv[0] << " FONT_FILE(./Battambang-Regular.ttf) TEXT(\"សោះស្តី\") DIRECTION(r|l) LANG(km|en)\n";
    std::cout << "LANG(language code) https://www.w3.org/International/articles/language-tags/\n";
    return 1;
  }
  fontfile = argv[1];
  text = argv[2];
  direction = argv[3];
  language = argv[4];

  const char *str = getGlyphs(fontfile, text, direction, language);
  std::cout << str;

  return 0;
}