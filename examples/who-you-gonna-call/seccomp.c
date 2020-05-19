#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <seccomp.h>
#include <errno.h>

int main(void)
{
    scmp_filter_ctx ctx;
    int rc;

    // disable everything by default, be returning EACCES (access denied)
    ctx = seccomp_init(SCMP_ACT_ERRNO(EACCES));
    // allow write only
    rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    // load the profile
    rc = seccomp_load(ctx);

    // write should succeed, but the pid will not
    fprintf(stdout, "My PID: %d, error: %d\n", getpid(), errno);
    // release the profiel
    seccomp_release(ctx);
}
