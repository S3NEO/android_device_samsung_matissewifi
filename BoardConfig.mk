# Copyright (C) 2014-2016 The CyanogenMod Project
# Copyright (C) 2017-2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common matisse
include device/samsung/matisse-common/BoardConfigCommon.mk

DEVICE_PATH := device/samsung/matissewifi

# Assert
TARGET_OTA_ASSERT_DEVICE := matisse,matissewifi,matissewifiue

# Kernel
TARGET_KERNEL_CONFIG := lineage_matissewifi_defconfig

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# SELinux
include $(DEVICE_PATH)/sepolicy/sepolicy.mk

# inherit from the proprietary version
-include vendor/samsung/matissewifi/BoardConfigVendor.mk
