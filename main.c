#include "eadk.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Image Viewer";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

extern const char* eadk_external_data;
extern size_t eadk_external_data_size;

#define EADK_COLOR(r, g, b) ((eadk_color_t)(((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)))

eadk_color_t palette[] = {
    EADK_COLOR(63, 67, 40),
    EADK_COLOR(95, 113, 50),
    EADK_COLOR(148, 173, 57),
    EADK_COLOR(194, 214, 79),
    EADK_COLOR(239, 243, 124),
    EADK_COLOR(227, 230, 172),
    EADK_COLOR(165, 198, 124),
    EADK_COLOR(115, 154, 112),
    EADK_COLOR(77, 102, 89),
    EADK_COLOR(52, 63, 65),
    EADK_COLOR(40, 46, 59),
    EADK_COLOR(26, 31, 46),
    EADK_COLOR(30, 49, 75),
    EADK_COLOR(47, 76, 108),
    EADK_COLOR(61, 128, 163),
    EADK_COLOR(99, 196, 204),
    EADK_COLOR(154, 229, 213),
    EADK_COLOR(229, 239, 239),
    EADK_COLOR(186, 201, 205),
    EADK_COLOR(141, 153, 164),
    EADK_COLOR(105, 111, 128),
    EADK_COLOR(65, 68, 83),
    EADK_COLOR(184, 161, 194),
    EADK_COLOR(126, 101, 155),
    EADK_COLOR(92, 58, 111),
    EADK_COLOR(57, 39, 94),
    EADK_COLOR(47, 25, 62),
    EADK_COLOR(78, 26, 73),
    EADK_COLOR(123, 35, 76),
    EADK_COLOR(178, 54, 87),
    EADK_COLOR(209, 105, 116),
    EADK_COLOR(237, 170, 163),
    EADK_COLOR(238, 203, 144),
    EADK_COLOR(225, 168, 69),
    EADK_COLOR(197, 120, 53),
    EADK_COLOR(141, 72, 48),
    EADK_COLOR(228, 114, 89),
    EADK_COLOR(195, 60, 64),
    EADK_COLOR(141, 54, 73),
    EADK_COLOR(92, 43, 52),
    EADK_COLOR(60, 37, 43),
    EADK_COLOR(104, 64, 57),
    EADK_COLOR(130, 86, 70),
    EADK_COLOR(183, 120, 98),
    EADK_COLOR(125, 89, 93),
    EADK_COLOR(83, 59, 65),
    EADK_COLOR(63, 51, 59),
    EADK_COLOR(43, 34, 42), 
    EADK_COLOR(109, 78, 75),
    EADK_COLOR(134, 112, 102),
    EADK_COLOR(180, 157, 126),
    EADK_COLOR(196, 198, 184)
};


void decode_and_draw_image(const char *code) {
    int x = 0, y = 0;
    while (*code) {
        if (y >= EADK_SCREEN_HEIGHT) {
            break;
        }
        char c = *code++;
        int count = 0;
        while (*code >= '0' && *code <= '9') {
            count = count * 10 + (*code++ - '0');
        }
        if (count == 0) {
            count = 1;
        }
        eadk_color_t color;
        if (c >= 'A' && c <= 'Z') {
            color = palette[c - 'A'];
        } else if (c >= 'a' && c <= 'z') {
            color = palette[c - 'a' + 26];
        }
        for (int i = 0; i < count; i++) {
            eadk_display_push_rect((eadk_rect_t){x, y, 1, 1}, &color);
            x++;
            if (x >= EADK_SCREEN_WIDTH) {
                x = 0;
                y++;
            }
        }
    }
}


int main() {
    decode_and_draw_image(eadk_external_data);

    eadk_keyboard_state_t state;
    do {
        state = eadk_keyboard_scan();
    } while (!eadk_keyboard_key_down(state, eadk_key_on_off) && !eadk_keyboard_key_down(state, eadk_key_back) && !eadk_keyboard_key_down(state, eadk_key_home));

    return 0;
}