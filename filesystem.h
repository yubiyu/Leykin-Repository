#ifndef FILESYSTEM_H_INCLUDED
#define FILESYSTEM_H_INCLUDED

#include <allegro5/allegro_physfs.h>
#include <physfs.h>

struct Filesystem
{
    static void Initialize(char **argv)
    {
        PHYSFS_init(argv[0]);
        PHYSFS_mount("./data.zip", "/", 1);
    }
    static void Uninitialize()
    {
        PHYSFS_deinit();
    }

    static void SetStandardFileInterface()
    {
        al_set_standard_file_interface();
    }
    static void SetPhysfsFileInterface()
    {
        al_set_physfs_file_interface();
    }
};

#endif // FILESYSTEM_H_INCLUDED
