/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "TestDemo"

#include "TestDemo.h"
#include <log/log.h>

namespace aidl {
namespace roger {
namespace test {
namespace demo {

::ndk::ScopedAStatus TestDemo::setActiveConfig(int32_t in_config) {
    ALOGD("%s[%d]: in_config=%d", __FUNCTION__, __LINE__, in_config);
    
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus TestDemo::getActiveConfig(int32_t* _aidl_return) {
    ALOGD("%s[%d]", __FUNCTION__, __LINE__);
    *_aidl_return = 88;

    return ndk::ScopedAStatus::ok();
}

}  // namespace demo
}  // namespace test
}  // namespace roger
}  // namespace aidl

