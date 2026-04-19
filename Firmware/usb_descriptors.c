#include "tusb.h"
#include "tusb_config.h"

#define USB_PRODUCT_STRING USB_PRODUCT
#define USB_MANUFACTURER_STRING USB_MANUFACTURER
#define USB_SERIAL_STRING USB_SERIAL

// Device Descriptor
const tusb_desc_device_t desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = USB_VID,
    .idProduct          = USB_PID,
    .bcdDevice          = USB_BCD,
    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,
    .bNumConfigurations = 0x01
};

// String Descriptors
const char *string_desc_arr[] = {
    (const char[]){0x09, 0x04}, // 0: English (0x0409)
    USB_MANUFACTURER_STRING,    // 1: Manufacturer
    USB_PRODUCT_STRING,         // 2: Product
    USB_SERIAL_STRING           // 3: Serial
};

uint16_t _desc_str[32];

// Minimal configuration descriptor for CDC (update for your needs)
static const uint8_t desc_configuration[] = {
    // Configuration Descriptor
    0x09, 0x02, 0x20, 0x00, // bLength, bDescriptorType, wTotalLength (32 bytes)
    0x01, 0x01, 0x00, 0x80, 0x32, // bNumInterfaces, bConfigurationValue, iConfiguration, bmAttributes, bMaxPower
    // Interface Descriptor (CDC Control)
    0x09, 0x04, 0x00, 0x00, 0x01, 0x02, 0x02, 0x01, 0x00,
    // CDC Header Functional Descriptor
    0x05, 0x24, 0x00, 0x10, 0x01,
    // CDC ACM Functional Descriptor
    0x04, 0x24, 0x02, 0x02,
    // CDC Union Functional Descriptor
    0x05, 0x24, 0x06, 0x00, 0x01,
    // Endpoint Descriptor (Interrupt IN)
    0x07, 0x05, 0x81, 0x03, 0x08, 0x00, 0x10
    // (This is a minimal example, add more for full CDC-ACM)
};

// TinyUSB callback to return configuration descriptor
uint8_t const * tud_descriptor_configuration_cb(uint8_t index) {
    (void)index;
    return desc_configuration;
}

// Invoked when GET DEVICE DESCRIPTOR request
uint8_t const * tud_descriptor_device_cb(void) {
    return (uint8_t const *) &desc_device;
}

// Invoked when GET STRING DESCRIPTOR request
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    uint8_t chr_count;
    if (index == 0) {
        _desc_str[1] = 0x0409;
        chr_count = 1;
    } else {
        if (!(index < sizeof(string_desc_arr)/sizeof(string_desc_arr[0]))) return NULL;
        const char* str = string_desc_arr[index];
        chr_count = strlen(str);
        if (chr_count > 31) chr_count = 31;
        for (uint8_t i = 0; i < chr_count; i++) {
            _desc_str[1 + i] = str[i];
        }
    }
    _desc_str[0] = (TUSB_DESC_STRING << 8 ) | (2*chr_count + 2);
    return _desc_str;
}
