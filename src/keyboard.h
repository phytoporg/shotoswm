#include <wayland-server-core.h>
#include <wayland-util.h>
#include <wlr/types/wlr_keyboard.h>

struct shotoswm_keyboard {
	struct wl_list link;
	struct shotoswm_server *server;
	struct wlr_input_device *device;

	struct wl_listener modifiers;
	struct wl_listener key;
};

void keyboard_handle_modifiers(struct wl_listener *listener, void *data);
bool handle_keybinding(struct shotoswm_server *server, xkb_keysym_t sym);
void keyboard_handle_key(struct wl_listener *listener, void *data);

void server_new_keyboard(
    struct shotoswm_server *server,
    struct wlr_input_device *device);
