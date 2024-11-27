#ifndef ATTRIBUTESINDEX_H_INCLUDED
#define ATTRIBUTESINDEX_H_INCLUDED

struct AttributeIndex
{
    enum enumBeingAttributes
    {
        ATTRIBUTE_BODY = 0,
        ATTRIBUTE_MIND = 1,
        ATTRIBUTE_SPIRIT = 2
    };
    static const int ATTRIBUTE_MARKER_FIRST = ATTRIBUTE_BODY;
    static const int ATTRIBUTE_MARKER_LAST = ATTRIBUTE_SPIRIT;
    static const int NUM_ATTRIBUTES = ATTRIBUTE_MARKER_LAST+1;

    inline static const std::map<unsigned,std::string>attributeNames
    {
        {ATTRIBUTE_BODY, "Body"},
        {ATTRIBUTE_MIND, "Mind"},
        {ATTRIBUTE_SPIRIT, "Spirit"}
    };
};

#endif // ATTRIBUTESINDEX_H_INCLUDED
