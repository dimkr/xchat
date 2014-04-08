
struct text_event
{
	char *name;
	char **help;
	char *def;
	int num_args;
	char *sound;
};

void PrintText (session *sess, unsigned char *text);
void end_logging (int fd);
void setup_logging (session *sess);
void load_text_events (void);
void pevent_save (char *fn);
void printevent_setup (void);
int pevt_build_string (char *input, char **output, int *max_arg);
int text_event (int i);
int pevent_load (char *filename);
void pevent_make_pntevts (void);