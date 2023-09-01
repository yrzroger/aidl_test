#pragma once

#include <my/test/BnFoo.h>

namespace my {
namespace test {

class Foo : public BnFoo {
public:
    ::android::binder::Status setFoo(int32_t x) override;
    ::android::binder::Status getFoo(int32_t* _aidl_return) override;

private:
};

}  // namespace test
}  // namespace my
