/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2018, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_msm8226.h"

using android::base::GetProperty;
using android::init::property_set;

void gsm_properties()
{
    property_set("ro.telephony.default_network", "3");
    property_set("telephony.lteOnGsmDevice", "0");
}

void init_target_properties()
{
    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("I9301I") == 0) {
        /* s3ve3gds */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/s3ve3gds/s3ve3g:4.4.2/KOT49H/I9301IXXUANL1:user/release-keys");
        property_override("ro.build.description", "s3ve3gds-user 4.4.2 KOT49H I9301IXXUANL1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "GT-I9301I");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "s3ve3g");
        gsm_properties();
    } else if (bootloader.find("I9301Q") == 0) {
        /* s3ve3gjv */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/s3ve3gjv/s3ve3g:4.4.2/KOT49H/I9301QXXUANH1:user/release-keys");
        property_override("ro.build.description", "samsung/s3ve3gjv/s3ve3g:4.4.2/KOT49H/I9301QXXUANH1:user/release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "GT-I9301Q");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "s3ve3gjv");
        gsm_properties();
    } else if (bootloader.find("I9300I") == 0) {
        /* s3ve3gdsds */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/s3ve3gdsxx/s3ve3gds:4.4.4/KTU84P/I9300IXWUBNJ1:user/release-keys");
        property_override("ro.build.description", "s3ve3gdsxx-user 4.4.4 KTU84P I9300IXWUBNJ1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "GT-I9300I");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "s3ve3gds");
        gsm_properties();
    } else {
        gsm_properties();
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
