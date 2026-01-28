// Be advised, poweroff command will make the system halt
// Since this Distro is meant to be tested on a VM, you can exit the VM if your job is done

#include <sys/reboot.h>
#include <linux/reboot.h>
#include <unistd.h>

int main(void) {
    sync();
    reboot(LINUX_REBOOT_CMD_POWER_OFF);
    return 0;
}
