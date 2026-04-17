#include "openrgb_protocol.h"
#include "tusb.h"


static set_all_rgb_callback_t rgb_cb = 0;

void openrgb_init(set_all_rgb_callback_t cb) {
    rgb_cb = cb;
    tusb_init();
}

void openrgb_task() {
    tud_task();
    // Receive 12 bytes for 4 RGB ports
    if (tud_cdc_available()) {
        uint8_t buf[64];
        uint32_t count = tud_cdc_read(buf, sizeof(buf));
        if (count >= 12 && rgb_cb) {
            rgb_cb(buf); // Pass first 12 bytes
        }
    }
}
