#include <unistd.h>
#include <fcntl.h>
#include <sys/sysinfo.h>

static void print(const char *s) {
    write(1, s, __builtin_strlen(s));
}

static void print_file(const char *path) {
    char buf[256];
    int fd = open(path, O_RDONLY);
    if (fd < 0) return;
    int n = read(fd, buf, sizeof(buf)-1);
    if (n > 0) {
        buf[n] = 0;
        print(buf);
    }
    close(fd);
}

int main(void) {
    struct sysinfo info;
    sysinfo(&info);

    print("--- MiniFetch ---\n");

    print("CPU: ");
    print_file("/proc/cpuinfo"); 
    print("\nRAM: ");
    char ram[64];
    long mb = info.totalram * info.mem_unit / 1024 / 1024;
    int len = 0;
    long tmp = mb;
    char num[20];
    do {
        num[len++] = '0' + (tmp % 10);
        tmp /= 10;
    } while (tmp);
    for (int i = len-1; i >= 0; i--) ram[len-1-i] = num[i];
    ram[len] = 0;
    print(ram);
    print(" MB\n");

    print("GPU: ");
    print_file("/sys/class/drm/card0/device/vendor");
    print("\n");

    return 0;
}
