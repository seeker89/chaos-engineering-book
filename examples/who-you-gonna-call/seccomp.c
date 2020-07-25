#include <stdio.h>
#include <unistd.h>
#include <seccomp.h>
#include <errno.h>

int main(void)
{
    scmp_filter_ctx ctx;
    int rc; // note, that we totally avoid any error handling here...

    // disable everything by default, by returning EPERM (not allowed)
    ctx = seccomp_init(SCMP_ACT_ERRNO(EPERM));
    // allow write...
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    // and exit - otherwise it would segfault on exit
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    // load the profile
    rc = seccomp_load(ctx);

    // write should succeed, but the pid will not
    fprintf(stdout, "getpid() == %d\n", getpid());

    // release the seccomp context
    seccomp_release(ctx);
}
