#include <sys/reboot.h>
#include <linux/reboot.h>
#include <unistd.h>

int main(void) {
    sync();
    reboot(LINUX_REBOOT_CMD_RESTART);
    return 0;
}
