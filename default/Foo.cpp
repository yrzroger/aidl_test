#define LOG_TAG "TestFoo"

#include "Foo.h"
#include <log/log.h>

namespace my {
namespace test {

::android::binder::Status Foo::setFoo(int32_t x) {
    ALOGD("call setFoo, x=%d", x);
    return ::android::binder::Status::ok();
}

::android::binder::Status Foo::getFoo(int32_t* _aidl_return) {
    ALOGD("call getFoo, return 88");
    *_aidl_return = 88;
    return ::android::binder::Status::ok();
}

}  // namespace test
}  // namespace my