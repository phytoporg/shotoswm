#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_surface.h>

// forward declarations
struct shotoswm_server;

enum shotoswm_cursor_mode 
{
	SHOTOSWM_CURSOR_PASSTHROUGH,
	SHOTOSWM_CURSOR_MOVE,
	SHOTOSWM_CURSOR_RESIZE,
};

void server_new_pointer(
    struct shotoswm_server *server,
    struct wlr_input_device *device);
void seat_request_cursor(
    struct wl_listener *listener,
    void *data);

void process_cursor_move(struct shotoswm_server *server, uint32_t time);
void process_cursor_motion(struct shotoswm_server *server, uint32_t time);
void process_cursor_resize(struct shotoswm_server *server, uint32_t time);

/* This iterates over all of our surfaces and attempts to find one under the
 * cursor. This relies on server->views being ordered from top-to-bottom. */
struct shotoswm_view *desktop_view_at(
		struct shotoswm_server *server, double lx, double ly,
		struct wlr_surface **surface, double *sx, double *sy);

void server_cursor_motion(struct wl_listener *listener, void *data);
void server_cursor_motion_absolute(struct wl_listener *listener, void *data);
void server_cursor_button(struct wl_listener *listener, void *data);
void server_cursor_axis(struct wl_listener *listener, void *data);
void server_cursor_frame(struct wl_listener *listener, void *data);

void begin_interactive(
    struct shotoswm_view *view,
    enum shotoswm_cursor_mode mode, uint32_t edges);
