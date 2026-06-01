//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <memory>
#include <vector>


class AttributedCharacter {

private:
    static inline std::vector< std::shared_ptr<AttributedCharacter> > characters;
   const char c;
   const bool bold;


   AttributedCharacter(char c, bool bold): c(c),bold(bold) {
   }

   public:

    AttributedCharacter(const AttributedCharacter &other) = delete;

    void operator=(const AttributedCharacter &other) = delete;

    AttributedCharacter(AttributedCharacter &&other) = delete;

    void operator=(AttributedCharacter &&other) = delete;
    ~AttributedCharacter() = default;
public:
      static std::shared_ptr<AttributedCharacter>  createInstance(char c, bool bold) {
          for(auto ac: characters)
          {
              if (ac->c == c && ac->bold == bold) return ac;

          }
          std::shared_ptr<AttributedCharacter> result = std::shared_ptr<AttributedCharacter>(new AttributedCharacter{c,bold});
          characters.push_back(result);
          return result;
      }

    [[nodiscard]] char get_c() const {
        return c;
    }

    [[nodiscard]] bool is_bold() const {
        return bold;
    }
};
