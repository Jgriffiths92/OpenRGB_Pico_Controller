#ifndef TUSB_CONFIG_H
#define TUSB_CONFIG_H

#define CFG_TUSB_MCU OPT_MCU_RP2040
#define CFG_TUSB_RHPORT0_MODE OPT_MODE_DEVICE | OPT_MODE_FULL_SPEED
#define CFG_TUD_ENDPOINT0_SIZE 64

// Enable CDC (USB Serial)
#define CFG_TUD_CDC 1

// USB Device Descriptor
#define USB_VID 0x1209 // pid.codes community VID (for open hardware projects)
#define USB_PID 0x0001 // Custom PID
#define USB_BCD 0x0100
#define USB_MANUFACTURER    "Jgriffiths92"
#define USB_PRODUCT         "Pico RGB Controller"
#define USB_SERIAL          "0001"

#endif // TUSB_CONFIG_H
