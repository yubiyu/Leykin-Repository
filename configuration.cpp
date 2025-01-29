#include "configuration.h"

ALLEGRO_CONFIG* Configuration::ancestryCfg;
ALLEGRO_CONFIG* Configuration::roleCfg;
ALLEGRO_CONFIG* Configuration::cargoCfg;
ALLEGRO_CONFIG* Configuration::placeCfg;

void Configuration::LoadStringConfigurations()
{
    al_set_standard_file_interface();

    ancestryCfg = al_load_config_file("configurations/ancestryCfg.cfg");
    if(!ancestryCfg)
        std::cout << "beep boop ancestry" << std::endl;
    roleCfg = al_load_config_file("configurations/roleCfg.cfg");
    if(!roleCfg)
        std::cout << "beep boop role" << std::endl;
    cargoCfg = al_load_config_file("configurations/cargoCfg.cfg");
    if(!cargoCfg)
        std::cout << "beep boop cargo" << std::endl;
    placeCfg = al_load_config_file("configurations/placeCfg.cfg");
    if(!placeCfg)
        std::cout << "beep boop place" << std::endl;
}

void Configuration::UnloadStringConfigurations()
{
    al_destroy_config(ancestryCfg);
    al_destroy_config(roleCfg);
    al_destroy_config(cargoCfg);
    al_destroy_config(placeCfg);
}


std::string Configuration::ReturnString(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
    return al_get_config_value(config, section, key);
}

int Configuration::ReturnInt(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
    std::stringstream strValue;
    strValue << al_get_config_value(config, section, key);

    int intValue;
    strValue >> intValue;

    return intValue;
}
