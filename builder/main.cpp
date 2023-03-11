#include <iostream>
#include <unordered_map>

class SpellChecker {
public:
    virtual ~SpellChecker() {}
    virtual SpellChecker* clone() const = 0;
    virtual bool checkSpelling(const std::string& word) = 0;
};

class EnglishSpellChecker : public SpellChecker {
public:
    EnglishSpellChecker() = default;
    EnglishSpellChecker(const EnglishSpellChecker&) = default;

    SpellChecker* clone() const override {
        std::cout << "2. cloning English spell checker\n";
        return new EnglishSpellChecker(*this);
    }

    bool checkSpelling(const std::string& word) override {
        std::cout << "some English word checking\n";
        return true;
    }
};

class FrenchSpellChecker : public SpellChecker {
public:
    FrenchSpellChecker() = default;
    FrenchSpellChecker(const FrenchSpellChecker&) = default;

    SpellChecker* clone() const override {
        std::cout << "2. cloning French spell checker\n";
        return new FrenchSpellChecker(*this);
    }

    bool checkSpelling(const std::string& word) override {
        std::cout << "some French word checking\n";
        return true;
    }
};

class GermanSpellChecker : public SpellChecker {
public:
    GermanSpellChecker() = default;
    GermanSpellChecker(const GermanSpellChecker&) = default;

    SpellChecker* clone() const override {
        std::cout << "2. cloning German spell checker\n";
        return new GermanSpellChecker(*this);
    }

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
        std::cout << "2. creating " + language + " spell checker using a builder that was created\n";
        m_builder->setLanguage(language);
        return m_builder->getSpellChecker();
    }
};

class SpellCheckerFactory {
private:
    std::unordered_map<std::string, SpellChecker*> m_prototypes;

public:
    SpellCheckerFactory() {
        m_prototypes.emplace("English", new EnglishSpellChecker());
        m_prototypes.emplace("French", new FrenchSpellChecker());
        m_prototypes.emplace("German", new GermanSpellChecker());
    }

    SpellChecker* createSpellChecker(const std::string& language) {
        std::cout << "1. creating " + language + " spell checker\n";
        if (m_prototypes.find(language) == m_prototypes.end()) {
            throw std::invalid_argument("Unsupported language");
        }
        return m_prototypes[language]->clone();
    }
};

auto main() -> int {
    {
        SpellCheckerDirector spell_checker_director {new EnglishSpellCheckerBuilder {}};
        
        auto spell_check = spell_checker_director.createSpellChecker("English");
    
        std::cout << "\n";
        if (spell_check->checkSpelling("word")) {
            std::cout << "word is correct\n";
        } else {
            std::cout << "word isn't correct\n";
        }

        delete spell_check;
    }
    
    std::cout << "\n--------------------------------------------\n\n";

    {
        SpellCheckerFactory spell_checker_factory {};
        auto spell_check = spell_checker_factory.createSpellChecker("French");
        
        std::cout << "\n";
        if (spell_check->checkSpelling("word")) {
            std::cout << "word is correct\n";
        } else {
            std::cout << "word isn't correct\n";
        }

        delete spell_check;
    }
}
