#include <pebble.h>

Window *window;
BitmapLayer *mask_layer;
TextLayer *text_layer;

void handle_init(void) {
    Layer *window_layer;
    GRect bounds;
    int calc;
    
	// Create a window
	window = window_create();
    window_set_background_color(window, GColorCobaltBlue);
    window_layer = window_get_root_layer(window);
    bounds = layer_get_bounds(window_layer);
    
    // Set up mask layer
    calc = (bounds.size.h * 27) / bounds.size.h;
    mask_layer = bitmap_layer_create(GRect(0, 0, bounds.size.w, calc));
    bitmap_layer_set_background_color(mask_layer, GColorBlack);
    
    // Set the text, font, and text alignment
	text_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(58, 52), bounds.size.w, 50));
	text_layer_set_text(text_layer, "100%");
	text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT));
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
    text_layer_set_background_color(text_layer, GColorClear);
    text_layer_set_text_color(text_layer, GColorWhite);
	
	// Add the mask and text layer to the window
    layer_add_child(window_layer, bitmap_layer_get_layer(mask_layer));
	layer_add_child(window_layer, text_layer_get_layer(text_layer));

	// Push the window
	window_stack_push(window, true);
	
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

void handle_deinit(void) {
	text_layer_destroy(text_layer);
    bitmap_layer_destroy(mask_layer);
	window_destroy(window);
}

// Main app loop
int main(void) {
	handle_init();
	app_event_loop();
	handle_deinit();
}
