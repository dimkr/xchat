#include "userlist.h"
#include "dcc.h"

int fe_args (int argc, char *argv[]);
void fe_init (void);
void fe_main (void);
void fe_cleanup (void);
void fe_exit (void);
int fe_timeout_add (int interval, void *callback, void *userdata);
void fe_timeout_remove (int tag);
void fe_new_window (struct session *sess);
void fe_new_server (struct server *serv);
void fe_add_rawlog (struct server *serv, char *text, int len, int outbound);
void fe_message (char *msg, int wait);
int fe_input_add (int sok, int read, int write, int ex, void *func,
						void *data);
void fe_input_remove (int tag);
void fe_set_topic (struct session *sess, char *topic);
void fe_set_hilight (struct session *sess);
void fe_update_mode_buttons (struct session *sess, char mode, char sign);
void fe_update_channel_key (struct session *sess);
void fe_update_channel_limit (struct session *sess);
int fe_is_chanwindow (struct server *serv);
void fe_add_chan_list (struct server *serv, char *chan, char *users,
							  char *topic);
void fe_chan_list_end (struct server *serv);
int fe_is_banwindow (struct session *sess);
void fe_add_ban_list (struct session *sess, char *mask, char *who, char *when);
void fe_ban_list_end (struct session *sess);
void fe_notify_update (char *name);
void fe_text_clear (struct session *sess);
void fe_close_window (struct session *sess);
void fe_progressbar_start (struct session *sess);
void fe_progressbar_end (struct session *sess);
void fe_print_text (struct session *sess, char *text);
void fe_userlist_insert (struct session *sess, struct User *newuser, int row);
void fe_userlist_remove (struct session *sess, struct User *user);
void fe_userlist_move (struct session *sess, struct User *user, int new_row);
void fe_userlist_numbers (struct session *sess);
void fe_userlist_clear (struct session *sess);
void fe_dcc_update_recv_win (void);
void fe_dcc_update_send_win (void);
void fe_dcc_update_chat_win (void);
void fe_dcc_update_send (struct DCC *dcc);
void fe_dcc_update_recv (struct DCC *dcc);
void fe_dcc_open_recv_win (int passive);
void fe_dcc_open_send_win (int passive);
void fe_dcc_open_chat_win (int passive);
void fe_clear_channel (struct session *sess);
void fe_session_callback (struct session *sess);
void fe_server_callback (struct server *serv);
void fe_checkurl (char *text);
void fe_pluginlist_update (void);
void fe_buttons_update (struct session *sess);
void fe_dlgbuttons_update (struct session *sess);
void fe_dcc_send_filereq (struct session *sess, char *nick);
void fe_set_channel (struct session *sess);
void fe_set_title (struct session *sess);
void fe_set_nonchannel (struct session *sess, int state);
void fe_set_nick (struct server *serv, char *newnick);
void fe_change_nick (struct server *serv, char *nick, char *newnick);
void fe_ignore_update (int level);
void fe_beep (void);
int fe_is_confmode (struct session *);
int fe_is_beep (struct session *);
void fe_lastlog (session *sess, session *lastlog_sess, char *sstr);
void fe_set_lag (server *serv, int lag);
void fe_set_throttle (server *serv);
void fe_set_away (server *serv);
int fe_open_serverlist (session *sess, int auto_connect, int dont_show);
