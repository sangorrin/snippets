//  gcc -Wall -g `pkg-config --libs --cflags gtk+-3.0` label.c -o label
#include <gtk/gtk.h>

static void on_window_closed (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{
    GtkWidget *window, *label;

    /* Initialization */
    gtk_init (&argc, &argv);
    /* Create a new top-level window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    /* Connect callback for the destroy event */
    g_signal_connect (window, "destroy", G_CALLBACK(on_window_closed), NULL);
    /* Create a label */
    label = gtk_label_new (NULL);
    /* Set the text of the label with a markup language */
    gtk_label_set_markup (GTK_LABEL(label),
            "<small>Small</small>\n"
            "<big>Big</big>\n"
            "<b>Bold</b>\n"
            "<span foreground=\"#ff0000\">Foreground Color</span>");
    /* Add the label to the window */
    gtk_container_add (GTK_CONTAINER(window), label);
    /* Set the title of the window */
    gtk_window_set_title (GTK_WINDOW(window), "Dibujar 1.0");
    /* Set the default size of the window (dependsd on window manager) */
    gtk_window_set_default_size (GTK_WINDOW(window), 640, 480);
    /* Show the label and the window */
    gtk_widget_show_all (window);
    /* Got to the main loop */
    gtk_main ();

    return 0;
}
