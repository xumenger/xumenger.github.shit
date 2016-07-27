/* table.c */
#include <gtk/gtk.h>
void callback1(GtkWidget *widget, gpointer data )		
{
  g_print ("Button 1 clicked\n");
}
void callback2(GtkWidget *widget, gpointer data )
{
  g_print ("Button 2 clicked\n");
}
gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  g_print ("delete event occurred\n");
  gtk_main_quit();
  return FALSE;
}
int main(int argc, char **argv) 						
{
  GtkWidget *window; 
  GtkWidget *table;
  GtkWidget *button;
  gtk_init(&argc, &argv); 						
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 	
  gtk_signal_connect(GTK_OBJECT(window), "delete_event",
      GTK_SIGNAL_FUNC(delete_event), NULL);
  gtk_container_set_border_width(GTK_CONTAINER (window), 15);	
  table = gtk_table_new(2, 2, TRUE);
  gtk_container_add (GTK_CONTAINER (window), table);	
  button = gtk_button_new_with_label("Button 1");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(callback1), NULL);
  gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 1, 0, 1); 
  gtk_widget_show (button);			
  button = gtk_button_new_with_label("Button 2");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(callback2), NULL);
  gtk_table_attach_defaults (GTK_TABLE (table), button, 1, 2, 0, 1);
  gtk_widget_show (button);
  button = gtk_button_new_with_label("Exit");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(delete_event), NULL);
  gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 2, 1, 2);
  gtk_widget_show (button);
  gtk_widget_show (table);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
