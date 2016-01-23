#include <pebble.h>

Window *window;
TextLayer *text_layer;

void handle_init(void) {
    Layer *window_layer;
    GRect bounds;
    
	// Create a window and text layer
	window = window_create();
    window_set_background_color(window, GColorTiffanyBlue);
    
    window_layer = window_get_root_layer(window);
    bounds = layer_get_bounds(window_layer);
    
	text_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(58, 52), bounds.size.w, 50));
	
	// Set the text, font, and text alignment
	text_layer_set_text(text_layer, "100%");
	text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT));
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
    text_layer_set_background_color(text_layer, GColorClear);
    text_layer_set_text_color(text_layer, GColorBlack);

	
	// Add the text layer to the window
	layer_add_child(window_layer, text_layer_get_layer(text_layer));

	// Push the window
	window_stack_push(window, true);
	
	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

void handle_deinit(void) {
	// Destroy the text layer
	text_layer_destroy(text_layer);
	
	// Destroy the window
	window_destroy(window);
}

int main(void) {
	handle_init();
	app_event_loop();
	handle_deinit();
}
