#include "utils/logger.h"
#include <coreinit/filesystem.h>
#include <malloc.h>
#include <wups.h>
#include <thread>
#include <memory>
#include <coreinit/thread.h>
#include <coreinit/cache.h>
#include <coreinit/debug.h>
#include <coreinit/memexpheap.h>
#include <coreinit/dynload.h>
#include <string.h>
#include <whb/log.h>

WUPS_PLUGIN_NAME("Alchemy Metadata Dumper");
WUPS_PLUGIN_DESCRIPTION("Dumps igMetaObject information in a format compatible with igCauldron");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("Jasleen, hydos");
WUPS_PLUGIN_LICENSE("GPLv3");
constexpr uint32_t PRINT_META_OBJECTS = VPAD_BUTTON_PLUS;
constexpr char* RPX_NAME = "nova-cafe-fin.rpx";

WUPS_USE_WUT_DEVOPTAB();
WUPS_USE_STORAGE("alchemy_dumper_plugin_id");

OSDynLoad_NotifyData* getAlchemyGameRpx() {
    int num_rpls = OSDynLoad_GetNumberOfRPLs();
    if (num_rpls == 0) {
        WHBLogPrintf("OSDynLoad_GetNumberOfRPLs failed.");
        return nullptr;
    }

    std::vector<OSDynLoad_NotifyData> rpls;
    rpls.resize(num_rpls);

    bool ret = OSDynLoad_GetRPLInfo(0, num_rpls, rpls.data());
    if (!ret) {
        WHBLogPrintf("OSDynLoad_GetRPLInfo failed.");
        return nullptr;
    }
    
    for (auto &rpl : rpls) {
        if (std::string_view(rpl.name).ends_with(RPX_NAME)) {
            return &rpl;
        }
    }

    WHBLogPrintf("Failed to find alchemy game rpx :(");
    return nullptr;
}

void* fixGhidraAddress(OSDynLoad_NotifyData* rpx, void* ptr) {
    // Cast dataAddr and ptr to uintptr_t for pointer arithmetic
    uintptr_t baseAddr = reinterpret_cast<uintptr_t>(rpx->dataAddr);
    uintptr_t offsetPtr = reinterpret_cast<uintptr_t>(ptr);

    // Subtract 0x10000000 and calculate the new address
    uintptr_t fixedAddr = baseAddr + (offsetPtr - 0x10000000);

    // Return the fixed address as a void*
    return reinterpret_cast<void*>(fixedAddr);
}

int dump() {
    WHBLogPrintf("Alchemy Metadata start");
    auto alchemyRpx = getAlchemyGameRpx();
    

    return 0;
}
/**
    Gets called ONCE when the plugin was loaded.
**/
INITIALIZE_PLUGIN() {
    initLogging();
    WHBLogPrintf("vv_alchemy_meta_dumper init");
}

/**
    Gets called when the plugin will be unloaded.
**/
DEINITIALIZE_PLUGIN() {}

/**
    Gets called when an application starts.
**/
ON_APPLICATION_START() {
    // bad plugin api :(
    initLogging();
}

/**
 * Gets called when an application actually ends
 */
ON_APPLICATION_ENDS() {}

/**
    Gets called when an application request to exit.
**/
ON_APPLICATION_REQUESTS_EXIT() {}

bool CheckForButtonCombo(uint32_t trigger, uint32_t hold) {
    if (trigger == PRINT_META_OBJECTS) {
        WHBLogPrintf("Alchemy Meta Object Dump key pressed.");
        dump();
        return true;
    } else {
    }
    return false;
}

DECL_FUNCTION(int32_t, VPADRead, VPADChan chan,
              VPADStatus *buffers,
              uint32_t count,
              VPADReadError *outError) {
    VPADReadError real_error;
    auto result = real_VPADRead(chan, buffers, count, &real_error);

    if (result > 0 && real_error == VPAD_READ_SUCCESS) {
        uint32_t end = 1;
        // Fix games like TP HD
        if (VPADGetButtonProcMode(chan) == 1) {
            end = result;
        }
        for (uint32_t i = 0; i < end; i++) {
            if (CheckForButtonCombo((buffers[i].trigger), (buffers[i].hold))) {
                break;
            }
        }
    }
    if (outError) {
        *outError = real_error;
    }
    return result;
}

WUPS_MUST_REPLACE_FOR_PROCESS(VPADRead, WUPS_LOADER_LIBRARY_VPAD, VPADRead, WUPS_FP_TARGET_PROCESS_ALL);
