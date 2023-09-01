#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <sched.h>

#include "Foo.h"

using my::test::Foo;

int main(int /*argc*/, char** /*argv*/) {
    ALOGI("Test Foo starting up...");

    android::ProcessState::initWithDriver("/dev/vndbinder");

    // register service
    android::sp<Foo> foo = new Foo();

    const android::String16 service_name = Foo::descriptor;
    auto status = android::defaultServiceManager()->addService(service_name, foo);
    CHECK(status == android::OK);

    android::ProcessState::self()->startThreadPool();
    android::IPCThreadState::self()->joinThreadPool();;

    return EXIT_FAILURE;
}