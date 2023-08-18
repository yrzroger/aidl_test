/*
 * Copyright 2022, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <binder/ProcessState.h>
#include <sched.h>

#include "TestDemo.h"

using aidl::roger::test::demo::TestDemo;

int main(int /*argc*/, char** /*argv*/) {
    ALOGI("Roger TestDemo starting up...");

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    // register TestDemo service
    auto test_demo = ndk::SharedRefBase::make<TestDemo>();
    const std::string service_name = 
        std::string() + TestDemo::descriptor + "/default";
    binder_status_t status =
        AServiceManager_addService(test_demo->asBinder().get(), service_name.c_str());
    CHECK(status == STATUS_OK);

    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE; // should not reached
}