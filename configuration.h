#ifndef CONFIGURATION_H_INCLUDED
#define CONFIGURATION_H_INCLUDED

#include <allegro5/allegro5.h>

#include <iostream>
#include <sstream>

struct Configuration
{
    static ALLEGRO_CONFIG* optionsCfg;

    static ALLEGRO_CONFIG* ancestryCfg;
    static ALLEGRO_CONFIG* roleCfg;
    static ALLEGRO_CONFIG* cargoCfg;
    static ALLEGRO_CONFIG* placeCfg;

    static void LoadStringConfigurations();
    static void UnloadStringConfigurations();

    static std::string ReturnString(const ALLEGRO_CONFIG* config, const char* section, const char* key);
    static int ReturnInt(const ALLEGRO_CONFIG* config, const char* section, const char* key);

};

#endif // CONFIGURATION_H_INCLUDED
