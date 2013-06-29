// First uncomment the code for the layout you want to try out.
// gcc -Wall `pkg-config --libs --cflags gtk+-3.0` layout.c -o layout
#include <gtk/gtk.h>

/* HORIZONTAL/VERTICAL panes that can be resized layout */

// int main (int argc, char *argv[])
// {
//     GtkWidget *window, *hpanes, *vpanes, *buttons[3];
//     gtk_init (&argc, &argv);
//     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//     g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//     hpanes = gtk_hpaned_new ();
//     buttons[0] = gtk_button_new_with_label ("left");
//     buttons[1] = gtk_button_new_with_label ("right");
//     gtk_paned_add1 (GTK_PANED(hpanes), buttons[0]);
//     gtk_paned_add2 (GTK_PANED(hpanes), buttons[1]);
//
//     vpanes = gtk_vpaned_new ();
//     buttons[2] = gtk_button_new_with_label ("up");
//     gtk_paned_add1 (GTK_PANED(vpanes), buttons[2]);
//     gtk_paned_add2 (GTK_PANED(vpanes), hpanes);
//
//     gtk_container_add (GTK_CONTAINER(window), vpanes);
//     gtk_widget_show_all (window);
//     gtk_main ();
//     return 0;
// }

/* TABLE layout */

// static void change_homogenous (GtkWidget *widget, GtkTable *table)
// {
//     /* Homogenität ändern */
//     gtk_table_set_homogeneous (table, !gtk_table_get_homogeneous (table));
// }
//
// int main (int argc, char *argv[])
// {
//     GtkWidget *window, *table, *button, *labels[8];
//     gtk_init (&argc, &argv);
//     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//     g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//     table = gtk_table_new (3, 3, FALSE);
//
//     labels[0] = gtk_label_new ("cero");
//     labels[1] = gtk_label_new ("uno");
//     labels[2] = gtk_label_new ("dos");
//     labels[3] = gtk_label_new ("tres");
//     labels[4] = gtk_label_new ("cuatro");
//     labels[5] = gtk_label_new ("cinco");
//     labels[6] = gtk_label_new ("seis");
//     labels[7] = gtk_label_new ("siete");
//
//     button = gtk_button_new_with_label ("homegeneo");
//     g_signal_connect (button, "clicked", G_CALLBACK(change_homogenous), table);
//
//     /* first row (left, right, top, bottom) */
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[0], 0, 1, 0, 1);
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[1], 1, 2, 0, 1);
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[2], 2, 3, 0, 1);
//
//     /* second row */
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[3], 0, 1, 1, 2);
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[4], 1, 2, 1, 2);
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[5], 2, 3, 1, 2);
//
//     /* third row */
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[6], 0, 1, 2, 3);
//     gtk_table_attach_defaults (GTK_TABLE(table), labels[7], 1, 2, 2, 3);
//     gtk_table_attach_defaults (GTK_TABLE(table), button, 2, 3, 2, 3);
//
//     gtk_container_add (GTK_CONTAINER(window), table);
//     gtk_widget_show_all (window);
//     gtk_main ();
//     return 0;
// }

/* FREE layout */
// static void move_button (GtkWidget *button, GtkWidget *layout)
// {
//     gint x;
//     gtk_container_child_get (GTK_CONTAINER(layout), button, "x", &x, NULL);
//     x = x % 100 + 10;
//     gtk_layout_move (GTK_LAYOUT(layout), button, x, 50);
// }
//
// int main (int argc, char *argv[])
// {
//     GtkWidget *window, *layout, *button, *label;
//     gtk_init (&argc, &argv);
//     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//     g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//     layout = gtk_layout_new (NULL, NULL);
//
//     label = gtk_label_new ("Test");
//     button = gtk_button_new_with_label ("Click me!");
//
//     gtk_layout_put (GTK_LAYOUT(layout), label, 10, 10);
//     gtk_layout_put (GTK_LAYOUT(layout), button, 20, 100);
//     g_signal_connect (button, "clicked", G_CALLBACK(move_button), layout);
//
//     gtk_container_add (GTK_CONTAINER(window), layout);
//     gtk_widget_show_all (window);
//     gtk_main ();
//     return 0;
// }

/* Vertical/Horizontal box */

// int main (int argc, char *argv[])
// {
//     GtkWidget *window, *hbox, *vbox, *buttons[5];
//
//     gtk_init (&argc, &argv);
//     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//     g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//     vbox = gtk_vbox_new (FALSE, 0);
//
//     /* Obere Zeile */
//     buttons[0] = gtk_button_new_with_label ("Menü");
//     gtk_box_pack_start (GTK_BOX(vbox), buttons[0], FALSE, FALSE, 0);
//
//     /* Mittlerer Bereich */
//     hbox = gtk_hbox_new (TRUE, 0);
//     buttons[1] = gtk_button_new_with_label ("TRUE, TRUE");
//     gtk_box_pack_start (GTK_BOX(hbox), buttons[1], TRUE, TRUE, 0);
//     buttons[2] = gtk_button_new_with_label ("FALSE, FALSE");
//     gtk_box_pack_start (GTK_BOX(hbox), buttons[2], FALSE, FALSE, 0);
//     buttons[3] = gtk_button_new_with_label ("TRUE, TRUE");
//     gtk_box_pack_start (GTK_BOX(hbox), buttons[3], TRUE, TRUE, 0);
//     gtk_box_pack_start (GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
//
//     /* Untere Zeile */
//     buttons[4] = gtk_button_new_with_label ("Status");
//     gtk_box_pack_start (GTK_BOX(vbox), buttons[4], FALSE, FALSE, 0);
//
//     gtk_container_add (GTK_CONTAINER(window), vbox);
//     gtk_widget_show_all (window);
//     gtk_main ();
//     return 0;
// }

