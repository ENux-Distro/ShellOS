#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *target = (argc > 1) ? argv[1] : ".";

    DIR *d = opendir(target);
    if (d) {
        struct dirent *dir;
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                printf("%s  ", dir->d_name);
            }
        }
        printf("\n");
        closedir(d);
    } else {
        perror("ls");
        return 1;
    }
    return 0;
}
