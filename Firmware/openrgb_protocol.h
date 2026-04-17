#ifndef OPENRGB_PROTOCOL_H
#define OPENRGB_PROTOCOL_H
#include <stdint.h>


typedef void (*set_all_rgb_callback_t)(const uint8_t rgb[12]);

void openrgb_init(set_all_rgb_callback_t cb);
void openrgb_task();

#endif // OPENRGB_PROTOCOL_H
