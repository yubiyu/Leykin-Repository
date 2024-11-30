#ifndef NAMEINDEX_H_INCLUDED
#define NAMEINDEX_H_INCLUDED

#include <vector>

struct NameIndex
{
    /* Hierarchy:
    -Name (the finished product made up of syllables, which are in turn made up of sounds).
    -Syllable (one or more per name)
    -Sound (one or more per syllable)
    */

    static inline const std::map<int, int> numSyllablesRandomDenominators =
    {
        {1, 0},
        {2, 15},
        {3, 66}
    };

    static inline const std::map<int, int> numConsecutiveVowelsRandomDenominators =
    {
        {1, 0},
        {2, 80},
        {3, 98}
    };

    static inline const std::vector<std::string> vowels = {"a", "e", "i", "o", "u"};

    static inline const std::vector<std::string> consonants =
    {
        /// Singles.
        "b", // Index 0
        "c",
        "d",
        "f",
        "g",
        "h",
        "j",
        "k",
        "l",
        "m",
        "n", // Index 10
        "p",
        "r",
        "s",
        "t",
        "v",
        "w",
        "x",
        "y",
        "z", // Index 19 (20th position).

        /// Doubles.
        "bb", "bl", "br", // br is index 20 (21st position).
        "ch", "cl", "cr",
        "dd", "dr",
        "ff", "fl", "fr",
        "gg", "gl", "gr",
        "hh",
        "jj",
        "kk",
        "ll",
        "mm",
        "nn",
        "pp", "ph", "pl", "pr",
        "qu",
        "rr",
        "ss", "sh", "sl", "sk", "sw",
        "tt", "th", "tr", "tw",
        "vv",
        "wh",
        "xx",
        "yy",
        "zz"
    };
    static const int NUM_CONSONANT_SINGLES = 20;
    static const int NUM_CONSONANT_DOUBLES = 40;
    static const int NUM_CONSONANTS = NUM_CONSONANT_SINGLES + NUM_CONSONANT_DOUBLES;

    static const int CONSONANT_SINGLES_MARKER_BEGIN = 0;
    static const int CONSONANT_SINGLES_MARKER_END = CONSONANT_SINGLES_MARKER_BEGIN + NUM_CONSONANT_SINGLES - 1;

    static const int CONSONANT_DOUBLES_MARKER_BEGIN = CONSONANT_SINGLES_MARKER_END+1;
    static const int CONSONANT_DOUBLES_MARKER_END = CONSONANT_DOUBLES_MARKER_BEGIN + NUM_CONSONANT_DOUBLES - 1;

    static std::string Generate()
    {
        std::string name;
        const int MAX_SYLLABLES = 3;
        std::string syllables[MAX_SYLLABLES];

        /// Step 1: Determine number of syllables.
        int numSyllables = 0;
        int numSyllablesRandomNumerator = rand()%100;
        //std::cout << "rand = " << numSyllablesRandomNumerator << std::endl;
        for(std::map<int,int>::const_iterator cit = numSyllablesRandomDenominators.begin(); cit != numSyllablesRandomDenominators.end(); ++cit)
        {
            if(numSyllablesRandomNumerator > (*cit).second)
            {
                numSyllables = (*cit).first;
                //std::cout << numSyllables << "ding " << std::endl;
            }
            else
                break;
        }

        /** Step 2: Generate a syllable under the following rules:
        //One consonant max.
        No consecutive consonant pairs without a vowel in between.
        */

        std::string previousSyllableLastLetter = "?";
        bool previousSoundIsConsonant = false; // This belongs outside syllable-level loop because the last sound of the previous syllable can be a consonant.
        for(int currentSyllable = 0; currentSyllable < numSyllables; currentSyllable ++)
        {
            int numSounds = 0;
            numSounds = rand()%MAX_SYLLABLES+1;
            //bool syllableHasConsonant = false;
            std::string previousSoundLastLetter = "?";

            for(int currentSound = 0; currentSound < numSounds; currentSound ++)
            {
                bool currentSoundWillBeConsonant = false;

                if( // !syllableHasConsonant &&
                   !previousSoundIsConsonant
                   && rand()%2 == 1)
                {
                    currentSoundWillBeConsonant = true;
                    //syllableHasConsonant = true;
                }

                if(currentSoundWillBeConsonant)
                {
                    std::string proposedConsonant;
                    proposedConsonant = RandomConsonant();

                    syllables[currentSyllable] += proposedConsonant;
                    previousSoundLastLetter = proposedConsonant;
                    previousSoundIsConsonant = true; // current is now previous.
                }
                else // current sound is vowel
                {
                    std::string proposedVowel = RandomVowel();
                    while(proposedVowel == previousSoundLastLetter) // Disallow double vowels.
                        proposedVowel = RandomVowel();

                    syllables[currentSyllable] += proposedVowel;
                    previousSoundLastLetter = proposedVowel;
                    previousSoundIsConsonant = false; // current is now previous.
                }
            }
            //syllableHasConsonant = false;

        }

        for(int i = 0; i < numSyllables; i++)
            name += syllables[i];

        if(!name.empty() && std::isalpha(name[0]))
            name[0] = std::toupper(name[0]);

        if(name.size() == 1)
        {
            if(rand()%2 == 0)
                name += RandomVowel();
            else
                name += RandomConsonantDouble();
        }

        if(name.empty())
            name = "???";

        /*
        name += " = ";
        for(int i = 0; i < numSyllables; i++)
        {
            if(i < numSyllables - 1)
                syllables[i] += " + ";

            name += syllables[i];
        }
        */

        return name;
    };

    static std::string RandomConsonant()
    {
        return consonants[rand()%NUM_CONSONANTS];
    }
    static std::string RandomConsonantSingle()
    {
        return consonants[rand()%NUM_CONSONANT_SINGLES];
    }

    static std::string RandomConsonantDouble()
    {
        return consonants[rand()% (CONSONANT_DOUBLES_MARKER_END - NUM_CONSONANT_SINGLES + 1) + NUM_CONSONANT_SINGLES];
    }

    static std::string RandomVowel()
    {
        return vowels[rand()%vowels.size()];
    }


};

#endif // NAMEINDEX_H_INCLUDED
