#ifndef __KSU_UAPI_APP_PROFILE_H
#define __KSU_UAPI_APP_PROFILE_H

#include <linux/types.h>

#ifndef KSU_MAX_PACKAGE_NAME
#define KSU_MAX_PACKAGE_NAME 256
#endif

#define KSU_APP_PROFILE_VER 1
#define KSU_MAX_GROUPS 32

struct root_profile {
	uid_t uid;
	gid_t gid;
	int groups_count;
	gid_t groups[KSU_MAX_GROUPS];
	struct {
		unsigned long long effective;
	} capabilities;
	char namespaces[KSU_MAX_PACKAGE_NAME];
	int selinux_domain;
};

struct non_root_profile {
	uid_t uid;
	int umask;
};

struct app_profile {
	int version;
	char key[KSU_MAX_PACKAGE_NAME];
	struct root_profile rp;
	struct non_root_profile nrp;
};

#endif