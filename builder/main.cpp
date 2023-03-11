#include <iostream>

class SpellChecker {
public:
    virtual ~SpellChecker() {}
    virtual bool checkSpelling(const std::string& word) = 0;
};

class EnglishSpellChecker : public SpellChecker {
public:
    bool checkSpelling(const std::string& word) override {
        std::cout << "some English word checking\n";
        return true;
    }
};

class FrenchSpellChecker : public SpellChecker {
public:
    bool checkSpelling(const std::string& word) override {
        std::cout << "some French word checking\n";
        return true;
    }
};

class GermanSpellChecker : public SpellChecker {
public:
    bool checkSpelling(const std::string& word) override {
        std::cout << "some German word checking\n";
        return true;
    }
};

class SpellCheckerBuilder {
public:
    virtual ~SpellCheckerBuilder() {}
    virtual void setLanguage(const std::string& language) = 0;
    virtual SpellChecker* getSpellChecker() = 0;
};

class EnglishSpellCheckerBuilder : public SpellCheckerBuilder {
private:
    EnglishSpellChecker* m_spellChecker;

public:
    EnglishSpellCheckerBuilder() {
        std::cout << "1. building an English spell checker\n";
        m_spellChecker = new EnglishSpellChecker();
    }

    void setLanguage(const std::string& language) override {
        if (language != "English") {
            throw std::invalid_argument("Unsupported language");
        }
    }

    SpellChecker* getSpellChecker() override {
        return m_spellChecker;
    }
};

class FrenchSpellCheckerBuilder : public SpellCheckerBuilder {
private:
    FrenchSpellChecker* m_spellChecker;

public:
    FrenchSpellCheckerBuilder() {
        std::cout << "1. building a French spell checker\n";
        m_spellChecker = new FrenchSpellChecker();
    }

    void setLanguage(const std::string& language) override {
        if (language != "French") {
            throw std::invalid_argument("Unsupported language");
        }
    }

    SpellChecker* getSpellChecker() override {
        return m_spellChecker;
    }
};

class GermanSpellCheckerBuilder : public SpellCheckerBuilder {
private:
    GermanSpellChecker* m_spellChecker;

public:
    GermanSpellCheckerBuilder() {
        std::cout << "1. building a German spell checker\n";
        m_spellChecker = new GermanSpellChecker();
    }

    void setLanguage(const std::string& language) override {
        if (language != "German") {
            throw std::invalid_argument("Unsupported language");
        }
    }

    SpellChecker* getSpellChecker() override {
        return m_spellChecker;
    }
};

class SpellCheckerDirector {
private:
    SpellCheckerBuilder* m_builder;

public:
    SpellCheckerDirector(SpellCheckerBuilder* builder) : m_builder(builder) {}

    SpellChecker* createSpellChecker(const std::string& language) {
        std::cout << "2. creating " + language + "spell checker using a builder that was created\n";
        m_builder->setLanguage(language);
        return m_builder->getSpellChecker();
    }
};

auto main() -> int {
    SpellCheckerDirector spell_checker_director {new EnglishSpellCheckerBuilder {}};
    
    auto spell_check = spell_checker_director.createSpellChecker("English");

    std::cout << "\n";
    if (spell_check->checkSpelling("word")) {
        std::cout << "word is correct\n";
    } else {
        std::cout << "word isn't correct\n";
    }
}
