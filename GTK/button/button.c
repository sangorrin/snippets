//  gcc -Wall -g `pkg-config --libs --cflags gtk+-3.0` button.c -o button
#include <gtk/gtk.h>

static void on_window_closed (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

static void on_button_clicked (GtkWidget *widget, gpointer data)
{
    static int click_count;
    gtk_button_set_label (GTK_BUTTON(widget), (click_count % 2 == 0) ? "Even" : "Odd");
    click_count++;
}

int main (int argc, char *argv[])
{
    GtkWidget *window, *button;

    /* Initialization */
    gtk_init (&argc, &argv);
    /* Create a new top-level window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    /* Connect callback for the destroy event */
    g_signal_connect (window, "destroy", G_CALLBACK(on_window_closed), NULL);
    /* Create a button */
    button = gtk_button_new_with_label ("Click me!");
    /* Connect signal to callback */
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    /* Add the label to the window */
    gtk_container_add (GTK_CONTAINER(window), button);
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
