/**
 * Author: Roger
 */

#define LOG_TAG "aidl_test"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <log/log.h>
#include <utils/Log.h>

#include <aidl/roger/test/demo/ITestDemo.h>
#include <android/binder_manager.h>

using AidlITestDemo = aidl::roger::test::demo::ITestDemo;

int main()
{
    const std::string service_name = std::string(AidlITestDemo::descriptor) + "/default";
    // waiting until service comes up
    std::shared_ptr<AidlITestDemo> mAidlITestDemo;
    mAidlITestDemo = AidlITestDemo::fromBinder(
            ndk::SpAIBinder(AServiceManager_waitForService(service_name.c_str())));
    if (!mAidlITestDemo) {
        fprintf(stderr, "Failed to get AIDL test demo service");
        return -1;
    }

    const auto status1 = mAidlITestDemo->setActiveConfig(99);
    if (!status1.isOk()) {
        fprintf(stderr, "getActiveConfig failed %s \n", status1.getDescription().c_str());
    }

    int config = 0;
    const auto status2 = mAidlITestDemo->getActiveConfig(&config);
    if (!status2.isOk()) {
        fprintf(stderr, "getActiveConfig failed %s \n", status2.getDescription().c_str());
    } else {
        fprintf(stderr, "getActiveConfig success %d \n", config);
    }

    getchar();

    return 0;
}
