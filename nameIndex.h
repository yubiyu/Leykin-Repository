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

    /
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
        "n",
        "p",
        "qu", // Q must be followed by U, so I'm counting QU as a single.
        "r",
        "s",
        "t",
        "v",
        "w",
        "x",
        "y",
        "z", // Index 20 (21st position).

        /// Doubles.
        "bl", "br",
        "ch", "cl", "cr",
        "dr",
        "fl", "fr",
        "gl", "gr",
        "ph", "pl", "pr",
        "sh", "sl", "sk", "sw",
        "th", "tr", "tw",
        "wh"
    };



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
        One consonant max.
        */

        std::string previousSyllableLastLetter = "?";
        bool previousSoundIsConsonant = false; // This belongs outside syllable-level loop because the last sound of the previous syllable can be a consonant.
        for(int currentSyllable = 0; currentSyllable < numSyllables; currentSyllable ++)
        {
            int numSounds = 0;
            numSounds = rand()%MAX_SYLLABLES+1;
            bool syllableHasConsonant = false;
            std::string previousSoundLastLetter = "?";

            for(int currentSound = 0; currentSound < numSounds; currentSound ++)
            {
                bool currentSoundIsConsonant = false;

                if(!syllableHasConsonant
                   && !previousSoundIsConsonant
                   && rand()%2 == 1)
                {
                    currentSoundIsConsonant = true;
                    syllableHasConsonant = true;
                }

                if(currentSoundIsConsonant)
                {
                    std::string proposedConsonant = consonants[rand()%consonants.size()];
                    while(proposedConsonant == previousSoundLastLetter)
                        proposedConsonant = consonants[rand()%consonants.size()];

                    syllables[currentSyllable] += proposedConsonant;
                    previousSoundLastLetter = proposedConsonant;
                    previousSoundIsConsonant = true; // current is now previous.
                }
                else // current sound is vowel
                {
                    std::string proposedVowel = vowels[rand()%vowels.size()];
                    while(proposedVowel == previousSoundLastLetter) // Disallow double vowels.
                        proposedVowel = vowels[rand()%vowels.size()];

                    syllables[currentSyllable] += proposedVowel;
                    previousSoundLastLetter = proposedVowel;
                    previousSoundIsConsonant = false; // current is now previous.
                }
            }
            syllableHasConsonant = false;

        }

        for(int i = 0; i < numSyllables; i++)
            name += syllables[i];

        name += " = ";
        for(int i = 0; i < numSyllables; i++)
        {
            if(i < numSyllables - 1)
                syllables[i] += " + ";

            name += syllables[i];
        }

        return name;
    };


};

#endif // NAMEINDEX_H_INCLUDED
