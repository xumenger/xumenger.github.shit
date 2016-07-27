#include<gtk/gtk.h>

int main(int argc, char **argv)
{
	GtkWidget *window;
	char title[] = "fuck";
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_widget_set_usize(window, 400, 200);
	gtk_widget_set_uposition(window, 200 ,200);
	gtk_widget_show(window);
	gtk_main();

	return 0;
}
