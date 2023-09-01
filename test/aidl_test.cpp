/**
 * Author: 二的次方
 */

#define LOG_TAG "aidl_test"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <log/log.h>
#include <utils/Log.h>


#include <binder/IServiceManager.h>
#include <my/test/IFoo.h>

using my::test::IFoo;

int main()
{
    const ::android::String16 service_name = IFoo::descriptor;
    // waiting until service comes up
    ::android::sp<IFoo> foo = ::android::waitForService<IFoo>(service_name);

    foo->setFoo(99);

    int x = 0;
    foo->getFoo(&x);
    fprintf(stderr, "getFoo %d \n", x);


    getchar();

    return 0;
}